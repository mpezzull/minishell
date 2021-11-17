/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:38:58 by mpezzull          #+#    #+#             */
/*   Updated: 2021/11/16 03:22:09 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_next_line(int fd, char **line)
{
	t_line	gnl;

	gnl.len = 0;
	if (!(line))
		return (-1);
	gnl.temp[0] = '\0';
	gnl.ret = read(fd, &gnl.buffer, 1);
	while (gnl.ret > 0)
	{
		if (gnl.buffer == '\n')
			break ;
		if (gnl.buffer == '\0')
			return (-5);
		gnl.temp[gnl.len++] = gnl.buffer;
		gnl.ret = read(fd, &gnl.buffer, 1);
	}
	gnl.temp[gnl.len + 1] = '\0';
	gnl.str = ((char *)malloc(sizeof(char) * (gnl.len + 1)));
	if (!(gnl.str))
		return (-1);
	gnl.str[gnl.len] = '\0';
	while (gnl.len-- >= 0)
		gnl.str[gnl.len] = gnl.temp[gnl.len];
	*line = gnl.str;
	return (gnl.ret);
}

int	get_file(int fd, char **content)
{
	t_line	gnl;
	int		i;

	gnl.len = 0;
	i = 0;
	while (i < 65536)
		gnl.temp[i++] = '\0';
	gnl.ret = read(fd, &gnl.buffer, 1);
	while (gnl.ret > 0)
	{
		gnl.temp[gnl.len++] = gnl.buffer;
		gnl.ret = read(fd, &gnl.buffer, 1);
	}
	gnl.temp[gnl.len] = '\0';
	gnl.str = ((char *)malloc(sizeof(char) * (gnl.len + 1)));
	if (!(gnl.str))
		return (-1);
	gnl.str[gnl.len] = '\0';
	i = 0;
	while (i < gnl.len)
	{
		gnl.str[i] = gnl.temp[i];
		i++;
	}
	*content = gnl.str;
	return (1);
}
