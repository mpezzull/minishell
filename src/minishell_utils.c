/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:41:43 by mpezzull          #+#    #+#             */
/*   Updated: 2021/08/10 13:02:00 by mde-rosa         ###   ########.fr       */
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
	return (new_ptr);
}
