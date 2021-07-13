/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:54:05 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/13 17:45:41 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


//echo -naaa ciao a tutti

int	main(int argc, char **argv)
{
	int	option;
	int	i;

	i = 1;
	if (argc == 1)
	{
		printf("\n");
		return (1);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'n' && argv[1][2] != ' ')
	{
		option = 1;
		i++;
	}
	while (i < argc)
	{
		printf("%s", argv[i]);
		if (i < (argc - 1))
			printf(" ");
		if (i == (argc - 1) && option == 0)
			printf("\n");
		i++;
	}
	return (0);
}
