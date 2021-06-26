/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:03:55 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/01/18 12:56:27 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*source;

	source = (char *)s;
	i = 0;
	while (i < n)
	{
		if (source[i] == c)
			return (source + i);
		i++;
	}
	return (0);
}
