/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:34:05 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/21 17:23:39 by mde-rosa         ###   ########.fr       */
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
	t_free_temp	s_free;

	s_free.temp = *cmd;
	while (s_free.temp)
	{
		s_free.temp_next = s_free.temp->next;
		if (s_free.temp->cmd)
			free(s_free.temp->cmd);
		if (s_free.temp->file_in)
			free(s_free.temp->file_in);
		s_free.to_free = s_free.temp->file_out;
		while (s_free.temp->file_out && *(s_free.temp->file_out))
			free(*(s_free.temp->file_out++));
		if (s_free.to_free)
			free(s_free.to_free);
		ft_cmdclear_two(&s_free);
		s_free.temp = s_free.temp_next;
	}
}

void	ft_cmdclear_two(t_free_temp *s_free)
{
	s_free->to_free = s_free->temp->args;
	while (s_free->temp->args && *(s_free->temp->args))
		free(*(s_free->temp->args++));
	if (s_free->to_free)
		free(s_free->to_free);
	s_free->to_free = s_free->temp->heredoc;
	while (s_free->temp->heredoc && *(s_free->temp->heredoc))
		free(*(s_free->temp->heredoc++));
	if (s_free->to_free)
		free(s_free->to_free);
	free(s_free->temp);
}
