/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:43:32 by ldeville          #+#    #+#             */
/*   Updated: 2023/10/13 15:31:16 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_infos
{
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_write;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_meal;
	long			nphilo;
	long			tdie;
	long			teat;
	long			tsleep;
	int				death;
	long			max_eat;
	long			actual_eat;
	long			stop;
	long			start_time;
	pthread_mutex_t	*forks;
}	t_infos;

typedef struct s_philo
{
	int				num;
	pthread_t		t_id;
	pthread_t		t_check;
	long			last_meal;
	int				end;
	int				meal;
	pthread_mutex_t	f_g;
	pthread_mutex_t	*f_d;
	t_infos			*infos;
}	t_philo;

/*		utils.c		*/
long		get_time(void);
void		print_action(t_philo *p, char *str);
long		ft_atol(char *str);
int			ft_strlen(char *str);
void		*ft_calloc(size_t nmemb, size_t size);

/*		init.c		*/
void		ft_usleep(long time);
int			check_argv(char **argv);
t_philo		*init(t_infos *info, int argc, char **argv);

/*		thread.c	*/
void		thread(t_philo *infos);

/*		tasks.c		*/
void		dead(t_philo *p);
int			stop(t_philo *p);
void		eating(t_philo *p);
void		sleeping(t_philo *p);
void		thinking(t_philo *p);

#endif