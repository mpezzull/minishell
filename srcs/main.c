/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:47:27 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/11/21 04:37:45 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_line;
	char	**our_env;
	t_cmd	*cmd;
	t_lexer	*lexer;

	our_env = ft_init_minishell(envp, argv, argc);
	while (TRUE)
	{
		signal(SIGINT, ft_signal_handler);
		signal(SIGQUIT, SIG_IGN);
		cmd_line = readline("minishell:~$ ");
		if (ft_ctrl_d(cmd_line, our_env))
			break ;
		add_history(cmd_line);
		lexer = ft_lexer(cmd_line);
		free(cmd_line);
		cmd = ft_parsing(lexer);
		ft_lexerclear(&lexer);
		ft_expander(cmd, our_env);
		our_env = ft_executer(cmd, our_env);
		ft_cmdclear(&cmd);
		cmd = NULL;
	}
	return (0);
}

void	ft_signal_handler(int sig_num)
{
	char	*str;
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

char	**ft_init_minishell(char **envp, char **argv, int argc)
{
	char	**our_env;

	argv = &(*argv);
	our_env = envp;
	if (!our_env)
		our_env = envp;
	if (argc != 1)
		ft_error("Launch with \"./minishell\"", 1);
	our_env = cp_str_array(envp);
	our_env = ft_update_path(our_env);
	if (!our_env)
		ft_error("minishell: system error", 1);
	ft_error("init fd", 0);
	return (our_env);
}

int	ft_ctrl_d(char *cmd_line, char **our_env)
{
	if (cmd_line == NULL)
	{
		ft_free_env(our_env);
		free(our_env);
		write(1, "exit\n", 5);
		rl_clear_history();
		return (1);
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
