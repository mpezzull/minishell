/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:47:27 by assokenay         #+#    #+#             */
/*   Updated: 2021/07/22 14:52:15 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_lexer(char *cmd_line);

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_line;
	char	*prompt;
	char	*temp;
	t_cmd	*cmd;
	t_lexer	*lexer;

	if (argc != 1)
		ft_error("Launch with \"./minishell\"", 1);
	printf("\n\t\t\033[1mWelcome in the worst minishell of the world!\n\n\033[0m");
	temp = ft_strdup("@minishell:~$ ");
	prompt = ft_strjoin(getenv("USER"), temp);
	free(temp);
	while (TRUE)
	{
		cmd_line = readline(prompt);
		if (ft_strcmp(cmd_line, "exit") == 0)
			break ;
		add_history(cmd_line);
		lexer = ft_lexer(cmd_line);
		cmd = ft_parsing(lexer);
//		ft_expander(cmd);
//		ft_executer(cmd);
		int i = 0;
		while (cmd)
		{
			int j = 0;
			printf("---------------	%d ----------------\n", i++);
			printf("cmd:     %s\n", cmd->cmd);
			while (cmd->args && cmd->args[j])
			{
				printf("args[%i]: %s\n", j, cmd->args[j]);
				j++;
			}
			if (cmd->out)
				printf("out: %d\n", cmd->out);
			if (cmd->file_out)
				printf("file_out: %s\n", cmd->file_out);
			if (cmd->in)
				printf("in: %d\n", cmd->in);
			if (cmd->file_in)
				printf("file_in: %s\n", cmd->file_in);
			printf("cmd_next:  %x\n", (unsigned int)cmd->next);
			cmd = cmd->next;
		}

		free(cmd_line);
	}
	free(prompt);
	return (0);
}

void	ft_error(char *strerror, int nbr)
{
	printf("%s\n", strerror);
	exit(nbr);
}

t_lexer	*ft_lstnew_two(char*args, int token)
{
	t_lexer	*lst;

	lst = (void *)malloc(sizeof(t_lexer));
	if (!lst)
		ft_error(strerror(errno), errno);
	lst->args = args;
	lst->token = token;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back_lexer(t_lexer **lst, t_lexer *new)
{
	t_lexer	*temp;

	if (!lst)
		return ;
	temp = *lst;
	if (temp == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	temp->next = new;
}

t_lexer	*ft_lexer(char *cmd_line)
{
	t_lexer	*lexer;
	t_lexer	*tmp;
	void	*head;
	char	**args;

	head = &lexer;
	tmp = ft_lstnew_two(ft_strdup("ls"), WORD);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("-l"), WORD);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("|"), PIPE);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("cat"), WORD);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("file1"), WORD);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup(">"), GREAT);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("file2"), WORD);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("|"), PIPE);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("cat"), WORD);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup(">>"), GREATGREAT);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("file3"), WORD);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("|"), PIPE);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("cat"), WORD);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("<<"), LESSLESS);
	ft_lstadd_back_lexer(head, tmp);
	tmp = ft_lstnew_two(ft_strdup("file4"), WORD);
	ft_lstadd_back_lexer(head, tmp);

	return (lexer);
}