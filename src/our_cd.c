/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:54:05 by assokenay         #+#    #+#             */
/*   Updated: 2021/08/04 18:57:18 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_our_cd(char **args)
{
	int	argc;

	argc = ft_count_args(args);
	if (argc > 1)
		printf("minishell: cd: too many arguments\n");
	else if ((argc == -1) || (ft_strcmp(args[0], "~") == 0)
		|| (ft_str_isspace(args[0]) == 0))
		chdir(getenv("HOME"));
	else
		if (chdir(args[0]) == -1)
			printf("minishell: cd: %s: No such file or directory\n", args[0]);
}

// return 0 if the string is only spaces, otherwise return 1
int	ft_str_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (1);
	}
	return (0);
}

//return how many strings there is in the array (args[?])
// -1 if there is not strings.
int	ft_count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}
