/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:27:58 by user              #+#    #+#             */
/*   Updated: 2023/10/14 13:52:04 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long time)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}


t_philo	*init_philo(t_infos *infos)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = ft_calloc((int)infos->nphilo + 1, sizeof(t_philo));
	while (i < infos->nphilo)
	{
		philo[i].num = i + 1;
		pthread_mutex_init(&philo[i].f_g, NULL);
		if (i == infos->nphilo - 1)
			philo[i].f_d = &philo[0].f_g;
		else
			philo[i].f_d = &philo[i + 1].f_g;
		philo[i].infos = infos;
		i++;
	}
	return (philo);
}

t_philo	*init(t_infos *info, int argc, char **argv)
{
	info->nphilo = ft_atol(argv[1]);
	info->tdie = ft_atol(argv[2]);
	info->teat = ft_atol(argv[3]);
	info->tsleep = ft_atol(argv[4]);
	if (argc == 6)
		info->max_eat = ft_atol(argv[5]);
	else
		info->max_eat = -1;
	info->start_time = get_time();
	pthread_mutex_init(&info->m_eat, NULL);
	pthread_mutex_init(&info->m_write, NULL);
	pthread_mutex_init(&info->m_dead, NULL);
	pthread_mutex_init(&info->m_stop, NULL);
	return (init_philo(info));
}

int	check_argv(char **argv)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (argv[y])
	{
		if (ft_strlen(argv[y]) > 10)
			return (-1);
		while (argv[y][i])
		{
			if (argv[y][i] < '0' || argv[y][i] > '9')
				return (-1);
		}
		y++;
	}
	return (1);
}
