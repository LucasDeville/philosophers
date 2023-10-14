/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:12:03 by ldeville          #+#    #+#             */
/*   Updated: 2023/10/14 11:42:39 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	dead(t_philo *p)
{
	print_action(p, "is dead");
}

int	stop(t_philo *p)
{
	pthread_mutex_lock(&p->infos->m_stop);
	if (p->infos->stop == 1)
		return (pthread_mutex_unlock(&p->infos->m_stop), 1);
	return (pthread_mutex_unlock(&p->infos->m_stop), 0);
}

void	eating(t_philo *p)
{
	pthread_mutex_lock(p->f_d);
	print_action(p, "has taken a fork");
	pthread_mutex_lock(&p->f_g);
	print_action(p, "has taken a fork");
	print_action(p, "is eating");
	p->last_meal = get_time();
	usleep(p->infos->teat);
	pthread_mutex_unlock(p->f_d);
	pthread_mutex_unlock(&p->f_g);
}

void	sleeping(t_philo *p)
{
	print_action(p, "is sleeping");
	usleep(p->infos->tsleep);
}

void	thinking(t_philo *p)
{
	print_action(p, "is thinking");
}
