/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_cd_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:48:20 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/11/21 15:56:25 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_init_cd(t_cd *cd, char **args)
{
	cd->pwd = NULL;
	cd->temp = NULL;
	cd->pwd = getcwd(cd->pwd, 200);
	cd->argc = ft_count_args(args);
	if (cd->argc > 2)
	{
		printf("minishell: cd: too many arguments\n");
		free(cd->pwd);
		return (-1);
	}
	return (0);
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
	while (args && args[i])
		i++;
	return (i);
}
