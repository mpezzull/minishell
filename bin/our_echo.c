/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:54:05 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/11/20 23:52:56 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

//ritorna il num di caratteri letti, (1 se solo '-'), 0 se non contiene opzioni!
int	check_options(char *str, char option)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	if (str[index] == '-')
		index++;
	else
		return (0);
	while (str[index] == option)
		index++;
	if (!(str[index] == '\0'))
		return (0);
	return (index);
}

int	main(int argc, char **argv)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	if (argc > 1)
	{
		if (option == 0)
		{	
			while (check_options(argv[i], 'n') > 1)
				i++;
		}
		if (i > 1)
			option = 1;
		while (i < argc)
		{
			printf("%s", argv[i]);
			if (i < (argc - 1))
				printf(" ");
			i++;
		}
	}
	if (option == 0)
		printf("\n");
	return (0);
}
