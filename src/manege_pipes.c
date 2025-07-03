/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manege_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:21:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/02 21:28:11 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	clear_fds(int **fds)
{
	int	**init;

	init = fds;
	if (!fds || !*fds)
		return ;
	while (*fds)
		free(*fds++);
	free(init);
}

void	close_all_pipes(int **pipes)
{
	int	i;

	if (!pipes || !*pipes)
		return (NULL);
	i = 0;
	while (pipes[i])
	{
		close(pipes[i][0]);
		close(pipes[i++][0]);
	}
	clear_fds(pipes);
}

static int	**init_fds(int size, int nproc)
{
	int	i;
	int	**fds;

	fds = ft_calloc(n_proc + 1, sizeof(int *));
	if (!fds)
	{
		ft_printf("allocation error at fds\n");
		return (NULL);
	}
	i = 0;
	while (i < nproc)
	{
		fds[i] = ft_calloc(2, sizeof(int));
		if (!fd[i])
		{
			ft_printf("Allocation error at fds\n");
			break ;
		}
		i++;
	}
	if (i == nproc - 1)
		return (fds);
	clear_fds(fds);
	return (NULL);
}

int	**init_pipes(int size, int nproc)
{
	int	i;
	int	**pipes;

	pipes = init_fds(size, nproc);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < nproc)
	{
		if (pipe(pipes[i]) == -1)
		{
			ft_printf("pipe creation fail\n");
			close_all_pipes(pipes);
			return (NULL);
		}
	}
	return (pipes);
}
