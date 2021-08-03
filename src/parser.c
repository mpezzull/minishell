/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:42:27 by mpezzull          #+#    #+#             */
/*   Updated: 2021/08/03 18:16:56 by mpezzull         ###   ########.fr       */
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
		ft_check_double_token(lexer);
		if (!temp)
		{
			temp = ft_cmd_new(0);
			ft_cmdadd_back(&head, temp);
		}
		if (data.token_found == PIPE && lexer->token == WORD)
		{
			if (!temp->cmd)
				temp->cmd = ft_strdup(lexer->args);
			temp->args = ft_realloc(temp->args, i, i + 1);
			temp->args[i++] = ft_strdup(lexer->args);
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
			if (lexer->token == WORD && data.token_found != PIPE)
			{
				if (!temp->cmd)
					temp->cmd = ft_strdup(lexer->args);
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
	int			pid;
	int			fd[2];

	signal(SIGINT, SIG_IGN);
	pipe(fd);
	pid = fork();
	if (pid == 0)
		ft_heredoc_child(lexer, fd);
	else
	{
		wait(NULL);
		close(fd[1]);
		write(fd[1], "\0", 1);
		ft_heredoc_parent(temp, fd, *i);
		close(fd[0]);
	}
}

void	ft_heredoc_child(t_lexer *lexer, int *fd)
{
	t_parser	data;

	close(fd[0]);
	while (TRUE)
	{
		signal(SIGINT, SIG_DFL);
		data.lessless = readline("> ");
		if (ft_strcmp(data.lessless, lexer->args) == 0)
			break ;
		write(fd[1], data.lessless, ft_strlen(data.lessless));
		write(fd[1], "\n", 1);
	}
	write(fd[1], "\0", 1);
	close(fd[1]);
	exit(0);
}

void	ft_heredoc_parent(t_cmd	*temp, int *fd, int i)
{
	int		j;
	char	*line;

	line = NULL;
	j = 0;
	while (j != -5)
	{
		line = NULL;
		j = get_next_line(fd[0], &line);
		if (line)
		{
			temp->args = ft_realloc(temp->args, i, i + 1);
			temp->args[i++] = ft_strdup(line);
		}
	}
}
