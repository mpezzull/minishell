/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:40:48 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/11/21 00:10:59 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_lexer	*ft_lexer(char *cmd_line)
{
	t_lexer	*lexer;
	t_lexer	**address_first;

	lexer = NULL;
	address_first = &lexer;
	ft_split_lexer(cmd_line, address_first);
	return (lexer);
}

// fills the list of structures in t_lexer ** lexer
void	ft_split_lexer(char *cmd_line, t_lexer **lexer)
{
	int			i;
	int			token;

	i = 0;
	while (cmd_line[i])
	{
		token = WORD;
		while (ft_is_space(cmd_line[i]))
			i++;
		if (cmd_line[i] != '\0')
			ft_lexer_core(cmd_line, lexer, token, &i);
	}
}

void	ft_lexer_core(char *cmd_line, t_lexer **lexer, int token, int *i)
{
	t_lexer	*tmp;
	char	*word;

	if (cmd_line[*i] == '>' || cmd_line[*i] == '<' || cmd_line[*i] == '|')
	{
		word = ft_token(cmd_line, i);
		token = ft_token_witch(word, 0);
	}
	else
		word = ft_create_word(cmd_line, i);
	if (word == NULL)
	{
		lexer = NULL;
		return ;
	}
	tmp = ft_lstnew_two(word, token);
	ft_lstadd_back_lexer(lexer, tmp);
}
