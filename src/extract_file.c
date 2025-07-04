/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:19:49 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/03 22:06:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_file	*create_t_file(char *str)
{
	t_file	*file;
	char	*file_name;

	if (!str || !*str)
	{
		ft_putstr_fd("null file name\n", 2);
		return (NULL);
	}
	file_name = ft_strdup(str);
	if (!file_name)
	{
		ft_putstr_fd("Allocation Error at file_name duplication\n", 2);
		return (NULL);
	}
	file = ft_calloc(1, sizeof(t_file));
	if (!file)
	{
		ft_putstr_fd("Allocation Error at t_file creation\n", 2);
		free(file_name);
		return (NULL);
	}
	file->name = file_name;
	return (file);
}

static int	has_heredoc(char **argv, t_cmd_chain *chain)
{
	char	*limiter;

	if (ft_strncmp(argv[1], "here_doc", 8))
		return (0);
	chain->has_heredoc = 1;
	if (!argv[2] || !*argv[2])
	{
		ft_putstr_fd("empty limiter\n", 2);
		return (-1);
	}
	limiter = ft_strdup(argv[2]);
	if (!limiter)
	{
		ft_putstr_fd("Allocation Error at limiter\n", 2);
		return (-1);
	}
	chain->limiter = limiter;
	return (0);
}

int	extract_file(int argc, char **argv, t_cmd_chain *chain)
{
	t_file	*file_in;
	t_file	*file_out;

	file_in = create_t_file(argv[1]);
	if (!file_in)
		return (-1);
	chain->file_in = file_in;
	file_out = create_t_file(argv[argc - 1]);
	if (!file_out)
	{
		clear_files(file_in, NULL);
		return (-1);
	}
	chain->file_out = file_out;
	if (has_heredoc(argv, chain))
	{
		clear_files(file_in, file_out);
		return (-1);
	}
	return (0);
}
