/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:03:21 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/15 19:51:07 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	t_list *temp_next;

	temp = *lst;
	while (temp)
	{
		temp_next = temp->next;
		del(temp->content);
		free(temp);
		temp = temp_next;
	}
	*lst = NULL;
}
