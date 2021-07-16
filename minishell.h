/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:42:04 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/16 17:44:47 by mpezzull         ###   ########.fr       */
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

# define GREAT		1
# define LESS		2
# define GREATGREAT	3
# define LESSLESS	4
# define PIPE		5
# define WORD		6
# define NOTOKEN	7

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
	int		token;
	t_lexer	*next;
};

t_cmd	ft_parsing(t_lexer *lexer);
void	ft_error(char *strerror, int nbr);
t_cmd	*init_cmd(void);
void	ft_init_args(t_cmd *instr, int num_args);
int		ft_count_chr(char *str, char c);
int		ft_count_words(char **splitted);
void	ft_zero_dquotes(t_cmd *instr, char **splitted);
t_cmd	*ft_echo(char *token, char **splitted);

#endif