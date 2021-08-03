/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:09:05 by assokenay         #+#    #+#             */
/*   Updated: 2021/08/02 23:10:49 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*instr;

	instr = (t_cmd *)malloc(sizeof(t_cmd));
	if (!instr)
		ft_error(strerror(errno), errno);
	instr->flag = NULL;
	return (instr);
}

void	ft_init_args(t_cmd *instr, int num_args)
{
	instr->args = (char **)malloc(sizeof(char *) * (num_args + 2));
	if (!instr->args)
		ft_error(strerror(errno), errno);
}
