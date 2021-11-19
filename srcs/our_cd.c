/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:54:05 by assokenay         #+#    #+#             */
/*   Updated: 2021/11/18 23:38:08 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_our_cd(char **args, char **our_env)
{
	int		argc;
	char	*pwd;
	char	*temp;

	pwd = NULL;
	temp = NULL;
	pwd = getcwd(pwd, 200);
	argc = ft_count_args(args);
	if (argc > 2)
	{
		printf("minishell: cd: too many arguments\n");
		return (our_env);
	}
	else if ((argc == 1) || (ft_strcmp(args[1], "~") == 0)
		|| (ft_str_isspace(args[1]) == 0))
		chdir(getenv("HOME"));
	else
	{
		if (chdir(args[1]) == -1)
		{
			printf("minishell: cd: %s: No such file or directory\n", args[1]);
			return (our_env);
		}
	}
	our_env = ft_change_pwd(our_env, pwd, getcwd(temp, 200));
	return (our_env);
}

char	**ft_change_pwd(char **our_env, char *pwd, char *new_pwd)
{
	char	**ret;

	ret = our_env;
	while (*our_env)
	{
		if (!ft_strncmp(*our_env, "OLDPWD=", 7))
		{
			free(*our_env);
			*our_env = ft_strjoin("OLDPWD=", pwd);
		}
		else if (!ft_strncmp(*our_env, "PWD=", 4))
		{
			free(*our_env);
			*our_env = ft_strjoin("PWD=", new_pwd);
		}
		our_env++;
	}
	return (ret);
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
