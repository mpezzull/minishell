/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:40:48 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/28 02:05:46 by mde-rosa         ###   ########.fr       */
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
	printf(" #\targs\tTOKEN\n");
	while (tmp)
	{
		printf(" %d %10s\t", i, (tmp)->args);
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
		i++;
		tmp = (tmp)->next;
	}
//termina stampa della lista

	return (lexer);
}

// fills the list of structures in t_lexer ** lexer
void	ft_split_lexer(char *cmd_line, t_lexer **lexer)
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
		token = WORD;
		while (ft_is_space(cmd_line[i]))
			i++;
		list.start = i;
		if (cmd_line[i] == '>' || cmd_line[i] == '<' || cmd_line[i] == '|')
		{
			word = ft_token(cmd_line, &i, lexer);
			token = ft_token_witch(word);
		}
		else
			word = ft_create_word(cmd_line, &i);
		tmp = ft_lstnew_two(word, token);
		ft_lstadd_back_lexer(lexer, tmp);
	}
}

// returns the word starting from the index up to the next space/token
// increment the index to the end of the word
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

char	*ft_save_word(char *cmd_line, int *start, int lenght)
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
