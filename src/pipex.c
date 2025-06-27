
#include "pipex.h"

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
	return (0);
}
