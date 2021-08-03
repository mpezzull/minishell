/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:47:27 by assokenay         #+#    #+#             */
/*   Updated: 2021/08/03 02:43:01 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_line;
	char	*prompt;
	char	*temp;
	char	**our_env;
//	t_cmd	*cmd;
	t_lexer	*lexer;

	char deleteme = argv[0][0];
	if (!deleteme)
		deleteme = argv[0][0];
	our_env = envp;
	if (!our_env)
		our_env = envp;
	if (argc != 1)
		ft_error("Launch with \"./minishell\"", 1);
/*	printf("\n");
	printf("\t\t\t──────────────────────────────────\n");
	printf("\t\t\t────────────██████████────────────\n");
	printf("\t\t\t────────███████████████████───────\n");
	printf("\t\t\t──────███████████████████████─────\n");
	printf("\t\t\t────██████████████████████████────\n");
	printf("\t\t\t───█████████████▀──────────▀███───\n");
	printf("\t\t\t──█████████████──────────────███──\n");
	printf("\t\t\t─████████████────────────────████─\n");
	printf("\t\t\t─██████████───────────────────███─\n");
	printf("\t\t\t██████████▀───────────────────████\n");
	printf("\t\t\t████████▀─────────────────────████\n");
	printf("\t\t\t██████▀────────────────────────███\n");
	printf("\t\t\t█████──▄▀▀▀▀▀▀▀▄────▄▀▀▀▀▀▀▀▄──███\n");
	printf("\t\t\t█████────▄▄▄▄▄────────▄▄▄▄▄────███\n");
	printf("\t\t\t█████──▄▀───▄██▄────▄▀───▄██▄──███\n");
	printf("\t\t\t█████──▀▄───▀▀█▀────▀▄───▀▀█▀──███\n");
	printf("\t\t\t█▀──█────▀▀▀▀▀────────▀▀▀▀▀────███\n");
	printf("\t\t\t█───█──────────────────────────█─█\n");
	printf("\t\t\t█────────────────────▄───────────█\n");
	printf("\t\t\t█───────────▄▀────────▀▄─────────█\n");
	printf("\t\t\t▀█─▄█───────▀▄─▀██──██───────────█\n");
	printf("\t\t\t─▀██────────────────────────────██\n");
	printf("\t\t\t──██────▄▀▀──────█─█──────▀▀▄──██─\n");
	printf("\t\t\t───█──────█▀▄────▀─▀────▄▀█────█──\n");
	printf("\t\t\t───█──────▀──▀▀▄▄▄▄▄▄▄▀▀──▀────█──\n");
	printf("\t\t\t───▀█─────────────────────────█▀──\n");
	printf("\t\t\t────▀█───────────────────────█▀───\n");
	printf("\t\t\t─────▀█─────────────────────█▀────\n");
	printf("\t\t\t──────▀█───────────────────█▀─────\n");
	printf("\t\t\t───────▀█─────────────────█▀──────\n");
	printf("\t\t\t────────▀█───▄───────▄───█▀───────\n");
	printf("\t\t\t─────────▀█▄──▀▄▄▄▄▄▀──▄█▀────────\n");
	printf("\t\t\t───────────▀▀█▄▄▄▄▄▄▄█▀▀──────────\n");
	printf("\n");
*/	printf("\n\t\t\033[1mWelcome in the worst minishell of the world!\n\n\033[0m");
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
		ft_print_lexer(lexer);
//		cmd = ft_parsing(lexer);
//		ft_expander(cmd);
//		ft_executer(cmd);
		free(cmd_line);
	}
	free(prompt);
	return (0);
}

t_cmd	*ft_parsing(char *cmd_line)
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

void	ft_error(char *strerror, int nbr)
{
	printf("%s\n", strerror);
	exit(nbr);
}

void	ft_print_lexer(t_lexer *lexer)
{
	int	i;

	i = 0;
	printf("---------ft_lexer-------------------\n #\targs\tTOKEN\n");
	while (lexer)
	{
		printf(" %d %10s\t", i++, lexer->args);
		if (lexer->token == GREAT)
			printf("%s\n", "GREAT");
		if (lexer->token == LESS)
			printf("%s\n", "LESS");
		if (lexer->token == GREATGREAT)
			printf("%s\n", "GREATGREAT");
		if (lexer->token == LESSLESS)
			printf("%s\n", "LESSLESS");
		if (lexer->token == PIPE)
			printf("%s\n", "PIPE");
		if (lexer->token == WORD)
			printf("%s\n", "WORD");
		fflush(stdout);
		lexer = lexer->next;
	}
	printf("---------ft_lexer-------------------\n");
}
