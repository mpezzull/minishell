/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:48:21 by mpezzull          #+#    #+#             */
/*   Updated: 2021/07/26 17:58:02 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_expander(t_cmd *cmd, char** our_env)
{
	int	i;

	i = 0;
	while (cmd)
	{
		while (cmd->args && cmd->args[i])
		{
			if (ft_strchr(cmd->args[i], '$'))
				
		}

	}
}