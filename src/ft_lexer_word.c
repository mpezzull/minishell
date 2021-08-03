/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:55:48 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/08/02 23:11:02 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// returns the word starting from the index up to the next space/token
// increment the index to the end of the word
char	*ft_create_word(char *cmd_line, int *index)
{
	int		start;
	int		lenght;
	char	*word;

	start = *index;
	lenght = 0;
	while (cmd_line[*index] && ft_is_space(cmd_line[*index]) == 0
		&& ft_is_token(cmd_line, *index) == 0)
		lenght = ft_word_lenght(cmd_line, index, lenght);
	word = ft_save_word(cmd_line, &start, lenght);
	return (word);
}

// returns the length of the word, includes the management of quotes.
// increment the index up to the character following the word.
int	ft_word_lenght(char *cmd_line, int *index, int lenght)
{
	char	type;

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
	return (lenght);
}

// creates the word and returns it full
char	*ft_save_word(char *cmd_line, int *start, int lenght)
{
	char	*word;
	int		index;

	index = 0;
	word = (char *)malloc((lenght + 1) * sizeof(char));
	if (!word)
		ft_error(strerror(errno), errno);
	while (cmd_line[*start] && ft_is_space(cmd_line[*start]) == 0
		&& ft_is_token(cmd_line, *start) == 0)
		ft_word_str(cmd_line, &index, start, word);
	word[index] = '\0';
	return (word);
}

// fills the word character by character
void	ft_word_str(char *cmd_line, int *index, int *start, char *word)
{
	char	type;

	if (cmd_line[*start] == '\'' || cmd_line[*start] == '\"')
	{
		type = cmd_line[*start];
		(*start)++;
		while (cmd_line[*start] != type)
		{
			if (type == '\'' && cmd_line[*start] == '$')
				word[(*index)++] = '\\';
			word[(*index)++] = cmd_line[(*start)++];
		}
		if (cmd_line[*start] == type)
			(*start)++;
	}
	else
		word[(*index)++] = cmd_line[(*start)++];
}
