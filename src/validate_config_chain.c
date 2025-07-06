/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config_chain.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:03:27 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/05 22:25:13 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_config_file(t_file *file_in, t_file *file_out, int heredoc)
{
	int	flag_in;
	int	flag_out;

	flag_in = O_RDONLY;
	flag_out = O_WRONLY;
	if (heredoc)
	{
		flag_in = O_RDONLY | O_CREAT;
		flag_out = O_WRONLY | O_APPEND;
	}
	if (open_file(file_out, flag_out))
		return (-1);
	if (open_file(file_in, flag_in))
	{
		close_files(NULL, file_out, heredoc);
		return (-1);
	}
	return (0);
}

static char	*is_comand_path(char *comand, char *path)
{
	char	*result;
	char	*temp;

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
	ft_putstr_fd("comando não exist: ", 2);
	ft_putstr_fd(comand->cmd_arg[0], 2);
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
	if (check_config_file(chain->file_in, chain->file_out, chain->has_heredoc))
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
