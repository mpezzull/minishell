/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:42:04 by assokenay         #+#    #+#             */
/*   Updated: 2021/11/18 19:18:09 by mde-rosa         ###   ########.fr       */
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
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/ioctl.h>


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

# define SET		1
# define GET		0

//Errors
# define SYNTAX_ERROR 3

typedef struct s_cmd	t_cmd;
typedef struct s_lexer	t_lexer;
typedef struct s_parser	t_parser;
typedef struct s_env	t_env;

struct s_parser
{
	int		token_found;
	int		n_args;
	char	*lessless;
};

struct	s_cmd
{
	char	*cmd;
	char	**args;
	char	**heredoc;
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

typedef struct s_line
{
	char	buffer;
	int		ret;
	char	*str;
	char	temp[65536];
	int		len;
}			t_line;

typedef struct s_data
{
	int		fd_out;
	int		fd_in;
	int		fd_pipe[2];
	char	*path;
	char	**com_matrix;
	int		save_stdout;
	int		save_stdin;
	int		pipe_lessless[2];	
}				t_data;

t_lexer	*ft_lexer(char *str);
void	ft_lstadd_back_lexer(t_lexer **lst, t_lexer *new);
t_lexer	*ft_lstnew_two(char*args, int token);
void	ft_split_lexer(char *cmd_line, t_lexer **lexer);
int		ft_is_space(char c);
int		ft_is_token(char *str, int index);
char	*ft_token(char *cmd_line, int *i);
char	*ft_token_arg(char *cmd_line, int i, int token);
int		ft_token_lenght(int token, int i);
int		ft_token_witch(char *cmd_line, int i);
char	*ft_create_word(char *cmd_line, int *i);
char	*ft_save_word(char *cmd_line, int *start, int lenght);
int		ft_check_closed(char *cmd_line, int i);
int		ft_word_lenght(char *cmd_line, int *index, int lenght);
void	ft_word_str(char *cmd_line, int *index, int *start, char *word);
void	ft_print_lexer(t_lexer *lexer);
t_cmd	*ft_parsing(t_lexer *lexer);
void	ft_error(char *strerror, int nbr);
t_cmd	*init_cmd(void);
void	ft_init_args(t_cmd *instr, int num_args);
int		ft_count_words(char **splitted);
void	ft_zero_dquotes(t_cmd *instr, char **splitted);
t_cmd	*ft_echo(char *token, char **splitted);
t_cmd	*ft_cmd_new(int n_args);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
char	**ft_realloc(char	**ptr, int cur_size, int new_size);
void	ft_print_cmd(t_cmd *cmd);
int		ft_check_double_token(t_lexer *lexer);
int		ft_heredoc_shell(t_lexer *lexer, t_cmd *temp);
void	ft_signal_handler_heredoc(int sig_num);
void	ft_signal_handler(int sig_num);
void	ft_heredoc_child(t_lexer *lexer, int *fd);
void	ft_heredoc_parent(t_cmd	*temp, int *fd);
char	**cp_str_array(char **envp);
void	ft_expander(t_cmd *cmd, char **our_env);
char	*ft_getenv(char *name, char **env);
char	*ft_realloc_str(char	*ptr, int cur_size, int new_size);
char	*ft_find_and_expand(char *to_replace, char **our_env);
void	ft_expand_env(char	*env, char *value, int len_word);
int		get_next_line(int fd, char **line);
char	**ft_data_paths(char **env);
int		ft_matr_del_and_free(char ***matrix);
int		ft_is_a_system_command(char **env, t_data *data);
int		ft_is_a_local_command(char **env, t_data *data);
void	ft_do_execve(char *command, t_data *data, char **env);
char	*ft_get_str_from_env(char *to_find, char **env);
char	**ft_executer(t_cmd *cmd, char **our_env);
int		ft_strchr_int(char *str, char c);
t_cmd	*ft_parsing_token(t_lexer *lexer, t_cmd *temp, t_parser *data, int *i);
void	ft_parsing_pipe(t_lexer *lexer, t_cmd *temp, t_parser *data, int *i);
void	ft_parsing_greats(t_lexer *lexer, t_cmd *temp, t_parser *data);
char	*ft_extract_alnum(char *str);
void	ft_lessless(t_cmd *cmd, t_data *data);
void	ft_less(t_cmd *cmd, t_data *data);
void	ft_greats(t_cmd *cmd, t_data *data);
void	ft_executer_child(t_cmd *cmd, t_data *data, char **our_env);
void	ft_execute_parent(t_cmd *cmd, t_data *data, int pid);
char	*ft_pipestatus(int mode, int status);
void	ft_signal_handler_executer(int sig);
void	ft_signal_handler_heredoc(int sig_num);
void	ft_delete_backslash(char *to_replace);
int		get_file(int fd, char **content);
void	ft_sleep(int ms);
void	ft_expand_builtin(t_cmd *cmd);
char	**ft_our_builtin(t_cmd *cmd, char **our_env);

int		ft_str_isspace(char *str);
int		ft_count_args(char **args);
void	ft_our_cd(char **args);

//export
char	**ft_our_export(char **args, char **envp);
int		ft_there_is_chr(char *str, char c);
char	*ft_check_if_exists(char *str, char **envp);
int		ft_search_in_array(char *search, char **array);
//unset
char	**ft_our_unset(char **args, char **envp);
int		ft_check_if_exists_unset(char *str, char **envp);
char	**ft_realloc_unset(char	**ptr, int cur_size, char	*args);

//free
void	ft_free_env(char **our_env);
void	ft_free_str(char **str);
void	ft_lexerclear(t_lexer **lexer);
void	ft_cmdclear(t_cmd **cmd);

//get_next_line
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);


void	ft_exit(t_cmd *cmd, char **our_env, int only_one);

#endif