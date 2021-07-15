/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:10:51 by mpezzull          #+#    #+#             */
/*   Updated: 2021/01/20 20:32:13 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;

	temp = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			while (temp)
			{
				new = temp->next;
				(*del)(temp->content);
				free(temp);
				temp = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&temp, new);
		lst = lst->next;
	}
	return (temp);
}
