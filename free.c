/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:34:05 by mpezzull          #+#    #+#             */
/*   Updated: 2021/08/02 11:48:58 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(t_cmd *cmd/*, t_lexer *lexer*/)
{ 
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->file_in)
		free(cmd->file_in);
	if (cmd->file_out)
		free(cmd->file_out);
	while (cmd->args)
		free(*(cmd->args++));
}

void	ft_free_word(char **word)
{
	while (*word)
	{
		free(*word);
		*word = NULL;
		word++;
	}
}
