/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:48:21 by mpezzull          #+#    #+#             */
/*   Updated: 2021/10/18 17:33:53 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_expand_env(char	*env, char *value, int len_word)
{
	int		i;
	char	*cpy_env;

	i = 0;
	cpy_env = ft_strdup(env);
	while (i++ < len_word + 1)
		cpy_env++;
	while (*value)
		*(env++) = *(value++);
	while (*cpy_env)
	{
		*(env++) = *(cpy_env++);
		len_word--;
	}
	while (len_word-- > 0)
		*(env++) = 0;
	*(env++) = '\0';
}

void	ft_expander(t_cmd *cmd, char **our_env)
{
	int		i;

	while (cmd)
	{
		if (cmd->cmd)
		{
			cmd->cmd = ft_find_and_expand(cmd->cmd, our_env);
			cmd->cmd = ft_expand_builtin(cmd->cmd);
		}
		if (cmd->file_in)
			cmd->file_in = ft_find_and_expand(cmd->file_in, our_env);
		if (cmd->file_out)
			cmd->file_out = ft_find_and_expand(cmd->file_out, our_env);
		i = 0;
		while (cmd->args && cmd->args[i])
		{
			cmd->args[i] = ft_find_and_expand(cmd->args[i], our_env);
			if (i == 0)
				cmd->args[i] = ft_expand_builtin(cmd->args[i]);
			i++;
		}
		i = 0;
		while (cmd->heredoc && cmd->heredoc[i])
		{
			cmd->heredoc[i] = ft_find_and_expand(cmd->heredoc[i], our_env);
			i++;
		}
		cmd = cmd->next;
	}
}

char	*ft_expand_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
	{
		cmd = ft_realloc_str(cmd, 4, 14);
		cmd = ft_strcpy(cmd, "./bin/our_echo");
	}
	else if (!ft_strcmp(cmd, "env"))
	{
		cmd = ft_realloc_str(cmd, 3, 13);
		cmd = ft_strcpy(cmd, "./bin/our_env");
	}
	else if (!ft_strcmp(cmd, "pwd"))
	{
		cmd = ft_realloc_str(cmd, 3, 13);
		cmd = ft_strcpy(cmd, "./bin/our_pwd");
	}
	return (cmd);
}

char	*ft_find_and_expand(char *to_replace, char **our_env)
{
	char	*pos_dollar;
	char	*pos_backslash;
	char	*env_value;
	char	*word;
	int		len_cmd;

	pos_dollar = ft_strchr(to_replace, '$');
	pos_backslash = NULL;
	while (pos_dollar != NULL)
	{
		if (pos_dollar != to_replace && *(pos_dollar - 1) == '\\')
			pos_backslash = pos_dollar - 1;
		if (pos_dollar && pos_backslash == NULL && *(pos_dollar + 1))
		{
			if (!ft_strncmp(pos_dollar, "$?", 2))
			{
				env_value = ft_pipestatus(GET, 0);
				word = ft_strdup("$?");
				word++;
			}
			else
			{
				word = ft_extract_alnum(pos_dollar);
				if (*(word + 1))
					word++;
				env_value = ft_getenv(word, our_env);
			}
			len_cmd = ft_strlen(to_replace);
			to_replace = ft_realloc_str(to_replace,
					len_cmd, len_cmd + ft_strlen(env_value) - ft_strlen(word));
			ft_expand_env(ft_strchr(to_replace, '$'), env_value,
				ft_strlen(word));
			--word;
			ft_free_str(&word);
			ft_free_str(&env_value);
			pos_dollar = ft_strchr(to_replace, '$');
		}
		else
			pos_dollar = NULL;
	}
/*	ft_delete_backslash() eventualmente gestire il backslash.
 *  Esempio echo "$PATH ciao \\$USER"
*/
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
