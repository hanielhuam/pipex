/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_maneger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:21:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/15 20:20:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_fds(int **fds)
{
	int	**init;

	if (!fds)
		return ;
	init = fds;
	while (*fds)
		free(*fds++);
	free(init);
}

void	close_pipes_unles(int **pipes, int in, int out)
{
	int	i;

	if (!pipes)
		return ;
	i = 0;
	while (pipes[i])
	{
		if (pipes[i][0] > 2 && i != in)
			close(pipes[i][0]);
		if (pipes[i][1] > 2 && i != out)
			close(pipes[i][1]);
		i++;
	}
}

void	close_all_pipes(int **pipes)
{
	int	i;

	if (!pipes)
		return ;
	i = 0;
	while (pipes[i])
	{
		if (pipes[i][0] > 2)
			close(pipes[i][0]);
		if (pipes[i][1] > 2)
			close(pipes[i][1]);
		i++;
	}
	clear_fds(pipes);
}

static int	**init_fds(int size)
{
	int	i;
	int	**fds;

	fds = ft_calloc(size + 1, sizeof(int *));
	if (!fds)
	{
		ft_putstr_fd("allocation error at fds\n", 2);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		fds[i] = ft_calloc(2, sizeof(int));
		if (!fds[i++])
		{
			ft_putstr_fd("Allocation error at fds\n", 2);
			clear_fds(fds);
			return (NULL);
		}
	}
	return (fds);
}

int	init_pipes(t_cmd_chain *chain)
{
	int	i;
	int	**pipes;

	pipes = init_fds(chain->sz_cmds + 1);
	if (!pipes)
		return (-1);
	i = 0;
	while (i < chain->sz_cmds + 1)
	{
		if (pipe(pipes[i++]) == -1)
		{
			ft_putstr_fd("pipe creation fail\n", 2);
			close_all_pipes(pipes);
			return (-1);
		}
	}
	chain->pipes = pipes;
	return (0);
}
