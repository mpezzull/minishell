/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assokenay <assokenay@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:05:58 by assokenay         #+#    #+#             */
/*   Updated: 2021/06/26 19:11:50 by assokenay        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_instr	*ft_echo(char *token, char **splitted)
{
	t_instr	*echo;
	int		d_quotes;
//	int		s_quotes;

	echo = init_instr();
	echo->cmd = ft_strdup(splitted[0]);
	if (!ft_strcmp(splitted[1], "-n"))
		echo->flag = ft_strdup(splitted[1]);
	d_quotes = ft_count_chr(token, '\"');
	if (d_quotes == 0)
		ft_zero_dquotes(echo, splitted);
//	s_quotes = ft_count_chr(token, '\'');
printf("cmd %s\nflag %s\nargs0 %s\nargs1 %s\n", echo->cmd, echo->flag, echo->args[0], echo->args[1]);
	fflush(stdout);
	return (echo);
}

void	ft_zero_dquotes(t_instr *echo, char **splitted)
{
	int	i;
	int	j;
	int	num_words;

	j = 0;
	if (echo->flag)
		i = 2;
	else
		i = 1;
	num_words = ft_count_words(splitted);
	ft_init_args(echo, num_words);
	while (splitted[i])
		echo->args[j++] = ft_strdup(splitted[i++]);
}
