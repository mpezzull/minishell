/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:48:21 by mpezzull          #+#    #+#             */
/*   Updated: 2021/07/27 19:09:12 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expand_env(char	*env, char *value)
{
	while (*value)
		*(env++) = *(value++);
}

void	ft_expander(t_cmd *cmd, char **our_env)
{
	int		i;

	i = 0;
	while (cmd)
	{
		if (cmd->cmd)
			cmd->cmd = ft_find_and_expand(cmd->cmd, our_env);
		if (cmd->file_in)
			cmd->file_in = ft_find_and_expand(cmd->file_in, our_env);
		if (cmd->file_out)
			cmd->file_out = ft_find_and_expand(cmd->file_out, our_env);
		while (cmd->args && cmd->args[i])
		{
			cmd->args[i] = ft_find_and_expand(cmd->args[i], our_env);
			i++;
		}
		cmd = cmd->next;
	}
}

//per ora splitta solo sugli spazi, andrebbe fatto per ogni carattere non alfanumerico
char	*ft_find_and_expand(char *to_replace, char **our_env)
{
	char	*pos_dollar;
	char	*pos_backslash;
	char	*env_value;
	char	*word;
	int		len_cmd;

	pos_dollar = ft_strchr(to_replace, '$');
	while (pos_dollar != NULL)
	{
		pos_backslash = ft_strchr(to_replace, '\\');
		if (pos_dollar && (pos_backslash == NULL
				|| (pos_backslash + 1 != pos_dollar)) && pos_dollar + 1)
		{
			word = *ft_split(pos_dollar + 1, ' ');
			env_value = ft_getenv(word, our_env);
			len_cmd = ft_strlen(to_replace);
			to_replace = ft_realloc_str(to_replace,
					len_cmd, len_cmd + ft_strlen(env_value));
			ft_expand_env(ft_strchr(to_replace, '$'), env_value);
		}
		pos_dollar = ft_strchr(to_replace, '$');
	}
	return (to_replace);
}

char	*ft_getenv(char *name, char **env)
{
	int		len;
	int		i;
	char	*np;
	char	*cp;

	if (name == NULL || env == NULL)
		return (NULL);
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
			return (cp);
		cp = *(++env);
	}
	return (ft_strdup(""));
}