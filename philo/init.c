/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:27:58 by user              #+#    #+#             */
/*   Updated: 2023/10/16 17:06:18 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long time)
{
	usleep(time * 1000);
}

t_philo	*init_philo(t_infos *infos)
{
	int				i;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	i = 0;
	philo = ft_calloc((int)infos->nphilo + 1, sizeof(t_philo));
	forks = ft_calloc((int)infos->nphilo + 1, sizeof(pthread_mutex_t));
	while (i < infos->nphilo)
		pthread_mutex_init(&forks[i++], NULL);
	i = 0;
	while (i < infos->nphilo)
	{
		philo[i].num = i + 1;
		philo[i].f_g = forks[i];
		if (i == infos->nphilo - 1)
			philo[i].f_d = &forks[infos->nphilo - 1];
		else
			philo[i].f_d = &forks[i + 1];
		philo[i].infos = infos;
		i++;
	}
	infos->forks = forks;
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
	pthread_mutex_init(&info->m_meal, NULL);
	return (init_philo(info));
}

int	check_argv(char **argv)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (argv[y])
	{
		i = -1;
		if (ft_strlen(argv[y]) > 10)
			return (0);
		while (argv[y][++i])
		{
			if (argv[y][i] < '0' || argv[y][i] > '9')
				return (0);
		}
		y++;
	}
	return (1);
}
