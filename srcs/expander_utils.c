/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:53:15 by mpezzull          #+#    #+#             */
/*   Updated: 2021/10/20 22:22:00 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_delete_backslash(char *to_replace)
{
	char	*backlash;

	backlash = ft_strchr(to_replace, 21);
	while (backlash)
	{
		if (*(backlash + 1) && *(backlash + 1) == '$')
			ft_expand_env(backlash, "",	0);
		else if (*(backlash + 1))
			backlash = ft_strchr(++backlash, 21);
		else
			break ;
	}
}