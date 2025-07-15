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
/*	while (i)
	{
		ft_printf("dentro do while do wait\n");
		if (wait(NULL) == -1)
			ft_putstr_fd("Error while waiting process finish\n", 2);
		i--;
	}
	ft_printf("depois do wait\n");*/
	ft_printf("emcima do wait\n");
	waitpid(-1, NULL, 0);
	ft_printf("embaixo do wait\n");
	(void)i;
}

static int	execute_comand(t_cmd_chain *chain, int i)
{
	t_list	*node;
	t_cmd	*cmd;
	//char	*content;

	if (dup2(chain->pipes[i][0], STDIN_FILENO) == -1 || \
			dup2(chain->pipes[i + 1][1], STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("Error when duping fd\n", 2);
		finish_program(chain);
		return (-1);
	}
	close_all_pipes(chain->pipes);
	//content = read_file_ulimit(chain->pipes[i][0], NULL);
	/*content = ft_calloc(15, sizeof(char));
	read(chain->pipes[i][0], content, 15L);
	ft_putstr_fd(content, chain->pipes[i + 1][1]);
	finish_program(chain);
	exit(0);*/
	node = *(chain->cmds);
	while (i)
	{
		node = node->next;
		i--;
	}
	cmd = (t_cmd *)node->content;
	if (execve(cmd->path, cmd->cmd_arg, chain->env))
		ft_printf("deu merda!!!");
	exit(1);
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
	ft_printf("vamos ver se chega aqui\n");
	close_pipes_unles(chain->pipes, chain->sz_cmds, 0);
	wait_process(i);
	ft_printf("depois do wait\n");
	return (0);
}

void	process_comand_chain(t_cmd_chain *chain)
{
	char	reader[1024];
	char	*content;

	if (!chain || init_pipes(chain))
		return ;
	content = read_file_ulimit(chain->file_in->fd, chain->limiter);
	if (!content)
		content = ft_calloc(1, sizeof(char));
	//ft_putstr_fd(content, chain->pipes[0][1]);
	if (write(chain->pipes[0][1], content, ft_strlen(content)) == -1)
		ft_printf("Deu ruim");
	close(chain->pipes[0][1]);
	ft_printf("escrevi o conteúdo \"%s\" no primeiro pipe\n", content);
	free(content);
	if (execute_comand_chain(chain))
	{
		ft_printf("\n\n\noi\n\n\n");
		return ;
	}
	ft_printf("chegou aqui\n");
	read(chain->pipes[chain->sz_cmds][0], reader, 1024);
	//content = read_file_ulimit(chain->pipes[chain->sz_cmds][0], NULL);
	//if (!content)
	//	content = ft_calloc(1, sizeof(char));
	ft_printf("o que recebi dos processo = %s\n", reader);
	ft_putstr_fd(reader, chain->file_out->fd);
	close(chain->pipes[chain->sz_cmds][0]);
	clear_fds(chain->pipes);
	//free(content);
}
