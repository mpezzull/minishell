/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:54:05 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/11/21 01:49:49 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_our_cd(char **args, char **our_env)
{
	t_cd	cd;

	if (ft_init_cd(&cd, args) == -1)
		return (our_env);
	else if ((cd.argc == 1) || (ft_strcmp(args[1], "~") == 0)
		|| (ft_str_isspace(args[1]) == 0))
		chdir(getenv("HOME"));
	else if ((cd.argc == 1) || (ft_strcmp(args[1], "-") == 0)
		|| (ft_str_isspace(args[1]) == 0))
	{
		if (ft_cd_minus(&cd, our_env) == -1)
			return (our_env);
	}
	else
	{
		if (chdir(args[1]) == -1)
		{
			printf("minishell: cd: %s: No such file or directory\n", args[1]);
			free(cd.pwd);
			return (our_env);
		}
	}
	our_env = ft_update_pwd(&cd, our_env);
	return (our_env);
}

int	ft_cd_minus(t_cd *cd, char **our_env)
{
	cd->oldpwd = ft_getenv("OLDPWD", our_env);
	if (!chdir(cd->oldpwd))
	{
		printf("%s\n", cd->oldpwd);
		free(cd->oldpwd);
	}
	else
	{
		printf("minishell: cd: OLDPWD not set\n");
		free(cd->pwd);
		free(cd->oldpwd);
		return (-1);
	}
	return (0);
}

char	**ft_update_pwd(t_cd *cd, char **our_env)
{
	cd->oldpwd = ft_getenv("OLDPWD", our_env);
	if (ft_strcmp(cd->oldpwd, "") == 0)
	{
		free(cd->oldpwd);
		cd->oldpwd = ft_strjoin("OLDPWD=", cd->pwd);
		cd->size_envp = ft_count_args(our_env);
		our_env = ft_realloc(our_env, cd->size_envp, cd->size_envp + 1);
		free(our_env[cd->size_envp]);
		our_env[cd->size_envp] = ft_strdup(cd->oldpwd);
	}
	free(cd->oldpwd);
	cd->oldpwd = getcwd(cd->temp, 200);
	our_env = ft_change_pwd(our_env, cd->pwd, cd->oldpwd);
	free(cd->pwd);
	free(cd->oldpwd);
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
