/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:48:21 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/21 15:59:07 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_expander(t_cmd *cmd, char **our_env)
{
	int	i;

	i = 0;
	while (cmd)
	{
		if (cmd->cmd)
		{
			cmd->cmd = ft_find_and_expand(cmd->cmd, our_env);
			ft_expand_builtin(cmd);
		}
		if (cmd->file_in)
			cmd->file_in = ft_find_and_expand(cmd->file_in, our_env);
		while (cmd->file_out && cmd->file_out[i])
		{
			cmd->file_out[i] = ft_find_and_expand(cmd->file_out[i], our_env);
			i++;
		}
		ft_expander_str(cmd->args, our_env);
		ft_expander_str(cmd->heredoc, our_env);
		cmd = cmd->next;
	}
}

void	ft_expand_builtin(t_cmd *cmd)
{
	if (cmd)
	{
		if (!ft_strcmp_lowcase(cmd->cmd, "echo"))
		{
			cmd->cmd = ft_realloc_str(cmd->cmd, 4, 14);
			cmd->cmd = ft_strcpy(cmd->cmd, "our_echo");
			cmd->args[0] = ft_strcpy(cmd->args[0], "our_echo");
		}
		else if (!ft_strcmp_lowcase(cmd->cmd, "env"))
		{
			cmd->cmd = ft_realloc_str(cmd->cmd, 3, 13);
			cmd->cmd = ft_strcpy(cmd->cmd, "our_env");
			cmd->args[0] = ft_strcpy(cmd->args[0], "our_env");
		}
		else if (!ft_strcmp_lowcase(cmd->cmd, "pwd"))
		{
			cmd->cmd = ft_realloc_str(cmd->cmd, 3, 13);
			cmd->cmd = ft_strcpy(cmd->cmd, "our_pwd");
			cmd->args[0] = ft_strcpy(cmd->args[0], "our_pwd");
		}
	}
}

char	*ft_find_and_expand(char *to_replace, char **our_env)
{
	t_expander	exp;

	exp.pos_dollar = ft_strchr(to_replace, '$');
	exp.pos_backslash = NULL;
	while (exp.pos_dollar != NULL)
	{
		if (exp.pos_dollar != to_replace && *(exp.pos_dollar - 1) == '\\')
		{
			exp.pos_backslash = exp.pos_dollar - 1;
			exp.pos_backslash[0] = 21;
		}
		else if (exp.pos_dollar != to_replace && *(exp.pos_dollar - 1) == 21)
			exp.pos_backslash = exp.pos_dollar - 1;
		if (exp.pos_dollar && exp.pos_backslash == NULL && *(exp.pos_dollar
				+ 1))
			to_replace = ft_expander_core(&exp, to_replace, our_env);
		else
		{
			exp.pos_dollar = ft_strchr(to_replace
					+ (exp.pos_dollar - to_replace) + 1, '$');
			exp.pos_backslash = NULL;
		}
	}
	ft_delete_backslash(to_replace);
	return (to_replace);
}

char	*ft_expander_core(t_expander *exp, char *to_replace, char **our_env)
{
	int	len_cmd;
	int	to_skip;

	exp->word = ft_get_value(exp, our_env);
	len_cmd = ft_strlen(to_replace);
	to_skip = (exp->pos_dollar - to_replace);
	to_replace = ft_realloc_str(to_replace, len_cmd,
			len_cmd + ft_strlen(exp->env_value) - ft_strlen(exp->word));
	exp->pos_dollar = ft_strchr(to_replace + to_skip, '$');
	ft_expand_env(exp->pos_dollar, exp->env_value, ft_strlen(exp->word));
	--exp->word;
	ft_free_str(&exp->word);
	ft_free_str(&exp->env_value);
	exp->pos_dollar = ft_strchr(to_replace + (exp->pos_dollar - to_replace) + 1,
			'$');
	exp->pos_backslash = NULL;
	return (to_replace);
}

char	*ft_getenv(char *name, char **env)
{
	int		len;
	int		i;
	char	*np;
	char	*cp;

	np = name;
	while (*np && *np != '=')
		++np;
	len = np - name;
	cp = *env;
	while (cp != NULL)
	{
		np = name;
		i = len;
		while (i && *cp)
		{
			if (*cp++ != *np++)
				break ;
			i--;
		}
		if (i == 0 && *cp++ == '=')
			return (ft_strdup(cp));
		cp = *(++env);
	}
	return (ft_strdup(""));
}
