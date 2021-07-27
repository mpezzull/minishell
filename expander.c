/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:48:21 by mpezzull          #+#    #+#             */
/*   Updated: 2021/07/27 15:11:08 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	return (NULL);
}

void	ft_expand_env(char	*env, char *value)
{
	while (*value)
		*(env++) = *(value++);
}

void    ft_expander(t_cmd *cmd, char** our_env)
{
	int		i;
	char	*pos_dollar;
	char	*pos_backslash;
	char	*env_value;
	int		len_cmd;

	i = 0;
	while (cmd)
	{
		while (cmd->args && cmd->args[i])
		{
			pos_backslash = ft_strchr(cmd->args[i], '\\');
			pos_dollar = ft_strchr(cmd->args[i], '$');
			if ((pos_backslash == NULL || (pos_backslash + 1 != pos_dollar))
				&& pos_dollar && pos_dollar + 1)
			{
				env_value = ft_getenv(pos_dollar + 1, our_env);
				len_cmd = ft_strlen(cmd->args[i]);
				printf("cmd->args prima: %s\n", cmd->args[i]);
				cmd->args[i] = ft_realloc_str(cmd->args[i],
						len_cmd, len_cmd + ft_strlen(env_value));
				ft_expand_env(ft_strchr(cmd->args[i], '$'), env_value);
				printf("cmd->args dopo: %s\n", cmd->args[i]);
			}
			i++;
		}
		cmd = cmd->next;
	}
}
