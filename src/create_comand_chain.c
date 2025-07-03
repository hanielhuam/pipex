/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comand_chain.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:29:43 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/02 21:25:50 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_cmd_chain	*chain_allocation(void)
{
	t_cmd_chain	*chain;

	chain = ft_calloc(1, sizeof(t_cmd_chain));
	if (!chain)
	{
		ft_putstr_fd("Allocation Error at chain creation\n", 2);
		return (NULL);
	}
	return (chain);
}

t_cmd_chain	*create_comand_chain(int argc, char **argv, char **env)
{
	t_cmd_chain	*chain;

	chain = chain_allocation();
	if (!chain)
		return (NULL);
	if (extract_file(argc, argv, chain))
	{
		free(chain);
		return (NULL);
	}
	if (extract_comands(argc, argv, chain))
	{
		clear_comand_chain(chain);
		return (NULL);
	}
	(void) env;
	return (chain);
}
