/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:00:52 by mpezzull          #+#    #+#             */
/*   Updated: 2021/07/22 16:03:33 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_realloc(char	**ptr, int cur_size, int new_size)
{
	char	**new_ptr;

	if (ptr == 0)
	{
		ptr = (char **)malloc(sizeof(char *) * (new_size + 1));
		if (!ptr)
			ft_error(strerror(errno), errno);
		return (ptr);
	}
	if (new_size <= cur_size)
		return (ptr);
	new_ptr = (char **)malloc(sizeof(char *) * (new_size + 1));
	if (!new_ptr)
		ft_error(strerror(errno), errno);
	ft_memcpy(new_ptr, ptr, cur_size * sizeof(char *));
	free(ptr);
	return (new_ptr);
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