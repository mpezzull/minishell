/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:20:01 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/20 17:23:43 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_double_quote(char *cmd_line, int *i, t_lexer **lexer,
		t_lex_data *list)
{
	char	*word;
	t_lexer	*tmp;

	*i = ft_dquote_data(cmd_line, *i, list);
	word = ft_dquote_arg(cmd_line, *lexer, list);
	tmp = ft_lstnew_two(word, WORD);
	ft_lstadd_back_lexer(lexer, tmp);
	(*i)++;
}

//salva in list le posizioni di start e end della parola
//restituisce l'indice dopo la fine della parola
int	ft_dquote_data(char *cmd_line, int i, t_lex_data *list)
{
	list->d_quote_open = 1;
	if (ft_there_is_char(cmd_line, i, '\"'))
	{
		i++;
		list->start++;
		list->d_quote_closed = 1;
		while (cmd_line[i] != '\"')
			i++;
		list->end = i - 1;
	}
	else
	{
		while ((cmd_line[i] && ft_is_space(cmd_line[i]) == 0
				&& ft_there_is_token(&cmd_line[i], i) == 0))
			i++;
		list->end = i - 1;
	}
	return (i);
}

// dai dati di list estrae la parola anteponendo, se necessario
// '\\' prima dei simboli da non interpretare.
char	*ft_dquote_arg(char *cmd_line, t_lexer *lexer, t_lex_data *list)
{
	char	*arg;

	arg = NULL;
	if (list->d_quote_open && list->d_quote_closed)
		arg = ft_dquote_openclosed(cmd_line, lexer, list);
	else if (list->d_quote_open && list->d_quote_closed == 0)
		arg = ft_quote_notclosed(cmd_line, lexer, list);
	return (arg);
}

// dai dati di list estrae la parola.
// virgoletta doppia aperta e chiusa, non viene interpretato nulla,
// bisogna aggiungere backslash prima del $.
char	*ft_dquote_openclosed(char *cmd_line, t_lexer *lexer, t_lex_data *list)
{
	int		start;
	int		lenght;
	char	*arg;
	int		i;

	i = 0;
	start = list->start;
	lenght = (1 + list->end - list->start);
	arg = (char *)malloc((lenght * sizeof(char) + 1));
	while (start <= list->end)
		arg[i++] = cmd_line[start++];
	arg[i] = '\0';
	*list = initlist();
	return (arg);
}
