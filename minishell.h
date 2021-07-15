/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:42:04 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/15 19:43:03 by mde-rosa         ###   ########.fr       */
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

typedef struct s_cmd	t_cmd;
typedef struct s_lexer	t_lexer;

struct	s_cmd
{
	char	*cmd;
	char	*flag;
	char	**args;
	char	*in;
	char	*out;
	char	*file_in;
	char	*file_out;
	t_cmd	*next;
};

struct	s_lexer
{
	char	*args;
	char	*token;
	t_lexer	*next;
};

t_cmd	*ft_parsing(char *token);
void	ft_error(char *strerror, int nbr);
t_cmd	*init_cmd(void);
void	ft_init_args(t_cmd *instr, int num_args);
int		ft_count_chr(char *str, char c);
int		ft_count_words(char **splitted);
void	ft_zero_dquotes(t_cmd *instr, char **splitted);
t_cmd	*ft_echo(char *token, char **splitted);
t_lexer	*ft_lexer(char *str);
void	ft_lstadd_back_lexer(t_lexer **lst, t_lexer *new);

#endif