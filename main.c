/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:47:27 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/16 17:05:17 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_line;
	char	*prompt;
	char	*temp;
	t_cmd	*cmd;
	t_lexer	*lexer;

	if (argc != 1)
		ft_error("Launch with \"./minishell\"", 1);
	printf("\n\t\t\033[1mWelcome in the worst minishell of the world!\n\n \033[0m");
	temp = ft_strdup("@minishell:~$ ");
	prompt = ft_strjoin(getenv("USER"), temp);
	free(temp);
	while (1)
	{
		cmd_line = readline(prompt);
		if (ft_strcmp(cmd_line, "exit") == 0)
			break ;
		add_history(cmd_line);
//		lexer = ft_lexer(cmd_line);
//		cmd = ft_parsing(lexer);
//		ft_expander(cmd);
//		ft_executer(cmd);
		free(cmd_line);
	}
	free(prompt);
}

/*t_cmd	*ft_parsing(char *cmd_line)
{
	t_cmd	*instr;
	char	**splitted;

	if (!cmd_line)
		ft_error("invalid cmd_line", 1);
	splitted = ft_split(cmd_line, ' ');
	if (!ft_strcmp(splitted[0], "echo"))
		instr = ft_echo(cmd_line, splitted);
	return (instr);
}
*/
void	ft_error(char *strerror, int nbr)
{
	printf("%s\n", strerror);
	exit(nbr);
}
