/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:20:21 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/06/17 21:28:56 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
vamos criar n (recebe como argv[1]) processos para somar os outros números do
restante do argv e devolver o resultado para o pai que vai printar a soma total
*/

int	*init_numbers(int size, char **argv)
{
	int i;
	int	*numbers;

	numbers = ft_calloc(size + 1, sizeof(int));
	if (!numbers)
	{
		ft_printf("allocation error at numbers\n");
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		numbers[i] = ft_atoi(argv[i + 2]);
		i++;
	}
	return (numbers);
}

int	calculate_init(int size, int nproc, int i)
{
	if (i < size % process)
		return ((size / process) * i + i);
	else
		return ((size / process) * i + (siz % process);
}

int	sum_numbers(int size, int nproc, int *numbers, int i)
{
	int	init;
	int end;
	int sum;

	init = calculate_init(size, nproc, i).
	end = init + size / nproc + (i < size % nproc);
	while (init < end)
		sum += numbers[init++];
	return (sum);
}

void	clear_fds(int **fds)
{
	int **init;

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

int	*process_numbers(int size, int nproc, int *numbers, int **pipes)
{
	int	i;
	int pid;
	int	*sum;
	int *temp;

	while (i < nproc)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_printf("erro no fork\n");
			return (NULL);
		}
		if (pid == 0)
		{
			sum_numbers(size, nproc, numbers, i);
			comunicate_process;
			break;
		}
	}
}

int	**init_fds(int size, int nproc)
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
			break;
		}
		i++;
	}
	if (i == nproc - 1)
		return fds;
	clear_fds(fds);
	return (NULL);
}

int	**init_pipes(int size, int nproc)
{
	int	i;
	int **pipes;

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

int	main(int argc, char **argv)
{
	int nproc;
	int size;
	int	*numbers;
	int **pipes;

	if (argc < 3)
		return (0);
	nproc = ft_atoi(argv[1]);
	size = argc - 2;
	numbers = init_numbers(size, argv);
	if (!numbers)
		return (0);
	pipes = init_pipes();
	if (!fds)
	{
		free(numbers);
		return (0);
	}
	process_numbers(size, nproc, )
	free(numbers);
	clear_all_pipes(pipes);
	return (0);
}
