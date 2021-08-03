/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:31:46 by mpezzull          #+#    #+#             */
/*   Updated: 2021/08/03 20:07:44 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_is_a_system_command(char **env, t_data *data)
{
	char	**path_matrix;
	char	*save;
	int		fd;
	int		i;

	path_matrix = ft_data_paths(env);
	i = -1;
	while (path_matrix[++i])
	{
		data->path = ft_strjoin(path_matrix[i], "/");
		save = data->path;
		data->path = ft_strjoin(data->path, data->com_matrix[0]);
		free(save);
		fd = open(data->path, O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			ft_matr_del_and_free(&path_matrix);
			return (1);
		}
		free(data->path);
	}
	data->path = NULL;
	ft_matr_del_and_free(&path_matrix);
	return (0);
}

int	ft_is_a_local_command(char **env, t_data *data)
{
	char	*get_str;
	int		fd;

	get_str = ft_get_str_from_env("PWD", env);
	if (!get_str)
		return (0);
	data->path = ft_strjoin(get_str, "/");
	free(get_str);
	get_str = data->path;
	data->path = ft_strjoin(data->path, data->com_matrix[0]);
	free(get_str);
	fd = open(data->path, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (1);
	}
	free(data->path);
	data->path = NULL;
	return (0);
}

char	*ft_get_str_from_env(char *to_find, char **env)
{
	char	*str;
	int		i;
	int		x;

	i = -1;
	str = NULL;
	while (env[++i])
	{
		if (ft_strstr(env[i], to_find))
		{
			x = ft_strchr_int(env[i], '=');
			if (x == -1)
				return (NULL);
			str = ft_substr(env[i], ++x, ft_strlen(env[i]));
			break ;
		}
	}
	return (str);
}

void	ft_do_execve(char *command, t_data *data, char **env)
{
	int	fd;

	close(data->fd_pipe[0]);
	if (dup2(data->fd_pipe[1], 1) < 0)
		ft_error("Error file descriptor", 1);
	close(data->fd_pipe[1]);
	if (ft_strchr_int(command, '/') == 0)
	{
		fd = open(data->com_matrix[0], O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			data->path = ft_strdup(data->com_matrix[0]);
		}
		else
			ft_error("1", 1);
	}
	else if (ft_strchr_int(command, '.') == 0)
	{
		if (!ft_is_a_local_command(env, data))
			ft_error("2", 1);
	}
	else if (!ft_is_a_system_command(env, data))
		ft_error("minishell: command not found", 1);
	execve(data->path, data->com_matrix, env);
	ft_error("Error exec command", 1);
}

void	ft_executer(t_cmd *cmd, char **our_env)
{
	t_data	data;
	int		pid;
	char	*line;
	int 	fd;

	line = NULL;
	data.com_matrix = NULL;
	data.path = NULL;
	while (cmd)
	{
		data.com_matrix = cp_str_array(cmd->args);
		if (pipe(data.fd_pipe) == -1)
			ft_error("Error pipe", 1);
		pid = fork();
		if (pid == -1)
			ft_error("Error fork", 1);
		else if (pid == 0)
			ft_do_execve(cmd->cmd, &data, our_env);
		else
		{
			wait(NULL);
			write(data.fd_pipe[1], "\0", 1);
			close(data.fd_pipe[1]);
			if (cmd->out == GREAT || cmd->out == GREATGREAT)
			{
				fd = open(cmd->file_out, O_CREAT | O_WRONLY | O_APPEND);
				if (fd < 0)
					ft_error("Error file descriptor", 1);
				if (dup2(fd, 1) < 0)
					ft_error("Error file descriptor", 1);
				while (get_next_line(data.fd_pipe[0], &line) != -5)
					printf("%s\n", line);
			}
			else if (cmd->out == PIPE)
				fd = data.fd_pipe[0];
			else
			{
				while (get_next_line(data.fd_pipe[0], &line) != -5)
					printf("%s\n", line);
			}
			close(data.fd_pipe[0]);
		}
		cmd = cmd->next;
	}
}