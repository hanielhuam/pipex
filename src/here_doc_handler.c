/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:47:19 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/05 17:58:50 by hmacedo-         ###   ########.fr       */
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

void	delete_heredoc(t_file *file_in)
{
	if (file_in)
	{
		if (unlink(file_in->name) == -1)
			ft_putstr_fd("Error on delete heredoc file\n", 2);
	}
}
