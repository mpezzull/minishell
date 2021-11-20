/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:48:21 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/20 04:47:05 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_expand_env(char	*env, char *value, int len_word)
{
	int		i;
	char	*cpy_env;
	char	*to_free;

	i = 0;
	cpy_env = ft_strdup(env);
	to_free = cpy_env;
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
	if (to_free)
		free(to_free);
}

void	ft_expander(t_cmd *cmd, char **our_env)
{
	while (cmd)
	{
		if (cmd->cmd)
		{
			cmd->cmd = ft_find_and_expand(cmd->cmd, our_env);
			ft_expand_builtin(cmd);
		}
		if (cmd->file_in)
			cmd->file_in = ft_find_and_expand(cmd->file_in, our_env);
		if (cmd->file_out)
			cmd->file_out = ft_find_and_expand(cmd->file_out, our_env);
		ft_expander_str(cmd->args, our_env);
		ft_expander_str(cmd->heredoc, our_env);
		cmd = cmd->next;
	}
}

void	ft_expander_str(char **str, char **our_env)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		str[i] = ft_find_and_expand(str[i], our_env);
		i++;
	}
}

void	ft_expand_builtin(t_cmd *cmd)
{
	if (cmd)
	{
		if (!ft_strcmp(ft_strlowcase(cmd->cmd), "echo"))
		{
			cmd->cmd = ft_realloc_str(cmd->cmd, 4, 14);
			cmd->cmd = ft_strcpy(cmd->cmd, "our_echo");
			cmd->args[0] = ft_strcpy(cmd->args[0], "our_echo");
		}
		else if (!ft_strcmp(ft_strlowcase(cmd->cmd), "env"))
		{
			cmd->cmd = ft_realloc_str(cmd->cmd, 3, 13);
			cmd->cmd = ft_strcpy(cmd->cmd, "our_env");
			cmd->args[0] = ft_strcpy(cmd->args[0], "our_env");
		}
		else if (!ft_strcmp(ft_strlowcase(cmd->cmd), "pwd"))
		{
			cmd->cmd = ft_realloc_str(cmd->cmd, 3, 13);
			cmd->cmd = ft_strcpy(cmd->cmd, "our_pwd");
			cmd->args[0] = ft_strcpy(cmd->args[0], "our_pwd");
		}
	}
}

char	*ft_find_and_expand(char *to_replace, char **our_env)
{
	char	*pos_dollar;
	char	*pos_backslash;
	char	*env_value;
	char	*word;
	int		len_cmd;
	int		to_skip;

	pos_dollar = ft_strchr(to_replace, '$');
	pos_backslash = NULL;
	while (pos_dollar != NULL)
	{
		if (pos_dollar != to_replace && *(pos_dollar - 1) == '\\')
		{
			pos_backslash = pos_dollar - 1;
			pos_backslash[0] = 21;
		}
		else if (pos_dollar != to_replace && *(pos_dollar - 1) == 21)
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
				if (!ft_strcmp(word, "$"))
				{
					env_value = ft_strdup("$$");
					env_value[0] = 21;
					word++;
				}
				else
					env_value = ft_getenv(++word, our_env);
			}
			len_cmd = ft_strlen(to_replace);
			to_skip = (pos_dollar - to_replace);
			to_replace = ft_realloc_str(to_replace,
					len_cmd, len_cmd + ft_strlen(env_value) - ft_strlen(word));
			pos_dollar = ft_strchr(to_replace + to_skip, '$');
			ft_expand_env(pos_dollar, env_value, ft_strlen(word));
			--word;
			ft_free_str(&word);
			ft_free_str(&env_value);
			pos_dollar = ft_strchr(to_replace + (pos_dollar - to_replace) + 1, '$');
			pos_backslash = NULL;
		}
		else
		{
			pos_dollar = ft_strchr( to_replace + (pos_dollar - to_replace) + 1, '$');
			pos_backslash = NULL;
		}
	}
	ft_delete_backslash(to_replace);
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
