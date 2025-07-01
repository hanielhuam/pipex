

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

void	clear_comands(t_cmd *cmds)
{
	t_cmd	*cmd_init;
	char	**cmd_arg_init;

	cmd_init = cmds;
	cmd_arg_init = cmd->cmd_arg;
	while (*cmds)
	{
		while (*(cmd->cmd_arg))
		{
			free(*(cmd->cmd_arg));
			cmd->cmd_arg++;
		}
		cmd++;
	}
	free(cmd_arg_init);
	free(cmd_init);
}

void	clear_chain(t_cmd_chain *chain)
{
	if (chain->file_in || chain->file_out)
		clear_files(chain->file_in, chain->file_out);
	if (chain->cmds || *(chain->cmds))
		clear_comands(chain->cmds);
	free(chain);
}
