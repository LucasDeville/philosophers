/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:03 by ldeville          #+#    #+#             */
/*   Updated: 2023/08/17 15:47:20 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



int main(int argc, char **argv, char **str)
{
	(void)argv;
	(void)argc;
	(void)str;
	t_infos	*infos;

	if (argv != 5 || argv != 6)
		return (-1);
	
	infos = ft_calloc(sizeof(t_infos), 1);



	printf("Test");
	return (0);
}
