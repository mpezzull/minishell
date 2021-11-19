/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:53:15 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/19 00:33:43 by mpezzull         ###   ########.fr       */
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
		{
			ft_expand_env(backlash, "",	0);
			backlash = ft_strchr(backlash, 21);
		}
		else if (*(backlash + 1))
			backlash = ft_strchr(++backlash, 21);
		else
			break ;
	}
}