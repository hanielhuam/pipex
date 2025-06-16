/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:20:21 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/06/13 19:01:13 by hmacedo-         ###   ########.fr       */
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
		return (NULL);
	i = 0;
	while (i < size)
	{
		numbers[i] = ft_atoi(argv[i + 2]);
		i++;
	}
	return (numbers);
}

int	main(int argc, char **argv)
{
	int	i;
	int nproc;
	int size;
	int	*numbers;
	int	pid;

	if (argc < 3)
		return (0);
	nproc = ft_atoi(argv[1]);

	size = argc - 2;
	numbers = init_numbers(size, argv);
	if (!numbers)
	{
		ft_printf("erro de alocação\n");
		return (0);
	}
	pid = 0;
	i = 0;
	while (i < nproc)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_printf("erro no fork\n");
			return (0);
		}
		if (pid == 0)
		{
			//child process
			// fazer a somatória dis size/
			break;
		}
	}
	free(numbers);
	return (0);
}
