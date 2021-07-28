/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:07:16 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/28 16:01:40 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns 1 if char is a token.
// (it also checks the next character)
int	ft_is_token(char *str, int index)
{
	if (str[index] == '<' || str[index] == '>' || str[index] == '|')
		return (1);
	if ((str[index + 1] == '?') || (str[index]
			== '<' && str[index + 1] == '<') || (str[index] == '>'
			&& str[index + 1] == '>'))
		return (2);
	return (0);
}

// returns 1 if char is one among [\\t] [\\n] [\\v] [\\f] [\\r] [space].
int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

// returns 1 if there is another quote like cmd_line[i]
// exit with ft_error
int	ft_check_closed(char *cmd_line, int i)
{
	char	search;

	search = cmd_line[i];
	i++;
	while (cmd_line[i] != '\0')
	{
		if (cmd_line[i] == search)
			return (1);
		i++;
	}
	ft_error("Quote not closed", 1);
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
