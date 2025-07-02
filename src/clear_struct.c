

#include "pipex.h"

void	clear_files(t_file *file_in, t_file *file_out)
{
	if (file_in)
	{
		free(file_in->name);
		free(file_in);
	}
	if (file_out)
	{
		free(file_out->name);
		free(file_out);
	}
}

void	clear_comands(t_cmd *cmd)
{
	int	i;

	if (cmd->path)
		free(path);
	if (cmd->comand)
		free(comand);
	if (cmd->cmd_arg && *cmd->cmd_arg)
	{
		i = 0;
		while (cmd_arg[i])
			free(cmd_arg[i++]);
		free(cmd_arg);
	}
	free(cmd);
}

void	clear_chain(t_cmd_chain *chain)
{
	if (chain->file_in || chain->file_out)
		clear_files(chain->file_in, chain->file_out);
	if (chain->cmds || *(chain->cmds))
	{	
		ft_lstclear(chain->cmds, clear_comands);
		free(chain->cmds);
	}
	free(chain);
}
