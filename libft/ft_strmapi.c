/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:01:20 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/01/20 19:10:53 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	len;
	unsigned int	i;

	if (s == 0 || f == 0)
		return (NULL);
	len = ft_strlen(s);
	if (!(newstr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	f(unsigned int i, char c)
{
	if (i + 1)
	{
		if (ft_isalpha(c))
			c = c - 32;
	}
	return (c);
}
