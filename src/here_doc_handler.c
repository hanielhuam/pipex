/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:47:19 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/16 18:48:34 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	has_heredoc(char **argv, t_cmd_chain *chain)
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

static void	read_and_write_from_terminal(int fd, char *limiter)
{
	char	*content;

	content = get_next_line(STDIN_FILENO);
	while (ft_strncmp(content, limiter, ft_strlen(limiter)))
	{
		ft_putstr_fd(content, fd);
		free(content);
		content = get_next_line(STDIN_FILENO);
	}
	free(content);
}

static int	fill_heredoc(int fd, char *file_name, char *limiter)
{
	read_and_write_from_terminal(fd, limiter);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Error on close the here_doc after write\n", 2);
		return (-1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 2)
	{
		ft_putstr_fd("Error on reopen here_doc\n", 2);
		return (-1);
	}
	return (fd);
}

int	config_heredoc(t_cmd_chain *chain)
{
	int	fd;

	fd = open(chain->file_in->name, O_WRONLY | O_CREAT, 0644);
	if (fd < 2)
	{
		ft_putstr_fd("Error when create heredoc", 2);
		return (-1);
	}
	fd = fill_heredoc(fd, chain->file_in->name, chain->limiter);
	if (fd < 2)
		return (-1);
	chain->file_in->fd = fd;
	return (0);
}

void	delete_heredoc(t_file *file_in)
{
	if (file_in)
	{
		if (unlink(file_in->name) == -1)
			ft_putstr_fd("Error on delete heredoc file\n", 2);
	}
}
