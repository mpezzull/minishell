/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:47:27 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/20 18:54:37 by mpezzull         ###   ########.fr       */
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

		int i = 0;
		while (cmd)
		{
			int j = 0;
			printf("---------------	%d ----------------\n", i++);
			printf("cmd:     %s\n", cmd->cmd);
			while (cmd->args && cmd->args[j])
			{
				printf("args[%i]: %s\n", j, cmd->args[j]);
				j++;
			}
			if (cmd->out)
				printf("out: %d\n", cmd->out);
			if (cmd->file_out)
				printf("file_out: %s\n", cmd->file_out);
			if (cmd->in)
				printf("in: %d\n", cmd->in);
			if (cmd->file_in)
				printf("file_in: %s\n", cmd->file_in);
			printf("cmd_next:  %x\n", (unsigned int)cmd->next);
			cmd = cmd->next;
		}

		free(cmd_line);
	}
	free(prompt);
	return (0);
}

void	ft_error(char *strerror, int nbr)
{
	printf("%s\n", strerror);
	exit(nbr);
}
