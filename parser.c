/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:42:27 by mpezzull          #+#    #+#             */
/*   Updated: 2021/07/21 19:23:36 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_parsing(t_lexer *lexer)
{
	t_cmd		*head;
	t_cmd		*temp;
	t_parser	data;
	int			i;

	data.token_found = PIPE;
	head = NULL;
	i = 0;
	while (lexer)
	{
		if (data.token_found == PIPE)
		{
			data.n_args = ft_count_args(lexer);
			temp = ft_cmd_new(data.n_args);
			ft_cmdadd_back(&head, temp);
			if (lexer->token == WORD)
				temp->cmd = ft_strdup(lexer->args);
			data.token_found = 0;
		}
		else if ((data.token_found == GREAT || data.token_found == GREATGREAT)
			&& lexer->token == WORD)
		{
			temp->file_out = ft_strdup(lexer->args);
			temp->out = data.token_found;
			data.token_found = 0;
		}
		else if (data.token_found == LESS && lexer->token == WORD)
		{
			temp->file_in = ft_strdup(lexer->args);
			temp->in = data.token_found;
			data.token_found = 0;
		}
		else if (data.token_found == LESSLESS && lexer->token == WORD)
		{
			while (TRUE)
			{
				data.lessless = readline(">");
				if (ft_strcmp(data.lessless, lexer->args) == 0)
					break ;
				temp->args[i++] = data.lessless;
			}
		}
		else
		{
			if (lexer->token == WORD)
				temp->args[i++] = ft_strdup(lexer->args);
			if (lexer->token == GREAT || lexer->token == GREATGREAT)
			{
				data.token_found = lexer->token;
				temp->out = data.token_found;
			}
			if (lexer->token == LESS || lexer->token == LESSLESS)
			{
				data.token_found = lexer->token;
				temp->in = data.token_found;
			}
			if (lexer->token == PIPE)
			{
				data.token_found = lexer->token;
				temp->out = data.token_found;
				i = 0;
				temp = temp->next;
			}
		}
		lexer = lexer->next;
	}
	return (head);
}

t_cmd	*ft_cmd_new(int n_args)
{
	t_cmd	*cmd;

	cmd = (void *)malloc(sizeof(t_cmd));
	if (!cmd)
		ft_error(strerror(errno), errno);
	cmd->args = (char **)malloc(sizeof(char *) * (n_args + 1));
	if (!cmd->args)
		ft_error(strerror(errno), errno);
	cmd->next = NULL;
	cmd->in = DEFAULT;
	cmd->out = DEFAULT;
	return (cmd);
}

void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*temp;

	if (!cmd)
		return ;
	temp = *cmd;
	if (temp == NULL)
	{
		*cmd = new;
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

int	ft_count_args(t_lexer *lexer)
{
	int		count;
	char	*lessless;

	count = 0;
	if (!lexer)
		return (count);
	while (lexer && lexer->token != PIPE)
	{
		if (lexer->token == LESSLESS)
		{
			lexer = lexer->next;
			while (TRUE)
			{
				lessless = readline(">d");
				if (ft_strcmp(lessless, lexer->args) == 0)
					break ;
				count++;
			}
		}
		else
			count++;
		lexer = lexer->next;
	}
	count--;
	return (count);
}
