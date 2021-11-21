/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:36:06 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/11/21 16:30:52 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_output(t_data *data, t_cmd *cmd)
{
	char	*line;

	line = NULL;
	{
		if (cmd->in != LESSLESS)
		{
			while (get_next_line(data->fd_pipe[0], &line) > 0)
			{
				printf("%s\n", line);
				if (line)
					free(line);
				line = NULL;
			}
			if (line)
				free(line);
			line = NULL;
		}
		close(data->fd_pipe[0]);
	}	
}

char	**ft_our_builtin(t_cmd *cmd, char **our_env)
{
	if (cmd->cmd)
	{
		if (!ft_strcmp(cmd->cmd, "exit"))
			ft_exit(cmd, our_env, 0);
		else if (!ft_strcmp_lowcase(cmd->cmd, "cd"))
			our_env = ft_our_cd(cmd->args, our_env);
		else if (!ft_strcmp_lowcase(cmd->cmd, "export"))
			our_env = ft_our_export(cmd->args, our_env);
		else if (!ft_strcmp_lowcase(cmd->cmd, "unset"))
			our_env = ft_our_unset(cmd->args, our_env);
		else
			return (NULL);
	}
	else
		return (NULL);
	return (our_env);
}
