/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:43:32 by ldeville          #+#    #+#             */
/*   Updated: 2023/08/17 15:44:47 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "ft_printf/libft/libft.h"
# include <stdio.h>

typedef struct s_infos
{
    int num_philo;
} t_infos;

typedef struct s_philo
{
    int exit;
} t_philo;


#endif