/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:44:17 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/06/13 19:00:13 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct s_cmd
{
	char	*comand;
	char	**args;
}			t_cmd;

typedef struct s_cmd_chain
{
	t_list	**cmds;
	int		fd_in;
	int		fd_out;
	int		**pipes;
	char	**path;
}			t_cmd_chain;

t_cmd_chain	*create_comand_chain(int argc, char **argv, char **env);
t_cmd_chain	*validate_chain(t_cmd_chain *chain);
void		execute_comand_chain(t_cmd_chain *chain);
void		clear_comand_chain(t_cmd_chain *chain);

int			**init_pipes(int size, int nproc);
void		clear_all_pipes(int **pipe);

#endif
