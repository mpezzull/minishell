/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:04:49 by mpezzull          #+#    #+#             */
/*   Updated: 2021/10/20 21:38:25 by mde-rosa         ###   ########.fr       */
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

	get_str = ft_getenv("PWD", env);
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

void	ft_less(t_cmd *cmd, t_data *data)
{
	close(data->fd_pipe[0]);
	data->fd_in = open(cmd->file_in, O_RDONLY);
	if (data->fd_in < 0)
		ft_error("Error file descriptor", 1);
	data->save_stdin = dup(0);
	if (dup2(data->fd_in, 0) < 0)
		ft_error("Error file descriptor", 1);
	close(data->fd_in);
}

void	ft_greats(t_cmd *cmd, t_data *data)
{
	int		fd;
	char	*line;

	line = NULL;
	if (cmd->out == GREAT)
		fd = open(cmd->file_out, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else
		fd = open(cmd->file_out, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		ft_error("Error file descriptor", 1);
	data->save_stdout = dup(1);
	if (dup2(fd, 1) < 0)
		ft_error("Error file descriptor", 1);
	while (get_next_line(data->fd_pipe[0], &line) > 0)
	{
		printf("%s\n", line);
		if (line)
			free(line);
		line = NULL;
	}
	dup2(data->save_stdout, 1);
	close(data->fd_pipe[0]);
}

char	*ft_pipestatus(int mode, int status)
{
	static int pipe_status;

	if (mode == SET)
	{
		pipe_status = status;
		return (NULL);
	}
	return (ft_itoa(pipe_status));
}
