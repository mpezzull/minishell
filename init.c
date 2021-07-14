/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:09:05 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/14 15:48:31 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_instr	*init_instr(void)
{
	t_instr	*instr;

	instr = (t_instr *)malloc(sizeof(t_instr));
	if (!instr)
		ft_error(strerror(errno), errno);
	instr->flag = NULL;
	return (instr);
}

void	ft_init_args(t_instr *instr, int num_args)
{
	instr->args = (char **)malloc(sizeof(char *) * (num_args + 2));
	if (!instr->args)
		ft_error(strerror(errno), errno);
}
