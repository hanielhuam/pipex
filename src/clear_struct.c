

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

void	clear_comands(void *comand)
{
	t_cmd	*cmd;
	char	*temp;

	cmd = (t_cmd *)comand;
	free(cmd->comand);
	temp = cmd->
	while (*(cmd->args))

}

void	clear_chain(t_cmd_chain *chain)
{
	if (chain->file_in || chain->file_out)
		clear_files(chain->file_in, chain->file_out);
	if (chain->cmds || *(chain->cmds))
		ft_lstclear(chain->cmds, clear_comands);
}
