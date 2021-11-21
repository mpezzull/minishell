/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:32:31 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/20 22:35:41 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strchr_int(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

int	ft_matr_del_and_free(char ***matrix)
{
	int	i;

	i = -1;
	if (!(*matrix))
		return (0);
	while ((*matrix)[++i])
	{
		free((*matrix)[i]);
		(*matrix)[i] = NULL;
	}
	free(*matrix);
	*matrix = NULL;
	return (0);
}

char	**ft_data_paths(char **env)
{
	char	*get_str;
	char	**path_matrix;

	get_str = ft_getenv("PATH", env);
	if (!get_str)
		return (0);
	path_matrix = ft_split(get_str, ':');
	free(get_str);
	return (path_matrix);
}

void	ft_signal_handler_executer(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
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
