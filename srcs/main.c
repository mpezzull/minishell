/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:47:27 by assokenay         #+#    #+#             */
/*   Updated: 2021/11/19 18:33:18 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_signal_handler(int sig_num)
{
	char 	*str;
	char	*new_line_buffer;

	if (sig_num == SIGINT)
	{
		str = rl_line_buffer;
		new_line_buffer = ft_strjoin(str, "  ");
		rl_on_new_line();
		rl_replace_line(new_line_buffer, 1);
		rl_redisplay();
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		free(new_line_buffer);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_line;
	char	*prompt;
	char	*user;
	char	**our_env;
	t_cmd	*cmd;
	t_lexer	*lexer;

	argv = &(*argv);
	our_env = envp;
	if (!our_env)
		our_env = envp;
	if (argc != 1)
		ft_error("Launch with \"./minishell\"", 1);
	our_env = cp_str_array(envp);
	if (!our_env)
		ft_error("minishell: system error", 1);
	printf("\n\t\t\033[1mWelcome in the worst minishell of the world!\n\n\033[0m");
	ft_error("init fd", 0);
	while (TRUE)
	{
		signal(SIGINT, ft_signal_handler);
		signal(SIGQUIT, SIG_IGN);
		user = ft_getenv("USER", our_env);
		prompt = ft_strjoin(user, "@minishell:~$ ");
		free(user);
		cmd_line = readline(prompt);
		free(prompt);
		if (cmd_line == NULL) // ctrl + D
		{
			ft_free_env(our_env);
			free(our_env);
			write(1, "exit\n", 5);
			break ;
		}
		add_history(cmd_line);
		lexer = ft_lexer(cmd_line);
		free(cmd_line);
//		ft_print_lexer(lexer);
		cmd = ft_parsing(lexer);
		ft_lexerclear(&lexer);
		ft_expander(cmd, our_env);
//		ft_print_cmd(cmd);
		our_env = ft_executer(cmd, our_env);
		ft_cmdclear(&cmd);
		cmd = NULL;
	}
	return (0);
}

void	ft_error(char *strerror, int nbr)
{
	static int	fd;

	if (nbr == 0 && fd == 0)
		fd = dup(1);
	else
	{
		dup2(fd, 1);
		printf("%s\n", strerror);
		exit(nbr);
	}
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

void	ft_print_cmd(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd)
	{
		j = 0;
		printf("---------------	%d ----------------\n", i++);
		printf("cmd:     %s\n", cmd->cmd);
		while (cmd->args && cmd->args[j])
		{
			printf("args[%i]: %s\n", j, cmd->args[j]);
			j++;
		}
		j = 0;
		while (cmd->heredoc && cmd->heredoc[j])
		{
			printf("heredoc[%i]: %s\n", j, cmd->heredoc[j]);
			j++;
		}
		printf("out: %d\n", cmd->out);
		if (cmd->file_out)
			printf("file_out: %s\n", cmd->file_out);
		printf("in: %d\n", cmd->in);
		if (cmd->file_in)
			printf("file_in: %s\n", cmd->file_in);
		printf("cmd_next:  %lx\n", (unsigned long)cmd->next);
		cmd = cmd->next;
	}
}
