/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:40:48 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/20 00:46:27 by mde-rosa         ###   ########.fr       */
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

/*
//inizia la stampa della lista
	tmp = *address_first;
	while (tmp)
	{
		printf("%s %d\n", (tmp)->args, (tmp)->token);
		fflush(stdout);
		tmp = (tmp)->next;
	}
//termina stampa della lista
*/
	return (lexer);
}

char	*ft_line_to_args(char *cmd_line, t_lexer **lexer)
{
	char		*word;
	t_lex_data	list;
	t_lexer		*tmp;
	int			i;

	word = NULL;
	list = initlist();
	i = 0;
	while (cmd_line[i])
	{
		list = initlist();
		while (ft_is_space(cmd_line[i]))
			i++;
		list.start = i;
		if (cmd_line[i] == '\'')
		{
			list.s_quote_open = 1;
			if (ft_there_is_char(cmd_line, i, '\''))
			{
				i++;
				list.start++;
				list.s_quote_closed = 1;
				while (cmd_line[i] != '\'')
					i++;
				list.end = i - 1;
			}
			else
			{
				while ((cmd_line[i] && ft_is_space(cmd_line[i]) == 0
						&& ft_there_is_token(&cmd_line[i], i) == 0))
					i++;
				list.end = i - 1;
			}
			word = ft_create_arg(cmd_line, *lexer, &list);
			tmp = ft_lstnew_two(word, 0);
			ft_lstadd_back_lexer(lexer, tmp);
			i++;
		}
	}
//	while (*lexer)
//	{
//		printf("%s %d\n", (*lexer)->args, (*lexer)->token);
//		fflush(stdout);
//		*lexer = (*lexer)->next;
//	}
	return (word);
}

//virgoletta singola aperta e chiusa, non viene interpretato nulla, bisogna solo aggiungere backslash prima del $.
//virgoletta singola aperta ma non chiusa, la virgoletta deve essere solo stampata come un normale carattere bisogna solo aggiungere backslash prima della virgoletta.
char	*ft_create_arg(char *cmd_line, t_lexer *lexer, t_lex_data *list)
{
	int		start;
	int		lenght;
	char	*arg;
	int		i;

	arg = NULL;
	i = 0;
	if (list->s_quote_open && list->s_quote_closed)
	{
		start = list->start;
		lenght = (1 + list->end - list->start + ft_count_char(cmd_line, list->start, list->end, '$'));
		arg = (char *)malloc((lenght * sizeof(char) + 1));
		while (start <= list->end)
		{
			if (cmd_line[start] == '$')
				arg[i++] = '\\';
			arg[i++] = cmd_line[start++];
		}
		arg[i] = '\0';
		*list = initlist();
		return (arg);
	}
	if (list->s_quote_open && list->s_quote_closed == 0)
	{
		i = 0;
		arg = (char *)malloc(((list->end - list->start) * sizeof(char) + 2));
	}
	return (arg);
}