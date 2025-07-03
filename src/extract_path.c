#include "pipex.h"

int	extract_path(char **env, t_cmd_chain *chain)
{
	chain->env = env;
	return (0);
}
