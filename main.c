/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:47:27 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/14 15:58:46 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*token;
	char	*prompt;
	char	*temp;
	t_instr	*instr;

	if (argc != 1)
		ft_error("Launch with \"./minishell\"", 1);
	printf("\n\t\t\033[1mWelcome in the worst minishell of the world!\n\n \033[0m");
	temp = ft_strjoin(argv[0], ">$ ");
	prompt = ft_strjoin(" ", temp);
	free(temp);
	while (1)
	{
		token = readline(prompt);
		if (ft_strcmp(token, "exit") == 0)
			break ;
		if (!ft_strcmp(token, "exec"))
			execve("/bin/sh", argv, envp);
		add_history(token);
		instr = ft_parsing(token);
		temp = ft_strjoin("./bin/", instr->cmd);
		execve(temp, instr->args, envp);
		free(temp);
	}
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
