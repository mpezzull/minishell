/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:54:05 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/14 02:58:19 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


//ritorna il numero di caratteri letti, (-1 se trova solo il '-'), 0 se la stringa non contiene opzioni!
int	check_options(char *str, char option)
{
	int index;

	index = 0;
	if (!str)
		return (0);
	if (str[index] == '-')
		index++;
	else
		return (0);
	while (str[index] == option)
		index++;
	if (!str[index] == '\0')
		return (0);
	if (index == 1)
		return (-1);
	return(index);
}
/*
./ft_echo -n -n -n -n ciao | cat -e
argc = 6;

*/
int	main(int argc, char **argv)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	if (argc > 1)
	{
		if (argv[1][0] == '-' && argv[1][1] == '\0')
		{
			i++;
			option = -1;
		}
		if (option == 0)
		{	
			while (check_options(argv[i], 'n') > 1)
				i++;
		}
		if (i > 1 && option == 0)
			option = 1;
		while (i < argc)
		{
			printf("%s", argv[i]);
			if (i < (argc - 1))
				printf(" ");
			i++;
		}
	}
	if (option <= 0)
		printf("\n");
	return (0);
}
		
/*
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
	*/

