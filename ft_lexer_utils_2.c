/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 01:08:16 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/28 02:09:28 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns the token as a string
// increment the index to the end of the word
char	*ft_token(char *cmd_line, int *i, t_lexer **lexer)
{
	char	*word;
	t_lexer	*tmp;
	int		token;

	token = ft_token_witch_index(cmd_line, *i);
	word = ft_token_arg(cmd_line, *i, token);
	*i = ft_token_lenght(token, *i);
	return (word);
}

// create and save the word (use malloc - to free!)
char	*ft_token_arg(char *cmd_line, int i, int token)
{
	char	*arg;
	int		lenght;

	if (token == GREATGREAT || token == LESSLESS)
		lenght = 2;
	else
		lenght = 1;
	arg = (char *)malloc((lenght * sizeof(char) + 1));
	arg[0] = cmd_line[i];
	if (token == GREATGREAT || token == LESSLESS)
	{
		arg[1] = cmd_line[i + 1];
		arg[2] = '\0';
	}
	else
		arg[1] = '\0';
	return (arg);
}

// increment the index up to the character following the token
int	ft_token_lenght(int token, int i)
{
	int	lenght;

	lenght = i;
	if (token == GREATGREAT || token == LESSLESS)
		lenght += 2;
	else
		lenght += 1;
	return (lenght);
}

// returns the token as an integer (as defined)
int	ft_token_witch_index(char *cmd_line, int i)
{
	if (cmd_line[i] == '>')
	{
		if (cmd_line[i + 1] == '>')
			return (GREATGREAT);
		return (GREAT);
	}
	else if (cmd_line[i] == '<')
	{
		if (cmd_line[i + 1] == '<')
			return (LESSLESS);
		return (LESS);
	}
	else if (cmd_line[i] == '|')
		return (PIPE);
	else
		return (NOTOKEN);
}

// returns the token as an integer (as defined)
int	ft_token_witch(char *word)
{
	int	i;

	i = 0;
	if (word[i] == '>')
	{
		if (word[i + 1] == '>')
			return (GREATGREAT);
		return (GREAT);
	}
	else if (word[i] == '<')
	{
		if (word[i + 1] == '<')
			return (LESSLESS);
		return (LESS);
	}
	else if (word[i] == '|')
		return (PIPE);
	else
		return (NOTOKEN);
}
