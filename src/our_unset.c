/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:54:54 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/08/10 12:57:07 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
void	ft_print_array(char **str);
int	main(int argc, char **argv, char **envp)
{
	char	**our_envp;
	char	*a[2];

	our_envp = cp_str_array(envp);
	argc = argc;
	a[0] = argv[1];
	a[1] = argv[2];
	a[2] = NULL;
	printf("Before:\n\n");
	ft_print_array(our_envp);
	our_envp = ft_our_unset(a, our_envp);
	printf("\n\nAfter :\n\n");
	ft_print_array(our_envp);
	return (0);
}

void	ft_print_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i++]);
		fflush(stdout);
	}
}
*/

char	**ft_our_unset(char **args, char **envp)
{
	int		argc;
	int		i;
	int		size_envp;

	i = 0;
	argc = ft_count_args(args);
	size_envp = ft_count_args(envp);
	while (i < argc)
	{
		if (ft_check_if_exists_unset(args[i], envp))
			envp = ft_realloc_unset(envp, size_envp, args[i++]);
		else
			i++;
	}
	return (envp);
}

char	**ft_realloc_unset(char	**ptr, int cur_size, char	*args)
{
	char	**new_ptr;
	int		i;
	int		j;

	if (ptr == 0)
	{
		ptr = (char **)ft_calloc((cur_size), sizeof(char *));
		if (!ptr)
			ft_error(strerror(errno), errno);
		return (ptr);
	}
	new_ptr = (char **)ft_calloc((cur_size), sizeof(char *));
	if (!new_ptr)
		ft_error(strerror(errno), errno);
	i = 0;
	j = 0;
	while (ptr[i])
	{
		if (ft_strncmp(ptr[i], args, ft_strlen(args)) == 0)
			i++;
		else
			new_ptr[j++] = ptr[i++];
	}
	free(ptr);
	return (new_ptr);
}

int	ft_check_if_exists_unset(char *str, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], str, ft_strlen(str)) == 0
			&& envp[i][ft_strlen(str)] == '=')
			return (1);
		i++;
	}
	return (0);
}
