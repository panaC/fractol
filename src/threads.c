/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:04:07 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/17 19:03:38 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fractol.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int			draw_threads(t_fract *fract)
{
	pthread_t		*thread;
	int				i;
	t_draw			*d;

	thread = (pthread_t*)ft_memalloc(sizeof(pthread_t) * fract->nb_threads);
	d = (t_draw*)ft_memalloc(sizeof(t_draw) * fract->nb_threads);
	i = 0;
	while (i < fract->nb_threads)
	{
		(d[i]).fract = fract;
		(d[i]).numero = i;
		if (pthread_create(&(thread[i]), NULL, draw, (void*)&(d[i])))
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < fract->nb_threads)
	{
		if (pthread_join(thread[i], NULL))
			return (FALSE);
		i++;
	}
	free(d);
	free(thread);
	return (TRUE);
}
