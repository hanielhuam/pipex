/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:09:44 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/16 18:56:50 by hmacedo-         ###   ########.fr       */
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

int	open_file_mode(t_file *file, int flags, int mod)
{
	int	fd;

	fd = open(file->name, flags, mod);
	if (fd == -1)
	{
		ft_putstr_fd("could not open file\n", 2);
		return (-1);
	}
	file->fd = fd;
	return (0);
}

char	*ft_read_file(int fd)
{
	char	*s1;
	char	*s2;
	char	*result;

	s2 = get_next_line(fd);
	if (!s2)
		return (NULL);
	result = ft_strjoin("", s2);
	s1 = result;
	while (s2)
	{
		free(s2);
		s2 = get_next_line(fd);
		if (s2)
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
