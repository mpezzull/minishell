/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:27:15 by mpezzull          #+#    #+#             */
/*   Updated: 2021/10/06 18:35:50 by mpezzull         ###   ########.fr       */
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