/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:54:54 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/11/21 02:08:58 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_our_export(char **args, char **envp)
{
	int		argc;
	int		i;
	int		size_envp;
	char	*actual_value;

	i = 1;
	argc = ft_count_args(args);
	size_envp = ft_count_args(envp);
	while (i < argc)
	{
		actual_value = ft_check_if_exists(args[i], envp);
		if (actual_value == NULL
			|| ft_strcmp(actual_value, "") == 0)
		{
			envp = ft_realloc(envp, size_envp, size_envp + 1);
			envp[size_envp++] = ft_strdup(args[i++]);
		}
		else if (actual_value != NULL)
			envp = ft_update_env(args, i++, envp);
		if (actual_value)
			free (actual_value);
	}
	return (envp);
}

char	**ft_update_env(char **args, int i, char **envp)
{
	char	**variable;
	int		position;

	variable = ft_split(args[i], '=');
	position = ft_search_in_array(variable[0], envp);
	free(envp[position]);
	envp[position] = ft_strdup(args[i]);
	ft_free_env(variable);
	free(variable);
	return (envp);
}

int	ft_search_in_array(char *search, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strncmp(search, array[i++], ft_strlen(search)) == 0)
			return (i - 1);
	}
	return (0);
}

char	*ft_check_if_exists(char *str, char **envp)
{
	char	**splitted;
	char	*actual_value;
	int		equal;

	equal = ft_there_is_chr(str, '=');
	if (equal)
	{
		splitted = ft_split(str, '=');
		actual_value = ft_getenv(splitted[0], envp);
		ft_free_env(splitted);
		free(splitted);
		if (ft_strcmp(actual_value, "") == 0)
		{
			free(actual_value);
			return (NULL);
		}
		else
			return (actual_value);
	}
	return (NULL);
}

//returns 1 if there is almost one char in str
int	ft_there_is_chr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}
