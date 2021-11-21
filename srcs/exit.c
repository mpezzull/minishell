/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:34:17 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/11/20 22:34:51 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_exit(t_cmd *cmd, char **our_env, int only_one)
{
	static int	save_only_one;

	if (cmd == NULL && our_env == NULL)
		save_only_one = only_one;
	else
	{
		if (cmd->args[1])
		{
			ft_pipestatus(SET, ft_atoi(cmd->args[1]));
			if (save_only_one != 1 && !ft_isnum(cmd->args[1]))
			{
				printf("bash: exit: numeric argument required\n");
				ft_pipestatus(SET, 255);
			}
		}
		if (save_only_one == 1)
			ft_only_exit(cmd, our_env);
	}
}

void	ft_only_exit(t_cmd *cmd, char **our_env)
{
	ft_free_env(our_env);
	free(our_env);
	write(1, "exit\n", 5);
	rl_clear_history();
	if (cmd->args[1] && !ft_isnum(cmd->args[1]))
		ft_error("bash: exit: numeric argument required", 255);
	ft_cmdclear(&cmd);
	exit(ft_atoi(ft_pipestatus(GET, 0)));
}
