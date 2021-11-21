/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 00:39:22 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/11/21 00:40:01 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_update_path(char **our_env)
{
	char	**path;
	char	*old_path;
	char	*new_path;
	char	*t;
	char	*t1;

	path = NULL;
	path = ft_realloc(path, 0, 3);
	path[0] = ft_strdup("export");
	old_path = ft_getenv("PATH", our_env);
	t = ft_getenv("PWD", our_env);
	new_path = ft_strjoin(t, "/bin");
	t1 = ft_strjoin("PATH=", old_path);
	free(t);
	t = ft_strjoin(t1, ":");
	path[1] = ft_strjoin(t, new_path);
	ft_our_export(path, our_env);
	ft_free_env(path);
	free(path);
	free(old_path);
	free(t);
	free(new_path);
	free(t1);
	return (our_env);
}
