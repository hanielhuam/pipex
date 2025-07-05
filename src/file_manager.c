#include "pipex.h"

int	open_file(t_file *file, int flags)
{
	int	fd;

	fd = open(file->name, flags);
	if (fd == -1)
	{
		ft_putstr_fd("could not open file", 2);
		return (-1);
	}
	file->fd = fd;
	return (0);
}

