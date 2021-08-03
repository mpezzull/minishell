/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:00:52 by mpezzull          #+#    #+#             */
/*   Updated: 2021/08/03 15:05:53 by mpezzull         ###   ########.fr       */
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
	cmd->next = NULL;
	cmd->flag = NULL;
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

void	ft_check_double_token(t_lexer *lexer)
{
	static int		prev;
	int				curr;

	curr = lexer->token;
	if (prev != DEFAULT && prev != WORD && prev != PIPE && curr != WORD)
		ft_error(ft_strjoin("minishell: syntax error near unexpected token ",
				lexer->args), SYNTAX_ERROR);
	prev = curr;
}