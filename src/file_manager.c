/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:09:44 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/13 18:12:36 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(t_file *file, int flags)
{
	int	fd;

	fd = open(file->name, flags);
	if (fd == -1)
	{
		ft_putstr_fd("could not open file\n", 2);
		return (-1);
	}
	file->fd = fd;
	return (0);
}

static size_t	limiter_lenght(char *str)
{
	if (!*str)
		return (1);
	return (ft_strlen(str));
}

char	*read_file_ulimit(int fd, char *limiter)
{
	char	*s1;
	char	*s2;
	char	*result;

	if (!limiter)
		limiter = "";
	s2 = get_next_line(fd);
	if (!s2 || !ft_strncmp(s2, limiter, limiter_lenght(limiter)))
		return (NULL);
	result = ft_strjoin("", s2);
	s1 = result;
	while (s2 && ft_strncmp(s2, limiter, limiter_lenght(limiter)))
	{
		free(s2);
		s2 = get_next_line(fd);
		if (s2 && ft_strncmp(s2, limiter, limiter_lenght(limiter)))
		{
			result = ft_strjoin(s1, s2);
			free(s1);
			s1 = result;
		}
	}
	free(s2);
	return (result);
}

void	close_files(t_file *file_in, t_file *file_out, int has_heredoc)
{
	if (file_in)
	{
		if (close(file_in->fd) == -1)
			ft_putstr_fd("Error on close the file_in\n", 2);
		if (has_heredoc)
			delete_heredoc(file_in);
	}
	if (file_out)
	{
		if (close(file_out->fd) == -1)
			ft_putstr_fd("Error on close the file_out\n", 2);
	}
}
