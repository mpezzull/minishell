/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 02:11:46 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/07/22 02:38:38 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_word(char *cmd_line, int *i, t_lexer **lexer)
{
	char	*word;
	t_lexer	*tmp;

	word = ft_word_arg(cmd_line, *i);
	*i += ft_word_lenght(cmd_line, *i);
	tmp = ft_lstnew_two(word, WORD);
	ft_lstadd_back_lexer(lexer, tmp);
}

/* ritorna la parola che va
 dall indice fino al prossimo spazio/toke/fineriga */
char	*ft_word_arg(char *cmd_line, int i)
{
	char	*word;
	int		lenght;
	int		j;

	j = 0;
	lenght = ft_word_lenght(cmd_line, i);
	word = (char *)malloc((lenght * sizeof(char) + 1));
	while (j < lenght)
		word[j++] = cmd_line[i++];
	word[j] = '\0';
	return (word);
}

// ritorna quanti caratteri ha letto
// partendo dall indice fino a spazio o token.
int	ft_word_lenght(char *cmd_line, int i)
{
	int	lenght;

	lenght = 0;
	while (cmd_line[i] && ft_there_is_token(cmd_line, i) == 0
		&& ft_is_space(cmd_line[i]) == 0)
	{
		lenght++;
		i++;
	}
	return (lenght);
}
