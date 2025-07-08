/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_comand_chain.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:08:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/07 21:27:08 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_comand_chain(t_cmd_chain *chain)
{
	char	
	if (!chain || !init_pipes(chain))
		return ;
	read_file(chain->file_in->fd, NULL);
}
