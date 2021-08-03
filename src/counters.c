/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:09:58 by assokenay         #+#    #+#             */
/*   Updated: 2021/08/02 23:11:05 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_count_chr(char *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
		if (str[i++] == c)
			res++;
	return (res);
}

int	ft_count_words(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
}
