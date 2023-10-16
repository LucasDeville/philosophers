/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:03 by ldeville          #+#    #+#             */
/*   Updated: 2023/10/16 11:32:33 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_philo *philo)
{
	free(philo[0].infos->forks);
	free(philo[0].infos);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_infos		*infos;
	t_philo		*philo;

	if (argc != 5 && argc != 6)
		return (printf("Error : Invalid argument\n"), -1);
	infos = ft_calloc(sizeof(t_infos), 1);
	if (!check_argv(argv))
		return (free(infos), printf("Error : Invalid argument\n"), -1);
	philo = init(infos, argc, argv);
	thread(philo);
	ft_usleep(500);
	free_all(philo);
	return (0);
}
