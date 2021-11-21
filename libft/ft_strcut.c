/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:09:35 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/21 04:30:07 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcut(char *str, int begin, int len)
{
	int	l;

	l = ft_strlen(str);
	if (len < 0)
		len = l - begin;
	if (begin + len > l)
		len = l - begin;
	ft_memmove(str + begin, str + begin + len, l - len + 1);
	return (len);
}
