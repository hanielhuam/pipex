/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:47:59 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/02 21:10:40 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_files(t_file *file_in, t_file *file_out)
{
	if (file_in)
	{
		free(file_in->name);
		free(file_in);
	}
	if (file_out)
	{
		free(file_out->name);
		free(file_out);
	}
}

void	clear_comands(void *content)
{
	int		i;
	t_cmd	*cmd;

	cmd = (t_cmd *)content;
	if (cmd->path)
		free(cmd->path);
	if (cmd->cmd_arg && *cmd->cmd_arg)
	{
		i = 0;
		while (cmd->cmd_arg[i])
			free(cmd->cmd_arg[i++]);
		free(cmd->cmd_arg);
	}
	free(cmd);
}

void	clear_path(char **path)
{
	int	i;

	if (!path || !*path)
	{
		if (path)
			free(path);
		return ;
	}
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
}

void	clear_comand_chain(t_cmd_chain *chain)
{
	if (chain->file_in || chain->file_out)
		clear_files(chain->file_in, chain->file_out);
	if (chaind->limiter)
		free(chain->limiter);
	if (chain->cmds)
	{	
		ft_lstclear(chain->cmds, clear_comands);
		free(chain->cmds);
	}
	if (chain->path)
		clear_path(chain->path);
	free(chain);
}
