/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config_chain.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:03:27 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/04 22:09:15 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file_name, int flags)
{
	int	fd;

	fd = open(file_name, flags);
	if (fd == -1)
}

static int	check_config_file(t_file *file_in, t_file *file_out, int heredoc)
{
	int	flag_in;
	int	flag_out;
	int	fd;

	flag_in = O_RDONLY;
	flag_out = O_WRONLY;
	if (chain->heredoc)
	{
		flag_in = O_RDONLY | O_CREAT;
		fla_out = O_WRONLY | O_APPEND;
	}
	fd_
}

t_cmd_chain	*validate_config_chain(t_cmd_chain *chain)
{
	if (check_config_file(chain->file_in, chain->file_out, chain->has_heredoc))
	{
		
	}
	if (!chain)
		return (NULL);
	return (chain);
}
