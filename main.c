/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assokenay <assokenay@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:47:27 by assokenay         #+#    #+#             */
/*   Updated: 2021/06/26 19:11:52 by assokenay        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char	*token;
	char	*prompt;
	char	*temp;

	if (argc != 1)
		ft_error("Launch with \"./minishell\"", 1);
	printf("\n\n\t\t\033[1mWelcome in the worst minishell of the world!\n\n");
	temp = ft_strjoin(argv[0], ">$ \033[0m");
	prompt = ft_strjoin("\033[1;35m", temp);
	free(temp);
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

