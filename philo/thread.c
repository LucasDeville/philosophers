/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:11:57 by ldeville          #+#    #+#             */
/*   Updated: 2023/10/16 17:34:51 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_meal(t_philo *p)
{
	pthread_mutex_lock(&p->infos->m_meal);
	if (p->meal == p->infos->max_eat)
	{
		p->end = 1;
		p->infos->actual_eat++;
		if (p->infos->actual_eat == p->infos->nphilo)
		{
			pthread_mutex_lock(&p->infos->m_stop);
			p->infos->stop = 1;
			pthread_mutex_unlock(&p->infos->m_stop);
			pthread_mutex_unlock(&p->infos->m_meal);
			return (0);
		}
	}
	pthread_mutex_unlock(&p->infos->m_meal);
	return (1);
}

void	*check(void *philo)
{
	t_philo		*p;
	long		meal;
	long		die;

	p = (t_philo *)philo;
	ft_usleep(p->infos->tdie);
	pthread_mutex_lock(&p->infos->m_eat);
	if (p->last_meal == 0)
		meal = get_time() - p->infos->start_time;
	else
		meal = get_time() - p->last_meal;
	pthread_mutex_unlock(&p->infos->m_eat);
	pthread_mutex_lock(&p->infos->m_dead);
	die = p->infos->tdie;
	pthread_mutex_unlock(&p->infos->m_dead);
	pthread_mutex_lock(&p->infos->m_stop);
	if (p->infos->stop == 0 && meal >= die)
	{
		dead(p);
		p->infos->stop = 1;
	}
	pthread_mutex_unlock(&p->infos->m_stop);
	return (NULL);
}

void	*job(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->num % 2 == 0)
		ft_usleep(p->infos->teat / 10);
	while (!stop(p))
	{
		pthread_create(&p->t_check, NULL, check, philo);
		eating(p);
		pthread_detach(p->t_check);
		if (!check_meal(p))
			break ;
	}
	return (NULL);
}

void	thread(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->infos->nphilo)
		pthread_create(&philo[i].t_id, NULL, job, &philo[i]);
	i = -1;
	while (++i < philo->infos->nphilo)
		pthread_join(philo[i].t_id, NULL);
	if (philo[0].infos->actual_eat == philo->infos->nphilo)
		printf("Each philosophers eated %li times !\n", philo->infos->max_eat);
	i = -1;
	while (++i < philo->infos->nphilo)
		pthread_mutex_destroy(&philo[i].f_g);
}
