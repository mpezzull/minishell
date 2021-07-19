/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:40:48 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/19 18:46:33 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_lex_data	t_lex_data;
char	*ft_line_to_args(char *cmd_line, t_lexer **lexer);
int		ft_is_space(char c);
int		ft_is_end(char *str, int index);
char	*ft_create_arg(char *cmd_line, t_lexer *lexer, t_lex_data *list);

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

// riempe tutte le strutture (10)
//	int i = 0;
//	while (i++ < 10)
//	{
//		tmp = ft_lstnew_two(ft_strdup("parola"), &i);
//		ft_lstadd_back_lexer(address_first, tmp);
//	}
//fine riempimento
t_lexer	*ft_lexer(char *cmd_line)
{
	t_lexer	*lexer;
	t_lexer	*tmp;
	t_lexer	**address_first;

	address_first = &lexer;
	ft_line_to_args(cmd_line, address_first);
	tmp = *address_first;
//	while (tmp)
//	{
//		printf("%s %d\n", (tmp)->args, (tmp)->token);
//		fflush(stdout);
//		tmp = (tmp)->next;
//	}
//	printf("%s %d\n", (*address_first)->args, (*address_first)->token);

	return (lexer);
}

struct s_lex_data
{
	int	s_quote_open;
	int	d_quote_open;
	int	s_quote_closed;
	int	d_quote_closed;
	int	start;
	int	end;
};

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

// ritorna il numero di caratteri che compongono il token, ritorna 0 se non ci sono token.
int	ft_is_end(char *str, int index)
{
	if (str[index] == '<' || str[index] == '>' || str[index] == '|'
		|| str[index] == '$')
		return (1);
	if ((str[index] == '$' && str[index + 1] == '?') || (str[index]
			== '<' && str[index + 1] == '<') || (str[index] == '>'
			&& str[index + 1] == '>'))
		return (2);
	return (0);
}

// ritorna 1 se il carattere passato é [\\t] [\\n] [\\v] [\\f] [\\r] [space], altimenti ritorna 0.
int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

//data una stringa ed una posizione in essa, scorre (partendo dalla posizione successiva a quella indicata) alla ricerca del carattere specificato in search
//ritorna 1 se trova il carattere, 0 se non lo trova.
int	ft_there_is_char(char *str, int index, char search)
{
	index++;
	while (str[index])
		if (str[index++] == search)
			return (1);
	return (0);
}
//ritorna il numero di quanti 'c' ci sono nella str da start a end
int	ft_count_char(char *str, int start, int end, char c)
{
	int	counter;

	counter = 0;
	while (start <= end)
	{
		if (str[start++] == c)
			counter++;
	}
	return (counter);
}

char	*ft_create_arg(char *cmd_line, t_lexer *lexer, t_lex_data *list)
{
	int		start;
	int		lenght;
	char	*arg;
	int		i;

	arg = NULL;
	i = 0;
 //virgoletta singola aperta e chiusa, non viene interpretato nulla, bisogna solo aggiungere backslash prima del $.
	if (list->s_quote_open && list->s_quote_closed)
	{
		start = list->start;
		lenght = (list->end - list->start + ft_count_char(cmd_line,
					list->start, list->end, '$'));
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
	 //virgoletta singola aperta ma non chiusa, la virgoletta deve essere solo stampata come un normale carattere bisogna solo aggiungere backslash prima della virgoletta.
	if (list->s_quote_open && list->s_quote_closed == 0)
	{
		i = 0;
		arg = (char *)malloc(((list->end - list->start) * sizeof(char) + 2));
	}
	return (arg);
}

char	*ft_line_to_args(char *cmd_line, t_lexer **lexer)
{
	char		*word;
	t_lex_data	list;
	t_lexer		*tmp;
	int			i;

	word = NULL;
	list = initlist();
//	printf("cmd_line : %s\n", cmd_line);
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
						&& ft_is_end(&cmd_line[i], i) == 0))
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
