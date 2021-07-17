/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:42:27 by mpezzull          #+#    #+#             */
/*   Updated: 2021/07/17 17:30:42 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_parsing(t_lexer *lexer)
{
	t_cmd	*cmd;
	t_cmd	**first_cmd;
	int		new_cmd;
	int		n_args;
	int		i;

	new_cmd = 1;
	i = 0;
	first_cmd = &cmd;
	while (!lexer)
	{
		if (new_cmd)
		{
			n_args = ft_count_args(lexer);
			cmd = ft_cmd_new(n_args);
			ft_cmdadd_back(first_cmd, cmd);
			if (lexer->token == WORD)
				cmd->cmd = ft_strdup(lexer->args);
			new_cmd = 0;
		}
		else
		{
			if (lexer->token == WORD)
				cmd->args[i++] = ft_strdup(lexer->args);
		}
		lexer = lexer->next;
	}
	return (cmd);
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
	int	count;

	count = 0;
	if (!lexer)
		return (count);
	while (lexer->token != PIPE)
	{
		count++;
		lexer = lexer->next;
	}
	count--;
	return (count);
}
