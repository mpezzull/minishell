/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:42:04 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/20 00:28:56 by mde-rosa         ###   ########.fr       */
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
typedef struct s_lex_data	t_lex_data;

struct s_lex_data
{
	int	s_quote_open;
	int	d_quote_open;
	int	s_quote_closed;
	int	d_quote_closed;
	int	start;
	int	end;
};

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

t_cmd		*ft_parsing(char *token);
void		ft_error(char *strerror, int nbr);
t_cmd		*init_cmd(void);
void		ft_init_args(t_cmd *instr, int num_args);
int			ft_count_chr(char *str, char c);
int			ft_count_words(char **splitted);
void		ft_zero_dquotes(t_cmd *instr, char **splitted);
t_cmd		*ft_echo(char *token, char **splitted);
t_lexer		*ft_lexer(char *str);
void		ft_lstadd_back_lexer(t_lexer **lst, t_lexer *new);

t_lex_data	initlist(void);
t_lexer		*ft_lstnew_two(char*args, int token);
char		*ft_line_to_args(char *cmd_line, t_lexer **lexer);
int			ft_is_space(char c);
int			ft_there_is_token(char *str, int index);
int			ft_count_char(char *str, int start, int end, char c);
int			ft_there_is_char(char *str, int index, char search);
char		*ft_create_arg(char *cmd_line, t_lexer *lexer, t_lex_data *list);

#endif