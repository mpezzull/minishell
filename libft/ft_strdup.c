/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:59:23 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/10/15 20:07:31 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		len;

	len = ft_strlen(src);
	copy = ((char *)malloc(sizeof(char) * (len + 1)));
	if (copy == NULL)
		return (0);
	ft_strcpy(copy, src);
	return (copy);
}
