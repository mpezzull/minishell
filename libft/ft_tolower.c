/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:28:19 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/11/21 04:33:30 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strlowcase(char *temp)
{
	int		index;
	char	*str;

	str = ft_strdup(temp);
	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] >= 65) && (str[index] <= 90))
		{
			str[index] = str[index] + 32;
		}
		index++;
	}
	return (str);
}
