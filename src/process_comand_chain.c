/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_comand_chain.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:08:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/14 22:23:29 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	wait_process(int i)
{
	while (i)
	{
		if (wait(NULL) == -1)
			ft_putstr_fd("Error while waiting process finish\n", 2);
		i--;
	}
}

static int	execute_comand(t_cmd_chain *chain, int i)
{
	t_list	*node;
	t_cmd	*cmd;

	if (dup2(chain->pipes[i][0], STDIN_FILENO) == -1 || \
			dup2(chain->pipes[i + 1][1], STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("Error when duping fd\n", 2);
		finish_program(chain);
		return (-1);
	}
	close_all_pipes(chain->pipes);
	node = *(chain->cmds);
	while (i)
	{
		node = node->next;
		i--;
	}
	cmd = (t_cmd *)node->content;
	execve(cmd->path, cmd->cmd_arg, chain->env);
	ft_putstr_fd("Error trying to execute program\n", 2);
	finish_program(chain);
	return (-1);
}

static int	execute_comand_chain(t_cmd_chain *chain)
{
	int	i;
	int	pid;

	i = 0;
	while (i < chain->sz_cmds)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_putstr_fd("Error when fork a process\n", 2);
			break ;
		}
		if (pid == 0)
		{
			if (execute_comand(chain, i))
				exit(EXIT_FAILURE);
		}
		i++;
	}
	close_pipes_unles(chain->pipes, chain->sz_cmds, -1);
	wait_process(i);
	return (0);
}

static void	read_and_write(int fd_in, int fd_out)
{
	char	*content;

	content = ft_read_file(fd_in);
	if (!content)
		content = ft_calloc(1, sizeof(char));
	ft_putstr_fd(content, fd_out);
	free(content);
}

void	process_comand_chain(t_cmd_chain *chain)
{
	if (!chain || init_pipes(chain))
		return ;
	read_and_write(chain->file_in->fd, chain->pipes[0][1]);
	execute_comand_chain(chain);
	read_and_write(chain->pipes[chain->sz_cmds][0], chain->file_out->fd);
	close(chain->pipes[chain->sz_cmds][0]);
	clear_fds(chain->pipes);
}
