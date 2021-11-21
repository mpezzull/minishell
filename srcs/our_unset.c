/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:54:54 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/11/21 02:22:26 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_our_unset(char **args, char **envp)
{
	int		argc;
	int		i;
	int		size_envp;

	i = 1;
	argc = ft_count_args(args);
	size_envp = ft_count_args(envp);
	while (i < argc)
	{
		if (ft_check_if_exists_unset(args[i], envp))
			envp = ft_realloc_unset(envp, size_envp--, args[i++]);
		else
			i++;
	}
	return (envp);
}

char	**ft_realloc_unset(char	**ptr, int cur_size, char	*args)
{
	char	**new_ptr;
	int		i;
	int		j;

	if (ptr == 0)
	{
		ptr = ft_calloc_starstar(cur_size);
		return (ptr);
	}
	new_ptr = ft_calloc_starstar(cur_size);
	i = 0;
	j = 0;
	while (ptr[i])
	{
		if (ft_strncmp(ptr[i], args, ft_strlen(args)) == 0
			&& (ptr[i][ft_strlen(args)] == '='))
			i++;
		else
			new_ptr[j++] = ft_strdup(ptr[i++]);
	}
	ft_free_env(ptr);
	free(ptr);
	return (new_ptr);
}

char	**ft_calloc_starstar(int cur_size)
{
	char	**ptr;

	ptr = (char **)ft_calloc((cur_size), sizeof(char *));
	if (!ptr)
		ft_error(strerror(errno), errno);
	return (ptr);
}

int	ft_check_if_exists_unset(char *str, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if ((ft_strncmp(envp[i], str, ft_strlen(str)) == 0)
			&& (envp[i][ft_strlen(str)] == '='))
			return (1);
		i++;
	}
	return (0);
}
