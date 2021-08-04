/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 01:49:53 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/08/04 02:28:01 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_print_array(char **str);

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1)
		ft_print_array(envp);
	else
		printf("our_env: ‘%s’: No such file or directory\n", argv[1]);
}

void	ft_print_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		printf("%s\n", str[i++]);
}
