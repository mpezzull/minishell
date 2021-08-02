/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:05:58 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/29 18:44:42 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_echo(char *token, char **splitted)
{
	t_cmd	*echo;
	int		d_quotes;
//	int		s_quotes;

	echo = init_cmd();
	echo->cmd = ft_strdup("ft_echo");
	if (splitted[1] && !ft_strcmp(splitted[1], "-n"))
		echo->flag = ft_strdup(splitted[1]);
	d_quotes = ft_count_chr(token, '\"');
	if (d_quotes == 0)
		ft_zero_dquotes(echo, splitted);
//	s_quotes = ft_count_chr(token, '\'');
//	printf("cmd %s\nflag %s\nargs0 %s\nargs1 %s\n", echo->cmd, echo->flag, echo->args[0], echo->args[1]);
//	fflush(stdout);
	return (echo);
}

void	ft_zero_dquotes(t_cmd *echo, char **splitted)
{
	int	i;
//	int	j;
	int	num_words;

	i = 0;
	num_words = ft_count_words(splitted);
	ft_init_args(echo, num_words);
	echo->args[i++] = ft_strdup("ft_echo");
	while (splitted[i])
	{
		echo->args[i] = ft_strdup(splitted[i]);
		i++;
	}
}
