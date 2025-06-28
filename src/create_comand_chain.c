

#include "pipex.h"

static t_cmd_chain	*chain_allocation(void)
{
	t_cmd_chain	*chain;
	chain = ft_calloc(1, sizeof(t_cmd_chain));
	if (!chain)
	{
		ft_putstr_fd("Allocation Error at chain creation\n", 2);
		return (NULL);
	}
	return (chain);
}

t_cmd_chain *create_comand_chain(int argc, char **argv, char **env)
{
	t_cmd_chain	*chain;

	chain = chain_allocation();
	if (!chain)
		return (NULL);
	if (!file_extractor(argc, argv, chain))
	{
		free(chain);
		return (NULL);
	}
	(void) env;
	return (NULL);
}
