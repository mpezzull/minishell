/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:39:21 by mpezzull          #+#    #+#             */
/*   Updated: 2021/07/24 17:39:26 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
typedef struct s_line
{
	char	buffer;
	char	ret;
	char	*str;
	char	temp[4096];
	int		len;
}			t_line;

int	get_next_line(int fd, char **line);

#endif