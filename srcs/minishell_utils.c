/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:41:43 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/20 04:14:20 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**cp_str_array(char **str_arr)
{
	char	**our_str_arr;
	int		j;

	j = 0;
	our_str_arr = NULL;
	while (str_arr && str_arr[j])
	{
		our_str_arr = ft_realloc(our_str_arr, j, j + 1);
		our_str_arr[j] = ft_strdup(str_arr[j]);
		j++;
	}
	return (our_str_arr);
}

char	**ft_realloc(char	**ptr, int cur_size, int new_size)
{
	char	**new_ptr;

	if (ptr == 0)
	{
		ptr = (char **)ft_calloc((new_size + 1), sizeof(char *));
		if (!ptr)
			ft_error(strerror(errno), errno);
		return (ptr);
	}
	if (new_size <= cur_size)
		return (ptr);
	new_ptr = (char **)ft_calloc((new_size + 1), sizeof(char *));
	if (!new_ptr)
		ft_error(strerror(errno), errno);
	ft_memcpy(new_ptr, ptr, cur_size * sizeof(char *));
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

char	*ft_realloc_str(char	*ptr, int cur_size, int new_size)
{
	char	*new_ptr;

	if (ptr == 0)
	{
		ptr = (char *)ft_calloc(new_size + 1, sizeof(char));
		if (!ptr)
			ft_error(strerror(errno), errno);
		return (ptr);
	}
	if (new_size <= cur_size)
		return (ptr);
	new_ptr = (char *)ft_calloc(new_size + 1, sizeof(char));
	if (!new_ptr)
		ft_error(strerror(errno), errno);
	ft_memcpy(new_ptr, ptr, cur_size * sizeof(char));
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

// scorre la stringa fino a che non trova un carattere alfanumerico.
char	*ft_extract_alnum(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			break ;
	}
	return (ft_substr(str, 0, i));
}

void	ft_sleep(int ms)
{
	int	i;

	i = 0;
	while (i++ < ms * 770000)
		;
}

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
