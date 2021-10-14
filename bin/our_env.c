/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:35:28 by mpezzull          #+#    #+#             */
/*   Updated: 2021/10/14 19:35:31 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_print_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		printf("%s\n", str[i++]);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1)
		ft_print_array(envp);
	else
		printf("our_env: ‘%s’: No such file or directory\n", argv[1]);
}
