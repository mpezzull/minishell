/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 01:08:16 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/22 01:19:40 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_token(char *cmd_line, int *i, t_lexer **lexer, t_lex_data *list)
{
	char	*word;
	t_lexer	*tmp;
	int		token;

	token = ft_token_witch(cmd_line, *i);
	word = ft_token_arg(cmd_line, *i, token);
	tmp = ft_lstnew_two(word, token);
	ft_lstadd_back_lexer(lexer, tmp);
	*i = ft_token_lenght(token, *i);
//	(*i)++;
}

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

// ritorna l indice al carattere successivo al token.
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

int	ft_token_witch(char *cmd_line, int i)
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
