/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:54:05 by assokenay         #+#    #+#             */
/*   Updated: 2021/08/03 18:31:30 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*current;
	size_t	size;

	if (argc == 1)
	{
		chdir(getenv("HOME"));
	//	return (0);
	}
	else
	{
		argv = 0;
	}
	current = NULL;
	size = 1050;
	current = getcwd(current, size);
	printf("%s\n", current);
	free (current);
	return (0);
}
