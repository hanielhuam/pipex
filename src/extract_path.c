/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:07:29 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/07/03 22:08:01 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (&env[i][5]);
		i++;
	}
	return (NULL);
}

int	extract_path(char **env, t_cmd_chain *chain)
{
	char	*path;
	char	**split;

	chain->env = env;
	path = find_path(env);
	if (!path)
		return (-1);
	split = ft_split(path, ':');
	if (!split || !split[0])
	{
		if (split)
			free(split);
		ft_putstr_fd("Allocation Error at Path split\n", 2);
		return (-1);
	}
	chain->path = split;
	return (0);
}
