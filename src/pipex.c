
#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	while (*env)
		ft_printf("%s\n", *env++);
	return (0);
}
