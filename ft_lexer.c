/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:40:48 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/29 17:35:10 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_lexer(char *cmd_line)
{
	t_lexer	*lexer;
	t_lexer	*tmp;
	t_lexer	**address_first;

	lexer = NULL;
	address_first = &lexer;
	ft_split_lexer(cmd_line, address_first);

//inizia la stampa della lista
	tmp = *address_first;
	int i = 0;
	printf("---------ft_lexer-------------------\n #\targs\tTOKEN\n");
	while (tmp)
	{
		printf(" %d %10s\t", i++, (tmp)->args);
		if ((tmp)->token == GREAT)
			printf("%s\n", "GREAT");
		if ((tmp)->token == LESS)
			printf("%s\n", "LESS");
		if ((tmp)->token == GREATGREAT)
			printf("%s\n", "GREATGREAT");
		if ((tmp)->token == LESSLESS)
			printf("%s\n", "LESSLESS");
		if ((tmp)->token == PIPE)
			printf("%s\n", "PIPE");
		if ((tmp)->token == WORD)
			printf("%s\n", "WORD");
		fflush(stdout);
		tmp = (tmp)->next;
	}
	printf("---------ft_lexer-------------------\n");
//termina stampa della lista

	return (lexer);
}

// fills the list of structures in t_lexer ** lexer
void	ft_split_lexer(char *cmd_line, t_lexer **lexer)
{
	t_lexer		*tmp;
	int			i;
	char		*word;
	int			token;

	i = 0;
	while (cmd_line[i])
	{
		token = WORD;
		while (ft_is_space(cmd_line[i]))
			i++;
		if (cmd_line[i] != '\0')
		{
			if (cmd_line[i] == '>' || cmd_line[i] == '<' || cmd_line[i] == '|')
			{
				word = ft_token(cmd_line, &i, lexer);
				token = ft_token_witch(word, 0);
			}
			else
				word = ft_create_word(cmd_line, &i);
			tmp = ft_lstnew_two(word, token);
			ft_lstadd_back_lexer(lexer, tmp);
		}
	}
}
