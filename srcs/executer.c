/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:31:46 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/20 22:36:52 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_executer(t_cmd *cmd, char **our_env)
{
	t_data		data;
	char		**our_builtin;

	data.com_matrix = NULL;
	data.path = NULL;
	data.fd_out = 0;
	data.save_stdout = 1;
	signal(SIGINT, ft_signal_handler_executer);
	signal(SIGQUIT, SIG_IGN);
	if (cmd && !ft_strcmp(cmd->cmd, "exit") && !cmd->next)
		ft_exit(NULL, NULL, 1);
	while (cmd)
	{
		our_builtin = ft_our_builtin(cmd, our_env);
		if (!our_builtin)
			ft_executer_core(cmd, &data, our_env);
		else
			our_env = our_builtin;
		cmd = cmd->next;
	}
	return (our_env);
}

void	ft_executer_core(t_cmd *cmd, t_data *data, char **our_env)
{
	int	pid;

	data->com_matrix = cp_str_array(cmd->args);
	if (pipe(data->fd_pipe) == -1)
		ft_error("Error pipe", 1);
	pid = fork();
	if (pid == -1)
		ft_error("Error fork", 1);
	else if (pid == 0)
		ft_executer_child(cmd, data, our_env);
	else
		ft_execute_parent(cmd, data, pid);
	ft_free_env(data->com_matrix);
	free(data->com_matrix);
}

void	ft_lessless(t_cmd *cmd, t_data *data)
{
	int	i;

	i = 0;
	if (pipe(data->pipe_lessless) == -1)
		ft_error("Error pipe", 1);
	while (cmd->heredoc && cmd->heredoc[i])
	{
		write(data->pipe_lessless[1], cmd->heredoc[i],
			ft_strlen(cmd->heredoc[i]));
		write(data->pipe_lessless[1], "\n", 1);
		i++;
	}
	close(data->pipe_lessless[1]);
	if (dup2(data->pipe_lessless[0], 0) < 0)
		ft_error("Error file descriptor", 1);
	close(data->pipe_lessless[0]);
}

void	ft_executer_child(t_cmd *cmd, t_data *data, char **our_env)
{
	if (cmd->out != DEFAULT)
	{
		close(data->fd_pipe[0]);
		if (dup2(data->fd_pipe[1], 1) < 0)
			ft_error("Error file descriptor 1", 1);
		write(data->fd_pipe[1], "$", 1);
		close(data->fd_pipe[1]);
	}
	if (cmd->in == LESS)
		ft_less(cmd, data);
	else if (cmd->in == LESSLESS)
		ft_lessless(cmd, data);
	else if (data->fd_out != 0)
	{
		data->fd_in = data->fd_out;
		data->fd_out = 0;
		if (data->fd_in < 0)
			ft_error("Error file descriptor 2", 1);
		if (dup2(data->fd_in, 0) < 0)
			ft_error("Error file descriptor 3", 1);
		close(data->fd_in);
	}
	ft_do_execve(cmd->cmd, data, our_env);
}

void	ft_execute_parent(t_cmd *cmd, t_data *data, int pid)
{
	int		status;
	int		pipe_size;
	char	buf;

	status = 0;
	ft_sleep(15);
	close(data->fd_pipe[1]);
	read(data->fd_pipe[0], &buf, 1);
	ioctl(data->fd_pipe[0], FIONREAD, &pipe_size);
	if (pipe_size > 65530)
		waitpid(pid, &status, WSTOPPED);
	else
		waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		ft_pipestatus(SET, WEXITSTATUS(status));
	else
		ft_pipestatus(SET, 0);
	if (cmd->out == GREAT || cmd->out == GREATGREAT)
		ft_greats(cmd, data);
	else if (cmd->out == PIPE)
		data->fd_out = data->fd_pipe[0];
	else
		ft_print_output(data, cmd);
}
