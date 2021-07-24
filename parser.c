/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:42:27 by mpezzull          #+#    #+#             */
/*   Updated: 2021/07/24 17:11:01 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_parsing(t_lexer *lexer)
{
	t_cmd		*head;
	t_cmd		*temp;
	t_parser	data;
	int			i;

	data.token_found = FIRST;
	head = NULL;
	i = 0;
	temp = NULL;
	while (lexer)
	{
		ft_check_double_token(lexer);
		if (!temp)
		{
			temp = ft_cmd_new(0);
			ft_cmdadd_back(&head, temp);
			if (data.token_found == FIRST && lexer->token == WORD)
				temp->cmd = ft_strdup(lexer->args);
		}
		if (data.token_found == PIPE)
		{
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
			temp->in = data.token_found;
			data.token_found = 0;
			ft_heredoc_shell(lexer, temp, &i);
		}
		else
		{
			if (lexer->token == WORD)
			{
				temp->args = ft_realloc(temp->args, i, i + 1);
				temp->args[i++] = ft_strdup(lexer->args);
			}
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

void	ft_heredoc_shell(t_lexer *lexer, t_cmd *temp, int *i)
{
	t_parser	data;
	int			pid;

	pid = fork();
	signal(SIGINT, SIG_IGN);
	if (pid == 0)
	{
		while (TRUE)
		{
			signal(SIGQUIT, SIG_IGN);
			signal(SIGINT, ft_signal_handler_heredoc);
			data.lessless = readline(">");
			if (ft_strcmp(data.lessless, lexer->args) == 0)
				break ;
			temp->args = ft_realloc(temp->args, *i, *i + 1);
			temp->args[(*i)++] = data.lessless;
		}
		exit(0);
	}
	else
	{
		wait(NULL);
	}
}

void	ft_signal_handler_heredoc(int sig_num)
{
	if (sig_num == SIGINT)
		exit(0);
}