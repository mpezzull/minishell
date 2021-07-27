/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:41:43 by mpezzull          #+#    #+#             */
/*   Updated: 2021/07/27 14:05:12 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		ptr = (char **)malloc(sizeof(char *) * (new_size + 1));
		if (!ptr)
			ft_error(strerror(errno), errno);
		return (ptr);
	}
	if (new_size <= cur_size)
		return (ptr);
	new_ptr = (char **)malloc(sizeof(char *) * (new_size + 1));
	if (!new_ptr)
		ft_error(strerror(errno), errno);
	ft_memcpy(new_ptr, ptr, cur_size * sizeof(char *));
	free(ptr);
	return (new_ptr);
}

char	*ft_realloc_str(char	*ptr, int cur_size, int new_size)
{
	char	*new_ptr;

	if (ptr == 0)
	{
		ptr = (char *)malloc(sizeof(char) * (new_size + 1));
		if (!ptr)
			ft_error(strerror(errno), errno);
		return (ptr);
	}
	if (new_size <= cur_size)
		return (ptr);
	new_ptr = (char *)malloc(sizeof(char) * (new_size + 1));
	if (!new_ptr)
		ft_error(strerror(errno), errno);
	ft_memcpy(new_ptr, ptr, cur_size * sizeof(char));
	free(ptr);
	return (new_ptr);
}