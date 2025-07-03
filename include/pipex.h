/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:44:17 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/02 21:16:31 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_list.h"
# include "ft_printf.h"

typedef struct s_file
{
	char	*name;
	int		fd;
}			t_file;

typedef struct s_cmd
{
	char	*path;
	char	**cmd_arg;
}			t_cmd;

typedef struct s_cmd_chain
{
	t_list	**cmds;
	t_file	*file_in;
	t_file	*file_out;
	int		**pipes;
	char	**path;
	int		sz_cmds;
	char	**env;
}			t_cmd_chain;

t_cmd_chain	*create_comand_chain(int argc, char **argv, char **env);
int			extract_file(int argc, char **argv, t_cmd_chain *chain);
int			extract_comands(int argc, char **argv, t_cmd_chain *chain);
t_cmd_chain	*validate_chain(t_cmd_chain *chain);
void		execute_comand_chain(t_cmd_chain *chain);
void		clear_comand_chain(t_cmd_chain *chain);
void		clear_files(t_file *file_in, t_file *file_out);
void		clear_comands(void	*cmd);
int			**init_pipes(int size, int nproc);
void		clear_all_pipes(int **pipe);

#endif
