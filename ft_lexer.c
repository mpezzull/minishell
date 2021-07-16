/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:40:48 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/16 19:54:54 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_quotes(char *cmd_line);
int		ft_is_space(char c);
int		ft_is_end(char *str, int index);


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

t_lexer	*ft_lexer(char *cmd_line)
{
	t_lexer	*lexer;
	t_lexer	*tmp;
	void	*address_first;
	char	**args;

	address_first = &lexer;
	args = ft_quotes(cmd_line);
// stampa tutte le strutture (10)
//	int i = 0;
//	while (i++ < 10)
//	{
//		tmp = ft_lstnew_two(ft_strdup("parola"), &i);
//		ft_lstadd_back_lexer(address_first, tmp);
//	}
//fine stampa
	return (lexer);
}

typedef struct s_lex_data
{
	int	s_quote;
	int	d_quote;
	int	start;
	int	end;
}				t_lex_data;

t_lex_data	initlist(void)
{
	t_lex_data		list;

	list.start = 0;
	list.end = 0;
	list.s_quote = 0;
	list.d_quote = 0;
	return (list);
}

// ritorna il numero di caratteri che compongono il token , ritorna 0 se non ci sono token.
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

char	**ft_quotes(char *cmd_line)
{
	char		*new_line;
	char		**args;
	t_lex_data	list;
	
	list = initlist();
	
	printf("cmd_line : %s\n", cmd_line);
	new_line = ft_strdup(cmd_line);
	printf("ft_quotes: %s\n", new_line);

	int i;

	i = 0;
	while (cmd_line[i])
	{
		i += ft_is_space(cmd_line[i]);
		list.start = i;
		if (cmd_line[i] == '\'')
		{
			list.s_quote = 1;
			list.start += 1;
		}
		if (cmd_line[i] == '\"')
		{
			list.d_quote = 1;
			list.start += 1;
		}
		while (cmd_line[i])
		{
			if (list.s_quote == 0 && list.d_quote == 0)
			{
				if ((ft_is_space(cmd_line[i]) == 0) && (ft_is_end(&cmd_line[i], i)
						== 0))
					i++;
				else
				{
					list.end = i - 1;
					if (ft_is_space(cmd_line[i]))
						i++;
				}
			}
			if (list.s_quote)
			{
				if (cmd_line[i] != '\'')
					i++;
				list.end = i - 1;
			}
			if (list.d_quote)
			{
				if (cmd_line[i] != '\"')
					i++;
				list.end = i - 1;
			}
			printf("list: start %d - end %d -  %d %d") // continuare il print per stampare struttura e vedere se funziona
		}
	}

	return (args);
}
