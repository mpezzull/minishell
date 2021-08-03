/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:54:05 by assokenay         #+#    #+#             */
/*   Updated: 2021/08/04 01:34:37 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	char	*buffer;
	size_t	size;

	buffer = NULL;
	size = 100;
	buffer = getcwd(buffer, size);
	printf("%s\n", buffer);
	free (buffer);
	return (0);
}
