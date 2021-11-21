/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:42:27 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/21 04:06:56 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd	*ft_parsing(t_lexer *lexer)
{
	t_cmd		*head;
	t_cmd		*temp;
	t_parser	data;
	int			i;

	data.token_found = PIPE;
	head = NULL;
	i = 0;
	temp = NULL;
	while (lexer)
	{
		if (ft_check_double_token(lexer))
		{
			ft_cmdclear(&head);
			return (NULL);
		}
		temp = ft_add_cmd(temp, &head);
		temp = ft_parsing_core(&data, lexer, temp, &i);
		if (temp && temp->error)
			return (NULL);
		lexer = lexer->next;
	}
	return (head);
}

t_cmd	*ft_add_cmd(t_cmd *temp, t_cmd **head)
{
	if (!temp)
	{
		temp = ft_cmd_new(0);
		ft_cmdadd_back(head, temp);
	}
	return (temp);
}

t_cmd	*ft_parsing_core(t_parser *data, t_lexer *lexer, t_cmd *temp, int *i)
{
	if (data->token_found == PIPE && lexer->token == WORD)
		ft_parsing_pipe(lexer, temp, data, i);
	else if ((data->token_found == GREAT || data->token_found == GREATGREAT)
		&& lexer->token == WORD)
		ft_parsing_greats(lexer, temp, data);
	else if (data->token_found == LESS && lexer->token == WORD)
	{
		temp->file_in = ft_strdup(lexer->args);
		temp->in = data->token_found;
		data->token_found = 0;
	}
	else if (data->token_found == LESSLESS && lexer->token == WORD)
	{
		temp->in = data->token_found;
		data->token_found = 0;
		if (ft_heredoc_shell(lexer, temp))
		{
			temp->error = 1;
			return (temp);
		}
	}
	else
		temp = ft_parsing_token(lexer, temp, data, i);
	return (temp);
}

t_cmd	*ft_parsing_token(t_lexer *lexer, t_cmd *temp, t_parser *data, int *i)
{
	if (lexer->token == WORD && data->token_found != PIPE)
	{
		if (!temp->cmd)
			temp->cmd = ft_strdup(lexer->args);
		temp->args = ft_realloc(temp->args, *i, *i + 1);
		temp->args[(*i)++] = ft_strdup(lexer->args);
	}
	if (lexer->token == GREAT || lexer->token == GREATGREAT)
	{
		data->token_found = lexer->token;
		temp->out = data->token_found;
	}
	if (lexer->token == LESS || lexer->token == LESSLESS)
		data->token_found = lexer->token;
	if (lexer->token == LESS || lexer->token == LESSLESS)
		temp->in = data->token_found;
	if (lexer->token == PIPE)
	{
		data->token_found = lexer->token;
		if (temp->out == DEFAULT)
			temp->out = data->token_found;
		*i = 0;
		temp = temp->next;
	}
	return (temp);
}
