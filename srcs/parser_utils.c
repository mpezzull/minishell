/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:00:52 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/17 21:32:44 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd	*ft_cmd_new(int n_args)
{
	t_cmd	*cmd;

	cmd = (void *)ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		ft_error(strerror(errno), errno);
	cmd->args = (char **)ft_calloc((n_args + 1), sizeof(char *));
	if (!cmd->args)
		ft_error(strerror(errno), errno);
	cmd->heredoc = (char **)ft_calloc(1, sizeof(char *));
	if (!cmd->heredoc)
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

int		ft_check_double_token(t_lexer *lexer)
{
	static int		prev;
	int				curr;

	curr = lexer->token;
	if (prev != DEFAULT && prev != WORD && prev != PIPE && curr != WORD)
	{
		printf("minishell: syntax error near unexpected token %s\n",
			lexer->args);
		ft_pipestatus(SET, SYNTAX_ERROR);
		return (1);
	}
	prev = curr;
	return (0);
}

void	ft_signal_handler_heredoc(int sig_num)
{
	char	*str;
	char	*new_line_buffer;

	if (sig_num == SIGINT)
	{
		str = rl_line_buffer;
		new_line_buffer = ft_strjoin(str, "  ");
		rl_on_new_line();
		rl_replace_line(new_line_buffer, 1);
		rl_redisplay();
		write(1, "\n", 1);
		exit(SIGINT);
	}
}