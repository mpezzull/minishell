/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:bin/our_env.c
/*   Created: 2021/08/04 01:49:53 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/08/04 02:56:18 by mde-rosa         ###   ########.fr       */
=======
/*   Created: 2021/07/26 16:31:05 by mpezzull          #+#    #+#             */
/*   Updated: 2021/10/14 18:14:23 by mpezzull         ###   ########.fr       */
>>>>>>> d5f0455486ca4709c9885625bdb69ba5d4082b34:src/env.c
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
