/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:43:32 by ldeville          #+#    #+#             */
/*   Updated: 2023/08/17 17:01:56 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>

typedef struct s_infos
{
    t_philo *philo;
    int num_philo;
    int die_time;
    int eat_time;
    int sleep_time;
    int max_eat;
} t_infos;

typedef struct s_philo
{
    int exit;
} t_philo;


#endif