/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:40:33 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/16 03:38:04 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <stdlib.h>
#include "fractol.h"
#include <stdio.h>

int			expose_win(t_fract *fract)
{
	if (!((fract->img.img = mlx_new_image(fract->mlx, fract->size_win_x, fract->size_win_y))))
		return (FALSE);
	fract->img.addr = mlx_get_data_addr(fract->img.img, &(fract->img.bpp),
			&(fract->img.size_line), &(fract->img.endian));
	draw_mandelbrot(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.img, 0, 0);
	mlx_destroy_image(fract->mlx, fract->img.img);
	return (TRUE);
}

int			mouse_win(int but, int x, int y, void *p)
{
	t_fract *fract;
	
	fract = (t_fract*)p;
	if (x > 0 && x <= fract->size_win_x && y > 0 && y <= fract->size_win_y)
	{
		x = x - (fract->size_win_x / 2);
		y = y - (fract->size_win_y / 2);
		if (but == M_LEFT || but == M_UP)
		{
			fract->mouse_x += (long double)x / fract->zoom;
			fract->mouse_y += (long double)y / fract->zoom;
			fract->h /= ((double)fract->speed / 10);
			fract->zoom = fract->size_win_x / fract->h / 2;
		}
		else if (but == M_RIGHT || but == M_DOWN)
		{
			fract->mouse_x -= (long double)x / fract->zoom;
			fract->mouse_y -= (long double)y / fract->zoom;
			fract->h *= ((double)fract->speed / 10);
			fract->zoom = fract->size_win_x / fract->h / 2;
		}
		expose_win(fract);
	}
	return (TRUE);
}

int			key_win(int key, t_fract *fract)
{
	//int		i;

	//i = 0;
	if (key == K_ESCAPE)
	{
		mlx_destroy_window(fract->mlx, fract->win);
		free_fract(&fract);
		exit(0);
	}
	fract->color = key % K_Q + 1;
	expose_win(fract);
	printf("color %d\n",  fract->color);
/*	while (i < 12)
	{
		if ((fdf->ev[i]).key == key)
			(fdf->ev[i]).ft(fdf);
		i++;
	}*/
	return (TRUE);
}
