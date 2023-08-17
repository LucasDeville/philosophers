/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:03 by ldeville          #+#    #+#             */
/*   Updated: 2023/08/17 17:03:44 by ldeville         ###   ########.fr       */
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

int main(int argc, char **argv, char **str)
{
	(void)argv;
	(void)argc;
	(void)str;
	t_infos	*infos;

	if (argc != 5 && argc != 6)
		return (-1);
	if	(!init(infos, argv) || !check_argv(argv))
	{
		//free infos
		return (-1);
	}

	infos = ft_calloc(sizeof(t_infos), 1);



	printf("Test");
	return (0);
}
