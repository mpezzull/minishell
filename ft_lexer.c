/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:40:48 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/22 01:12:12 by mde-rosa         ###   ########.fr       */
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
	ft_line_to_args(cmd_line, address_first);

//inizia la stampa della lista
	tmp = *address_first;
	while (tmp)
	{
		printf("%s %d\n", (tmp)->args, (tmp)->token);
		fflush(stdout);
		tmp = (tmp)->next;
	}
//termina stampa della lista

	return (lexer);
}

// prende in ingresso la cmd_line e riempe la lista con gli argomenti
void	ft_line_to_args(char *cmd_line, t_lexer **lexer)
{
	t_lex_data	list;
	int			i;

	list = initlist();
	i = 0;
	while (cmd_line[i])
	{
		list = initlist();
		while (ft_is_space(cmd_line[i]))
			i++;
		list.start = i;
		if (cmd_line[i] == '\'')
			ft_single_quote(cmd_line, &i, lexer, &list);
		else if (cmd_line[i] == '\"')
			ft_double_quote(cmd_line, &i, lexer, &list);
		else if (cmd_line[i] == '>' || cmd_line[i] == '<' || cmd_line[i] == '|')
			ft_token(cmd_line, &i, lexer, &list);
		else
			i++;
	}
}
