/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:40:48 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/26 17:14:59 by mde-rosa         ###   ########.fr       */
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
	printf("%10s %s\n", "args", "token");
	while (tmp)
	{
		printf("%10s %3d\n", (tmp)->args, (tmp)->token);
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
	t_lexer		*tmp;
	int			i;
	char		*word;
	int			token;

	list = initlist();
	i = 0;
	while (cmd_line[i])
	{
		list = initlist();
		while (ft_is_space(cmd_line[i]))
			i++;
		list.start = i;
		if (cmd_line[i] == '>' || cmd_line[i] == '<' || cmd_line[i] == '|')
		{
			word = ft_token(cmd_line, &i, lexer);
			token = ft_token_witch(word);
		}
		else
		{
			word = ft_create_word(cmd_line, &i);
			token = WORD;
		}
		tmp = ft_lstnew_two(word, token);
		ft_lstadd_back_lexer(lexer, tmp);
	}
}

char	*ft_create_word(char *cmd_line, int *index)
{
	int		start;
	int		lenght;
	char	type;
	char	*word;

	start = *index;
	lenght = 0;
	while (cmd_line[*index] && ft_is_space(cmd_line[*index]) == 0
		&& ft_there_is_token(cmd_line, *index) == 0)
	{
		if (cmd_line[*index] == '\'' || cmd_line[*index] == '\"')
		{
			type = cmd_line[*index];
			ft_check_closed(cmd_line, (*index)++);
			while (cmd_line[*index] != type)
			{
				if (type == '\'' && cmd_line[*index] == '$')
					lenght++;
				(*index)++;
				lenght++;
			}
			(*index)++;
		}
		else
		{
			lenght++;
			(*index)++;
		}
	}
	word = ft_save_word(cmd_line, &start, lenght);
	return (word);
}


char *ft_save_word(char *cmd_line, int *start, int lenght)
{
	char	*word;
	char	type;
	int		index;

	index = 0;
	word = (char *)malloc((lenght * sizeof(char) + 1));
	if (!word)
		ft_error(strerror(errno), errno);
	word[0] = '\0';
	while (cmd_line[*start] && ft_is_space(cmd_line[*start]) == 0
		&& ft_there_is_token(cmd_line, *start) == 0)
	{
		if (cmd_line[*start] == '\'' || cmd_line[*start] == '\"')
		{
			type = cmd_line[*start];
			(*start)++;
			while (cmd_line[*start] != type)
			{
				if (type == '\'' && cmd_line[*start] == '$')
					word[index++] = '\\';
				word[index++] = cmd_line[(*start)++];
			}
			if (cmd_line[*start] == type)
				(*start)++;
		}
		else
			word[index++] = cmd_line[(*start)++];
	}
	word[index] = '\0';
	return (word);
}

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
