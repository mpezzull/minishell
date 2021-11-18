/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:31:46 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/18 19:38:18 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_executer(t_cmd *cmd, char **our_env)
{
	t_data		data;
	int			pid;
	char		**our_builtin;

	data.com_matrix = NULL;
	data.path = NULL;
	data.fd_out = 0;
	data.save_stdout = 1;
	signal(SIGINT, ft_signal_handler_executer);
	signal(SIGQUIT, SIG_IGN);
	if (cmd && !ft_strcmp(cmd->cmd, "exit") && !cmd->next)
		ft_exit(NULL, NULL, 1);
	//contare quanti cmd ci sono
	while (cmd)
	{
		our_builtin = ft_our_builtin(cmd, our_env);
		if (!our_builtin)
		{
			data.com_matrix = cp_str_array(cmd->args);
			if (pipe(data.fd_pipe) == -1)
				ft_error("Error pipe", 1);
			pid = fork();
			if (pid == -1)
				ft_error("Error fork", 1);
			else if (pid == 0)
				ft_executer_child(cmd, &data, our_env);
			else
				ft_execute_parent(cmd, &data, pid);
			ft_free_env(data.com_matrix);
			free(data.com_matrix);
		}
		else
			our_env = our_builtin;
		cmd = cmd->next;
	}
	return (our_env);
}

void	ft_do_execve(char *command, t_data *data, char **env)
{
	int	fd;

	if (ft_strchr_int(command, '/') == 0)
	{
		fd = open(data->com_matrix[0], O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			data->path = ft_strdup(data->com_matrix[0]);
		}
		else
			ft_error("Error 1", 1);
	}
	else if (ft_strchr_int(command, '.') == 0)
	{
		if (!ft_is_a_local_command(env, data))
			ft_error("Error 2", 1);
	}
	else if (!ft_is_a_system_command(env, data))
		ft_error("minishell: command not found", 127);
	signal(SIGINT, SIG_DFL);
	execve(data->path, data->com_matrix, env);
}

char	**ft_our_builtin(t_cmd *cmd, char **our_env)
{
	if (cmd->cmd)
	{
		if (!ft_strcmp(cmd->cmd, "cd"))
			ft_our_cd(cmd->args);
		else if (!ft_strcmp(cmd->cmd, "export"))
			our_env = ft_our_export(cmd->args, our_env);
		else if (!ft_strcmp(cmd->cmd, "unset"))
			our_env = ft_our_unset(cmd->args, our_env);
		else if (!ft_strcmp(cmd->cmd, "exit"))
			ft_exit(cmd, our_env, 0);
		else
			return (NULL);
	}
	return (our_env);
}

void	ft_exit(t_cmd *cmd, char **our_env, int only_one)
{
	static int	save_only_one;


	if (cmd == NULL && our_env == NULL)
		save_only_one = only_one;
	else
	{
		if (cmd->args[1])
			ft_pipestatus(SET, ft_atoi(cmd->args[1]));
		if (save_only_one == 1)
		{
			ft_free_env(our_env);
			free(our_env);
			ft_cmdclear(&cmd);
			write(1, "exit\n", 5);
			exit(ft_atoi(ft_pipestatus(GET, 0)));
		}
	}
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
//		data->save_stdout = dup(1);
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
//		data->save_stdin = dup(0);
		if (dup2(data->fd_in, 0) < 0)
			ft_error("Error file descriptor 3", 1);
		close(data->fd_in);
	}
	ft_do_execve(cmd->cmd, data, our_env);
}

void	ft_execute_parent(t_cmd *cmd, t_data *data, int pid)
{
	char	*line;
	int		status;
	int		pipe_size;
	char	buf;

	line = NULL;
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
	{
		if (cmd->in != LESSLESS)
		{
			while (get_next_line(data->fd_pipe[0], &line) > 0)
			{
				printf("%s\n", line);
				if (line)
					free(line);
				line = NULL;
			}
			if (line)
				free(line);
			line = NULL;
		}
		close(data->fd_pipe[0]);
	}	
}