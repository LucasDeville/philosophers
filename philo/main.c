/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:03 by ldeville          #+#    #+#             */
/*   Updated: 2023/10/13 00:48:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_check(t_infos *infos, char **argv)
{
	/*int	tmp;

	tmp = atoi(argv[1]);
	if (tmp < 1)
		return (-1);
	infos->num_philo = tmp;*/


	return (1);
}

int	main(int argc, char **argv)
{
	t_infos	*infos;

	if (argc != 5 && argc != 6)
		return (-1);
	infos = ft_calloc(sizeof(t_infos), 1);
	if (!check_argv(argv) || !init(infos, argv))
		return (printf("Error : Invalid argument\n"), -1);

/*
	TO DO :
		ARGV -> Check character - Only numeric
		ADD ARGV to struct -> atoi | argc 6
*/



	printf("Test");
	return (0);
}
