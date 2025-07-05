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
	if (open_file(file_in, flags_in))
		return (-1);
	if (open_file(file_out), flag_out);
		{
			if (heredoc)
				finish_heredoc
			return (-1);
		}
	return (0);
}

t_cmd_chain	*validate_config_chain(t_cmd_chain *chain)
{
	if (!chain)
		return (NULL);
	if (check_config_file(chain->file_in, chain->file_out, chain->has_heredoc))
	{
		clear_comand_chain(chain);
		return (NULL);
	}
	if (validate_comands(chain->cmds))
	return (chain);
}
