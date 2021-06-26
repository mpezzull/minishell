/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assokenay <assokenay@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:47:27 by assokenay         #+#    #+#             */
/*   Updated: 2021/06/26 18:32:51 by assokenay        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char	*token;
	char	*prompt;
	char	*temp;

	printf("\n\n\t\t\033[1mWelcome in the worst minishell of the world!\n\n");
	temp = ft_strjoin(argv[0], ">$ \033[0m");
	prompt = ft_strjoin("\033[1;35m", temp);
	free(temp);
	if (argc != 1)
		return (1);
	token = readline(prompt);
	ft_parsing(token);

	free(prompt);
	free(token);
}

t_instr	*ft_parsing(char *token)
{
	t_instr	*instr;
	char	**splitted;

	if (!token)
		ft_error("invalid token", 1);
	splitted = ft_split(token, ' ');
	if (!ft_strcmp(splitted[0], "echo"))
		instr = ft_echo(token, splitted);
	return (instr);
}

void	ft_error(char *strerror, int nbr)
{
	printf("%s\n", strerror);
	exit(nbr);
}

t_instr *init_instr(void)
{
	t_instr	*instr;

	instr = (t_instr *)malloc(sizeof(t_instr));
	if (!instr)
		ft_error(strerror(errno), errno);
	instr->flag = NULL;
	return (instr);
}

void	ft_init_args(t_instr *instr, int num_args)
{
	instr->args = (char **)malloc(sizeof(char *) * (num_args + 1));
	if (!instr->args)
		ft_error(strerror(errno), errno);
}

int	ft_count_chr(char *str, char c)
{
	int i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
		if (str[i++] == c)
			res++;
	return (res);
}

int	ft_count_words(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
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
