/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config_chain.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:03:27 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/16 20:10:42 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_config_file(t_cmd_chain *chain)
{
	int	flags;

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	if (chain->has_heredoc)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	if (open_file_mode(chain->file_out, flags, 0644))
		return (-1);
	if (chain->has_heredoc && config_heredoc(chain))
	{
		close_files(NULL, chain->file_out, chain->has_heredoc);
		return (-1);
	}
	else if (!chain->has_heredoc && open_file(chain->file_in, O_RDONLY))
	{
		close_files(NULL, chain->file_out, chain->has_heredoc);
		return (-1);
	}
	return (0);
}

static char	*is_comand_path(char *comand, char *path)
{
	char	*result;
	char	*temp;

	if (access(comand, F_OK) != -1)
		return (ft_strdup(comand));
	temp = ft_strjoin(path, "/");
	if (!temp)
	{
		ft_putstr_fd("Allocatio Error at comand_path\n", 2);
		return (NULL);
	}
	result = ft_strjoin(temp, comand);
	free(temp);
	if (!result)
	{	
		ft_putstr_fd("Allocatio Error at comand_path\n", 2);
		return (NULL);
	}
	if (access(result, F_OK) == -1)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

static int	verify_comand(t_cmd *comand, char **path)
{
	char	*temp;

	while (*path)
	{
		temp = is_comand_path(comand->cmd_arg[0], *path);
		if (temp)
		{
			comand->path = temp;
			return (0);
		}
		path++;
	}
	ft_putstr_fd("there is a comand which not exist\n", 2);
	return (-1);
}

static int	validate_comands(t_list **cmds, char **path)
{
	t_list	*temp;

	temp = *cmds;
	while (temp)
	{
		if (verify_comand((t_cmd *)temp->content, path))
			return (-1);
		temp = temp->next;
	}
	return (0);
}

t_cmd_chain	*validate_config_chain(t_cmd_chain *chain)
{
	if (!chain)
		return (NULL);
	if (check_config_file(chain))
	{
		clear_comand_chain(chain);
		return (NULL);
	}
	if (validate_comands(chain->cmds, chain->path))
	{
		close_files(chain->file_in, chain->file_out, chain->has_heredoc);
		clear_comand_chain(chain);
		return (NULL);
	}
	return (chain);
}
