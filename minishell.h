/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:42:04 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/24 17:03:34 by mpezzull         ###   ########.fr       */
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

# define DEFAULT	0
# define GREAT		1
# define LESS		2
# define GREATGREAT	3
# define LESSLESS	4
# define PIPE		5
# define WORD		6
# define NOTOKEN	7
# define FIRST		8

# define TRUE		1

//Errors
# define SYNTAX_ERROR 3

typedef struct s_cmd	t_cmd;
typedef struct s_lexer	t_lexer;
typedef struct s_parser	t_parser;

struct s_parser
{
	int		token_found;
	int		n_args;
	char	*lessless;
};

struct	s_cmd
{
	char	*cmd;
	char	*flag;
	char	**args;
	int		in;
	int		out;
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

t_cmd	*ft_parsing(t_lexer *lexer);
void	ft_error(char *strerror, int nbr);
t_cmd	*init_cmd(void);
void	ft_init_args(t_cmd *instr, int num_args);
int		ft_count_chr(char *str, char c);
int		ft_count_words(char **splitted);
void	ft_zero_dquotes(t_cmd *instr, char **splitted);
t_cmd	*ft_echo(char *token, char **splitted);

t_cmd	*ft_cmd_new(int n_args);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
char	**ft_realloc(char	**ptr, int cur_size, int new_size);
int		rl_replace_line(char *line, int clear_undo);
void	ft_print_cmd(t_cmd *cmd);
void	ft_check_double_token(t_lexer *lexer);
void	ft_heredoc_shell(t_lexer *lexer, t_cmd *temp, int *i);
void	ft_signal_handler_heredoc(int sig_num);

#endif