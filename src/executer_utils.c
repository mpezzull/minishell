/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:32:31 by mpezzull          #+#    #+#             */
/*   Updated: 2021/08/03 17:33:33 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strchr_int(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

int	ft_matr_del_and_free(char ***matrix)
{
	int	i;

	i = -1;
	if (!(*matrix))
		return (0);
	while ((*matrix)[++i])
	{
		free((*matrix)[i]);
		(*matrix)[i] = NULL;
	}
	free(*matrix);
	*matrix = NULL;
	return (0);
}

char	**ft_data_paths(char **env)
{
	char	*get_str;
	char	**path_matrix;

	get_str = ft_get_str_from_env("PATH", env);
	if (!get_str)
		return (0);
	path_matrix = ft_split(get_str, ':');
	free(get_str);
	return (path_matrix);
}
