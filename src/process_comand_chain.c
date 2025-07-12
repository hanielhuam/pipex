/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_comand_chain.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:08:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/11 21:17:36 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_comand_chain(t_cmd_chain *chain)
{
	char	*content;

	if (!chain || init_pipes(chain))
		return ;
	content = read_file_ulimit(chain->file_in->fd, chain->limiter);
	if (!content)
		content = ft_calloc(1, sizeof(char));
	ft_printf("%s\n", content);
	free(content);
}
