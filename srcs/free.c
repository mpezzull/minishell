/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:34:05 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/21 00:01:47 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	t_lexer	*temp;
	t_lexer	*temp_next;

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
	t_free_temp	temp;

	temp.temp = *cmd;
	while (temp.temp)
	{
		temp.temp_next = temp.temp->next;
		if (temp.temp->cmd)
			free(temp.temp->cmd);
		if (temp.temp->file_in)
			free(temp.temp->file_in);
		if (temp.temp->file_out)
			free(temp.temp->file_out);
		temp.to_free = temp.temp->args;
		while (*(temp.temp->args))
			free(*(temp.temp->args++));
		if (temp.to_free)
			free(temp.to_free);
		temp.to_free = temp.temp->heredoc;
		while (*(temp.temp->heredoc))
			free(*(temp.temp->heredoc++));
		if (temp.to_free)
			free(temp.to_free);
		free(temp.temp);
		temp.temp = temp.temp_next;
	}
}
