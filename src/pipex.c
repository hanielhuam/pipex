/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:47:37 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/07 17:16:27 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	show_comands(void *content)
{
	int		i;
	t_cmd	*cmd;

	cmd = (t_cmd *)content;
	i = 0;
	ft_printf("Comand = ");
	while (cmd->cmd_arg[i])
	{
		ft_printf("%s ", cmd->cmd_arg[i++]);
	}
	ft_printf("& path = %s\n", cmd->path);
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
	chain = validate_config_chain(create_comand_chain(argc, argv, env));
	if (!chain)
		return (0);
	process_comand_chain(chain);
	finishi_program(chain);
	return (0);
}
