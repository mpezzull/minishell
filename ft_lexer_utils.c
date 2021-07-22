/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:07:16 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/22 02:34:23 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lex_data	initlist(void)
{
	t_lex_data		list;

	list.start = 0;
	list.end = 0;
	list.s_quote_open = 0;
	list.d_quote_open = 0;
	list.s_quote_closed = 0;
	list.d_quote_closed = 0;
	return (list);
}

t_lexer	*ft_lstnew_two(char*args, int token)
{
	t_lexer	*lst;

	lst = (void *)malloc(sizeof(t_lexer));
	if (!lst)
		ft_error(strerror(errno), errno);
	lst->args = args;
	lst->token = token;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back_lexer(t_lexer **lst, t_lexer *new)
{
	t_lexer	*temp;

	if (!lst)
		return ;
	temp = *lst;
	if (temp == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	temp->next = new;
}

// ritorna il numero di caratteri che compongono il token,
// ritorna 0 se non ci sono token.
int	ft_there_is_token(char *str, int index)
{
	if (str[index] == '<' || str[index] == '>' || str[index] == '|')
		return (1);
	if ((str[index + 1] == '?') || (str[index]
			== '<' && str[index + 1] == '<') || (str[index] == '>'
			&& str[index + 1] == '>'))
		return (2);
	return (0);
}

// ritorna 1 se il carattere passato é [\\t] [\\n] [\\v] [\\f] [\\r] [space],
// altimenti ritorna 0.
int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
