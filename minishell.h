/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:42:04 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/14 14:57:33 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H 
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"
# include <string.h>

typedef struct s_instr	t_instr;

struct	s_instr
{
	char	*cmd;
	char	*flag;
	char	**args;
	t_instr	*next;
};

t_instr	*ft_parsing(char *token);
void	ft_error(char *strerror, int nbr);
t_instr	*init_instr(void);
void	ft_init_args(t_instr *instr, int num_args);
int		ft_count_chr(char *str, char c);
int		ft_count_words(char **splitted);
void	ft_zero_dquotes(t_instr *instr, char **splitted);
t_instr	*ft_echo(char *token, char **splitted);

#endif