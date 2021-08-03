/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:42:04 by assokenay         #+#    #+#             */
/*   Updated: 2021/08/03 14:33:38 by mde-rosa         ###   ########.fr       */
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
# include "../libft/libft.h"
# include <string.h>

# define DEFAULT	0
# define GREAT		1
# define LESS		2
# define GREATGREAT	3
# define LESSLESS	4
# define PIPE		5
# define WORD		6
# define NOTOKEN	7

typedef struct s_cmd		t_cmd;
typedef struct s_lexer		t_lexer;

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
t_lexer		*ft_lstnew_two(char*args, int token);
void		ft_split_lexer(char *cmd_line, t_lexer **lexer);
int			ft_is_space(char c);
int			ft_is_token(char *str, int index);
char		*ft_token(char *cmd_line, int *i);
char		*ft_token_arg(char *cmd_line, int i, int token);
int			ft_token_lenght(int token, int i);
int			ft_token_witch(char *cmd_line, int i);
char		*ft_create_word(char *cmd_line, int *i);
char		*ft_save_word(char *cmd_line, int *start, int lenght);
int			ft_check_closed(char *cmd_line, int i);
int			ft_word_lenght(char *cmd_line, int *index, int lenght);
void		ft_word_str(char *cmd_line, int *index, int *start, char *word);
void		ft_print_lexer(t_lexer *lexer);


#endif