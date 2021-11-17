/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:42:27 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/17 21:33:02 by mpezzull         ###   ########.fr       */
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
		if (!temp)
		{
			temp = ft_cmd_new(0);
			ft_cmdadd_back(&head, temp);
		}
		if (data.token_found == PIPE && lexer->token == WORD)
			ft_parsing_pipe(lexer, temp, &data, &i);
		else if ((data.token_found == GREAT || data.token_found == GREATGREAT)
			&& lexer->token == WORD)
			ft_parsing_greats(lexer, temp, &data);
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
			if (ft_heredoc_shell(lexer, temp))
				return (NULL);
		}
		else
			temp = ft_parsing_token(lexer, temp, &data, &i);
		lexer = lexer->next;
	}
	return (head);
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
	{
		data->token_found = lexer->token;
		temp->in = data->token_found;
	}
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

int	ft_heredoc_shell(t_lexer *lexer, t_cmd *temp)
{
	int	pid;
	int	fd[2];
	int	status;

	status = 0;
	signal(SIGINT, SIG_IGN);
	pipe(fd);
	pid = fork();
	if (pid == 0)
		ft_heredoc_child(lexer, fd);
	else
	{
		close(fd[1]);
		wait(&status);
		if (status != 0)
			return (status);
		ft_heredoc_parent(temp, fd);
		close(fd[0]);
	}
	return (status);
}

void	ft_heredoc_child(t_lexer *lexer, int *fd)
{
	t_parser	data;

	close(fd[0]);
	while (TRUE)
	{
		signal(SIGINT, ft_signal_handler_heredoc);
		data.lessless = readline("> ");
		if (data.lessless == NULL)
			break ;
		if (ft_strcmp(data.lessless, lexer->args) == 0)
			break ;
		write(fd[1], data.lessless, ft_strlen(data.lessless));
		write(fd[1], "\n", 1);
		free(data.lessless);
	}
	close(fd[1]);
	exit(0);
}

void	ft_heredoc_parent(t_cmd *temp, int *fd)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	while (get_next_line(fd[0], &line) > 0)
	{
		if (line)
		{
			temp->heredoc = ft_realloc(temp->heredoc, i, i + 1);
			temp->heredoc[i++] = ft_strdup(line);
			free(line);
		}
		temp->heredoc = ft_realloc(temp->heredoc, i, i + 1);
		line = NULL;
	}
	if (line)
		free(line);
}
