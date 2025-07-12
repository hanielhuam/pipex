/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:50:01 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/11 19:33:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	finish_program(t_cmd_chain *chain)
{
	close_all_pipes(chain->pipes);
	close_files(chain->file_in, chain->file_out, chain->has_heredoc);
	clear_comand_chain(chain);
}
