/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:40:33 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/14 20:16:53 by pleroux          ###   ########.fr       */
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
	/*for(int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			fract->img.addr[i * fract->img.size_line + j * (fract->img.bpp / 8) + 0] = 0xFF;
			fract->img.addr[i * fract->img.size_line + j * (fract->img.bpp / 8) + 1] = j % 0xFF;
			fract->img.addr[i * fract->img.size_line + j * (fract->img.bpp / 8) + 2] = i % 0xFF;
			fract->img.addr[i * fract->img.size_line + j * (fract->img.bpp / 8) + 3] = 0;
		}
	}*/
	draw_mandelbrot(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.img, 0, 0);
	mlx_destroy_image(fract->mlx, fract->img.img);
	return (TRUE);
}

int			mouse_win3(int x, int y, void *p)
{;
	((t_fract*)p)->mouse_x = (float)x / ((t_fract*)p)->zoom;
	((t_fract*)p)->mouse_y = (float)y / ((t_fract*)p)->zoom;
	//printf(" %f %f\n", ((t_fract*)p)->mouse_x, ((t_fract*)p)->mouse_y);
	//expose_win(fract);
	return (TRUE);
}

int			key_win(int key, t_fract *fract)
{
	int		i;

	i = 0;
	if (key == K_ESCAPE)
	{
		mlx_destroy_window(fract->mlx, fract->win);
//		free_fdf(&fdf);
		exit(0);
	}
/*	while (i < 12)
	{
		if ((fdf->ev[i]).key == key)
			(fdf->ev[i]).ft(fdf);
		i++;
	}*/
	return (TRUE);
}
