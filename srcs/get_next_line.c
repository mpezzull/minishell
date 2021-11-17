/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:25:35 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/17 19:53:56 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_fill_line(char **line_read, char **line, char *temp)
{
	int		i;

	i = 0;
	while (((*line_read)[i] != '\n') && ((*line_read)[i] != '\0'))
		i++;
	if ((*line_read)[i] == '\n')
	{
		*line = ft_substr(*line_read, 0, i);
		temp = ft_strdup(*line_read + i + 1);
		if (*line_read)
		{
			free(*line_read);
			*line_read = NULL;
		}
		*line_read = temp;
		return (1);
	}
	*line = ft_strdup(*line_read);
	if (!(*line))
		return (-1);
	if (*line_read)
	{
		free(*line_read);
		*line_read = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*l_read[OPEN_MAX];
	char			buffer[256];
	char			*temp;
	int				outcome;

	if (fd < 0 || !line || fd > OPEN_MAX)
		return (-1);
	outcome = read(fd, buffer, 256);
	while (outcome > 0)
	{
		buffer[outcome] = '\0';
		if (!l_read[fd] && !(l_read[fd] = (char *)ft_calloc(1, sizeof(char))))
			return (-1);
		temp = ft_strjoin(l_read[fd], buffer);
		if (l_read[fd])
			free(l_read[fd]);
		l_read[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
		outcome = read(fd, buffer, 256);
	}
	if (outcome < 0)
		return (-1);
	if (!outcome && !l_read[fd] && (*line = ft_strdup("")))
		return (0);
	return (ft_fill_line(&l_read[fd], line, NULL));
}
