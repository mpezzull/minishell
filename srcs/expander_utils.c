/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:53:15 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/20 22:40:28 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_delete_backslash(char *to_replace)
{
	char	*backlash;

	backlash = ft_strchr(to_replace, 21);
	while (backlash)
	{
		if (*(backlash + 1) && *(backlash + 1) == '$')
		{
			ft_expand_env(backlash, "", 0);
			backlash = ft_strchr(backlash, 21);
		}
		else if (*(backlash + 1))
			backlash = ft_strchr(++backlash, 21);
		else
			break ;
	}
}

int	ft_strcmp_lowcase(char *str1, char *str2)
{
	char	*temp;
	char	*temp2;
	int		ret;

	ret = 0;
	temp = ft_strdup(str1);
	temp2 = ft_strlowcase(temp);
	ret = ft_strcmp(temp2, str2);
	free(temp);
	free(temp2);
	return (ret);
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

char	*ft_get_value(t_expander *exp, char **our_env)
{
	if (!ft_strncmp(exp->pos_dollar, "$?", 2))
	{
		exp->env_value = ft_pipestatus(GET, 0);
		exp->word = ft_strdup("$?");
		exp->word++;
	}
	else
	{
		exp->word = ft_extract_alnum(exp->pos_dollar);
		if (!ft_strcmp(exp->word, "$"))
		{
			exp->env_value = ft_strdup("$$");
			exp->env_value[0] = 21;
			exp->word++;
		}
		else
			exp->env_value = ft_getenv(++exp->word, our_env);
	}
	return (exp->word);
}
