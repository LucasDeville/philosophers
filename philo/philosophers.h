/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:43:32 by ldeville          #+#    #+#             */
/*   Updated: 2023/10/13 00:43:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>

typedef struct s_infos
{
	t_philo	*philo;
	int		nphilo;
	int		tdie;
	int		teat;
	int		tsleep;
	int		max_eat;
}	t_infos;

typedef struct s_philo
{
	int	exit;
}	t_philo;


#endif