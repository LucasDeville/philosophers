/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:11:57 by ldeville          #+#    #+#             */
/*   Updated: 2023/10/14 14:13:39 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check(void *philo)
{
	t_philo		*p;
	long		meal;
	long		die;

	p = (t_philo *)philo;
	if (p->last_meal == 0)
		meal = 0;
	else
		meal = get_time() - p->last_meal;
	die = p->infos->tdie;
	pthread_mutex_lock(&p->infos->m_dead);
	pthread_mutex_lock(&p->infos->m_stop);
	if (p->infos->stop == 0 && meal >= die)
	{
		dead(p);
		p->infos->stop = 1;
	}
	pthread_mutex_unlock(&p->infos->m_stop);
	pthread_mutex_unlock(&p->infos->m_dead);
	return (NULL);
}

void	*job(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->num % 2 != 0)
		ft_usleep(p->infos->teat);
	while (!stop(p))
	{
		pthread_create(&p->t_check, NULL, check, philo);
		eating(p);
		sleeping(p);
		thinking(p);
		pthread_detach(p->t_check);
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
	i = -1;
	while (++i < philo->infos->nphilo)
		pthread_mutex_destroy(&philo[i].f_g);
}
