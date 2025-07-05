/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:09:44 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/05 18:51:19 by hmacedo-         ###   ########.fr       */
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
