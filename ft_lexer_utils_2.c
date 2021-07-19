/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:31:16 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/20 00:32:17 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// data una stringa ed una posizione in essa, scorre (partendo dalla posizione
// successiva a quella indicata) alla ricerca del carattere search
// ritorna 1 se trova il carattere, 0 se non lo trova.
int	ft_there_is_char(char *str, int index, char search)
{
	index++;
	while (str[index])
		if (str[index++] == search)
			return (1);
	return (0);
}

//ritorna il numero di quanti 'c' ci sono nella str da start a end
int	ft_count_char(char *str, int start, int end, char c)
{
	int	counter;

	counter = 0;
	while (start <= end)
	{
		if (str[start++] == c)
			counter++;
	}
	return (counter);
}
