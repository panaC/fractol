/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:04:07 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/16 16:05:01 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fractol.h"
#include <pthread.h>

struct			s_tmp
{
	t_fract		*fract;
	nt			num;
}

static int	draw_thread(void *p)
{
	struct s_tmp	*t;

	t = (struct s_tmp)p;
	draw(t->fract, 
	return (TRUE);
}

int			draw_threads(t_fract *fract)
{
	pthread_t		thread;
	int				i;
	struct s_tmp	*tmp;

	tmp = (struct s_tmp)ft_memalloc(sizeof(tmp) * fract->nb_threads);
	i = 0;
	while (i < fract->nb_threads)
	{
		(tmp[i]).fract = fract;
		(tmp[i]).num = i;
		if (pthread_create(&thread, NULL, draw_thread, (void*)&(tmp[i]))) {
			perror("pthread_create");
			return (FALSE);
		}
		i++;
	}
	free(tmp);
	return (TRUE);
}
