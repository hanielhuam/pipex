/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:44:17 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/14 19:30:21 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_list.h"
# include "ft_printf.h"
# include "get_next_line.h"

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
	int		has_heredoc;
	char	*limiter;
	int		**pipes;
	char	**path;
	int		sz_cmds;
	char	**env;
}			t_cmd_chain;

t_cmd_chain	*create_comand_chain(int argc, char **argv, char **env);
int			extract_file(int argc, char **argv, t_cmd_chain *chain);
int			extract_comands(int argc, char **argv, t_cmd_chain *chain);
int			extract_path(char **env, t_cmd_chain *chain);
t_cmd_chain	*validate_config_chain(t_cmd_chain *chain);
int			has_heredoc(char **argv, t_cmd_chain *chain);
int			config_heredoc(t_cmd_chain *chain);
int			open_file(t_file *file, int flags);
char		*ft_read_file(int fd);
void		process_comand_chain(t_cmd_chain *chain);
void		finish_program(t_cmd_chain *chain);
void		clear_comand_chain(t_cmd_chain *chain);
void		clear_files(t_file *file_in, t_file *file_out);
void		clear_comands(void	*cmd);
void		close_files(t_file *file_in, t_file *file_out, int has_heredoc);
void		delete_heredoc(t_file *file_in);
int			init_pipes(t_cmd_chain *chain);
void		close_all_pipes(int **pipe);
void		close_pipes_unles(int **pipes, int in, int out);
void		clear_fds(int **fds);

#endif
