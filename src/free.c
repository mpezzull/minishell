/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:34:05 by mpezzull          #+#    #+#             */
/*   Updated: 2021/10/14 19:00:39 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void	ft_free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
