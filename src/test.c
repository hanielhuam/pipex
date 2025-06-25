/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:20:21 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/06/18 21:52:50 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
vamos criar n (recebe como argv[1]) processos para somar os outros números do
restante do argv e devolver o resultado para o pai que vai printar a soma total


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

void	child_process(int size, int nproc, int *numbers, int **pipes, int i)
{
	int	sum;

	sum = sum_numbers(size, nproc, numbers, i);
	if (write(pipe[i][1], &sum, sizeof(int)) == -1)
		printf("error on write\n");
	free(numbers);
	close_all_pipes(pipes);
}

void	parent_process(int nproc, int **pipes)
{
	int	sum;
	int temp;

	sum = 0;
	temp = 0;
	while ()
}

int	*process_numbers(int size, int nproc, int *numbers, int **pipes)
{
	int	i;
	int pid;

	i = 0;
	pid = 0;
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
			break;
		}
	}
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
	pipes = init_pipes(size, nproc);
	if (!pipes)
	{
		free(numbers);
		return (0);
	}
	process_numbers(size, nproc, numbers, pipes)
	free(numbers);
	clear_all_pipes(pipes);
	return (0);
}*/
