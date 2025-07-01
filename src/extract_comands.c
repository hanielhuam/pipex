

#include "pipex.h"

t_list	**create_cmd_list(int argc, char **argv)
{
	t_list	**list;
	int		i;

	list = ft_calloc(1, sizeof(t_list *));
	if (!list)
	{
		ft_putstr_fd("Allocation Error at cmd_list");
		return (NULL);
	}
	i = 0
	while ()
}

int	 extract_comands(int argc, char **argv, t_cmd_chain *chain)
{
	t_list	**cmds;

	chain->cmd_sz = argc - 3;
	cmds = create_cmd_list(argc, argv);
	if (!cmds)
		return (-1);
	chain->cmds = cmds;
	return (0);
}
