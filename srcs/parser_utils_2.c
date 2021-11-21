/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:27:15 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/21 04:07:19 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_parsing_pipe(t_lexer *lexer, t_cmd *temp, t_parser *data, int *i)
{
	if (!temp->cmd)
		temp->cmd = ft_strdup(lexer->args);
	temp->args = ft_realloc(temp->args, *i, *i + 1);
	temp->args[(*i)++] = ft_strdup(lexer->args);
	data->token_found = 0;
}

void	ft_parsing_greats(t_lexer *lexer, t_cmd *temp, t_parser *data)
{
	temp->file_out = ft_strdup(lexer->args);
	temp->out = data->token_found;
	data->token_found = 0;
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
	rl_clear_history();
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
