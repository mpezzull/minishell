/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:47:27 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/18 17:43:45 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_lexer(char *cmd_line);

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_line;
	char	*prompt;
	char	*temp;
	t_cmd	*cmd;
	t_lexer	*lexer;

	if (argc != 1)
		ft_error("Launch with \"./minishell\"", 1);
	printf("\n\t\t\033[1mWelcome in the worst minishell of the world!\n\n\033[0m");
	temp = ft_strdup("@minishell:~$ ");
	prompt = ft_strjoin(getenv("USER"), temp);
	free(temp);
	while (1)
	{
		cmd_line = readline(prompt);
		if (ft_strcmp(cmd_line, "exit") == 0)
			break ;
		add_history(cmd_line);
		lexer = ft_lexer(cmd_line);
		cmd = ft_parsing(lexer);
//		ft_expander(cmd);
//		ft_executer(cmd);
		free(cmd_line);
	}
	free(prompt);
	while (lexer)
	{
		printf("%s %d\n", lexer->args, lexer->token);
		printf("%s\n", cmd->cmd);
		if (cmd->args)
			printf("%s\n", cmd->args[0]);
		lexer = lexer->next;
//		cmd = cmd->next;
	}
	return (0);
}

void	ft_error(char *strerror, int nbr)
{
	printf("%s\n", strerror);
	exit(nbr);
}
