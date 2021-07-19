/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:42:27 by mpezzull          #+#    #+#             */
/*   Updated: 2021/07/19 18:50:13 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_parsing(t_lexer *lexer)
{
	t_cmd	*head;
	t_cmd	*temp;
	int		new_cmd;
	int		n_args;
	int		i;

	new_cmd = 1;
	head = NULL;
	while (lexer)
	{
		if (new_cmd)
		{
			n_args = ft_count_args(lexer);
			temp = ft_cmd_new(n_args);
			ft_cmdadd_back(&head, temp);
			if (lexer->token == WORD)
				temp->cmd = ft_strdup(lexer->args);
			new_cmd = 0;
		}
		else
		{
			if (lexer->token == WORD)
				temp->args[i++] = ft_strdup(lexer->args);
			if (lexer->token == PIPE)
			{
				temp->out = PIPE;
				new_cmd = 1;
				i = 0;
				temp = temp->next;
			}
		}
		lexer = lexer->next;
	}
	// while (head)
	// {
	// 	printf("head:     %x\n", (unsigned int)head);
	// 	printf("%s\n", (head)->cmd);
	// 	if ((head)->args)
	// 		printf("%s\n", (head)->args[0]);
	// 	(head) = (head)->next;
	// }
	return (head);
}

t_cmd	*ft_cmd_new(int n_args)
{
	t_cmd	*cmd;

	cmd = (void *)malloc(sizeof(t_cmd));
	if (!cmd)
		ft_error(strerror(errno), errno);
	cmd->args = (char **)malloc(sizeof(char *) * (n_args + 1));
	if (!cmd->args)
		ft_error(strerror(errno), errno);
	cmd->next = NULL;
	return (cmd);
}

void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*temp;

	if (!cmd)
		return ;
	temp = *cmd;
	if (temp == NULL)
	{
		*cmd = new;
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

int	ft_count_args(t_lexer *lexer)
{
	int	count;

	count = 0;
	if (!lexer)
		return (count);
	while (lexer && lexer->token != PIPE)
	{
		count++;
		lexer = lexer->next;
	}
	count--;
	return (count);
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
	void	*address_first;
	char	**args;

	address_first = &lexer;
	int i = 0;
	tmp = ft_lstnew_two(ft_strdup("ls"), WORD);
	ft_lstadd_back_lexer(address_first, tmp);
	tmp = ft_lstnew_two(ft_strdup("-l"), WORD);
	ft_lstadd_back_lexer(address_first, tmp);
	tmp = ft_lstnew_two(ft_strdup("|"), PIPE);
	ft_lstadd_back_lexer(address_first, tmp);
	tmp = ft_lstnew_two(ft_strdup("cat"), WORD);
	ft_lstadd_back_lexer(address_first, tmp);
	tmp = ft_lstnew_two(ft_strdup("file1"), WORD);
	ft_lstadd_back_lexer(address_first, tmp);
	tmp = ft_lstnew_two(ft_strdup("file2"), WORD);
	ft_lstadd_back_lexer(address_first, tmp);
	tmp = ft_lstnew_two(ft_strdup("file3"), WORD);
	ft_lstadd_back_lexer(address_first, tmp);
	tmp = ft_lstnew_two(ft_strdup("|"), PIPE);
	ft_lstadd_back_lexer(address_first, tmp);
	tmp = ft_lstnew_two(ft_strdup("cat"), WORD);
	ft_lstadd_back_lexer(address_first, tmp);
	return (lexer);
}

