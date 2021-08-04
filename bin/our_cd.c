/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:54:05 by assokenay         #+#    #+#             */
/*   Updated: 2021/08/04 13:45:10 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_str_isspace(char *str);
int		ft_count_args(char **args);
void	ft_our_cd(char **args);
// ELIMINARE DA QUI...
void	ft_print_pwd(char *msg);

int	main(int argc, char **argv)
{
	if (argc > 2)
		printf("lancia ./our_cd pathname\n");
	char *a[1];
	a[0] = 	argv[1];
	ft_print_pwd("before: pwd= ");
	ft_our_cd(a);
	ft_print_pwd("after : pwd= ");
	return (0);
}

void	ft_print_pwd(char *msg)
{
	char	*current;
	size_t	size;

	current = NULL;
	size = 100;
	current = getcwd(current, size);
	printf("%s%s\n", msg, current);
	free (current);
}

//....................FINO A QUI!

static int	ft_strcmp(char *s1, char *s2)
{
	int				c;
	int				n1;
	int				n2;

	c = 0;
	while (s1[c] != '\0' || s2[c] != '\0')
	{
		if (s1[c] != s2[c])
		{
			n1 = s1[c];
			n2 = s2[c];
			if (n1 > n2 || n1 < n2)
				return (n1 - n2);
		}
		if (s1[c] == s2[c])
			c++;
	}
	return (0);
}

void	ft_our_cd(char **args)
{
	int	argc;

	argc = ft_count_args(args);
	if (argc > 1)
		printf("minishell: cd: too many arguments\n");
	else if ((argc == -1) || (ft_strcmp(args[0], "~") == 0)
		|| (ft_str_isspace(args[0]) == 0))
		chdir(getenv("HOME"));
	else
		if (chdir(args[0]) == -1)
			printf("minishell: cd: %s: No such file or directory\n", args[0]);
}

// return 0 if the string is only spaces, otherwise return 1
int	ft_str_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (1);
	}
	return (0);
}

//return how many strings there is in the array (args[?])
// -1 if there is not strings.
int	ft_count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i - 1);
}
