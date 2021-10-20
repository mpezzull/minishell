/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:34:05 by mpezzull          #+#    #+#             */
/*   Updated: 2021/10/20 21:00:57 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free_cmd(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->cmd)
			free(cmd->cmd);
		if (cmd->file_in)
			free(cmd->file_in);
		if (cmd->file_out)
			free(cmd->file_out);
		while (*(cmd->args))
			free(*(cmd->args++));
		while (*(cmd->heredoc))
			free(*(cmd->heredoc++));
		cmd = cmd->next;
	}
}

void	ft_free_lexer(t_lexer *lexer)
{
	while (lexer)
	{
		if (lexer->args)
			free(lexer->args);
		lexer = lexer->next;
	}
}

void	ft_free_env(char **our_env)
{
	while (*our_env)
		free(*(our_env++));
}

void	ft_free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	ft_lexerclear(t_lexer **lexer)
{
	t_lexer *temp;
	t_lexer *temp_next;

	temp = *lexer;
	while (temp)
	{
		temp_next = temp->next;
		if (temp->args)
			free(temp->args);
		free(temp);
		temp = temp_next;
	}
	*lexer = NULL;
}

void	ft_cmdclear(t_cmd **cmd)
{
	t_cmd	*temp;
	t_cmd	*temp_next;
	char	**to_free;

	temp = *cmd;
	while (temp)
	{
		temp_next = temp->next;
		if (temp->cmd)
			free(temp->cmd);
		if (temp->file_in)
			free(temp->file_in);
		if (temp->file_out)
			free(temp->file_out);
		to_free = temp->args;
		while (*(temp->args))
			free(*(temp->args++));
		if (to_free)
			free(to_free);
		to_free = temp->heredoc;
		while (*(temp->heredoc))
			free(*(temp->heredoc++));
		if (to_free)
			free(to_free);
		free(temp);
		temp = temp_next;
	}
	*cmd = NULL;
}