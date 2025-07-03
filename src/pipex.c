/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:47:37 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/02 21:28:55 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	show_comands(void *content)
{
	int		i;
	t_cmd	*cmd;

	cmd = (t_cmd *)content;
	i = 0;
	while (cmd->cmd_arg[i])
		ft_printf("%s ", cmd->cmd_arg[i++]);
	ft_printf("\n");
}

static void	show_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		ft_printf("%s\n", env[i++]);
}

int	main(int argc, char **argv, char **env)
{
	t_cmd_chain	*chain;

	if (argc < 5)
	{
		ft_putstr_fd("too few arguments\n", 2);
		return (0);
	}
	chain = create_comand_chain(argc, argv, env);
	//chain = validate_chain(creat_comand_chain(argc, argv, env));
	if (!chain)
		return (0);
	ft_printf("file_in is \"%s\"\n", chain->file_in->name);
	ft_printf("file_out is \"%s\"\n", chain->file_out->name);
	ft_lstiter(*chain->cmds, show_comands);
	ft_printf("número de comando = %d\n", chain->sz_cmds);
	show_env(chain->path);
	clear_comand_chain(chain);
	return (0);
}
