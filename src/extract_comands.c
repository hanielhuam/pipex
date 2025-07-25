/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_comands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:36:38 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/03 21:33:11 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_cmd	*compose_cmd(t_cmd *cmd, char *str)
{
	char	**cmd_arg;

	if (!str || !*str)
		return (NULL);
	cmd_arg = ft_split(str, ' ');
	if (!cmd_arg || !*cmd_arg)
	{
		ft_putstr_fd("Allocation Error at split in cmd_args\n", 2);
		return (NULL);
	}
	cmd->cmd_arg = cmd_arg;
	return (cmd);
}

static t_list	*create_cmd(char	*str)
{
	t_list	*node;
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
	{
		ft_putstr_fd("Allocation Error at t_cmd\n", 2);
		return (NULL);
	}
	if (!compose_cmd(cmd, str))
	{
		free(cmd);
		return (NULL);
	}
	node = ft_lstnew(cmd);
	if (!node)
	{
		ft_putstr_fd("Allocation Error at t_list\n", 2);
		clear_comands(cmd);
		return (NULL);
	}
	return (node);
}

static t_list	**create_cmd_list(int sz_cmds, char **comands)
{
	t_list	**list;
	t_list	*temp;
	int		i;

	list = ft_calloc(1, sizeof(t_list *));
	if (!list)
	{
		ft_putstr_fd("Allocation Error at cmd_list\n", 2);
		return (NULL);
	}
	i = 0;
	while (i < sz_cmds)
	{
		temp = create_cmd(comands[i++]);
		if (!temp)
		{
			ft_lstclear(list, clear_comands);
			free(list);
			return (NULL);
		}
		ft_lstadd_back(list, temp);
	}
	return (list);
}

int	extract_comands(int argc, char **argv, t_cmd_chain *chain)
{
	t_list	**cmds;

	chain->sz_cmds = argc - 3 - chain->has_heredoc;
	if (chain->sz_cmds < 2)
	{
		ft_putstr_fd("too few comands\n", 2);
		return (-1);
	}
	cmds = create_cmd_list(chain->sz_cmds, &argv[2 + chain->has_heredoc]);
	if (!cmds)
		return (-1);
	chain->cmds = cmds;
	return (0);
}
