/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:59:28 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/16 06:31:03 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fractol.h"
#include <stdio.h>
#include <math.h>

int			draw_mandelbrot(t_fract *fract)
{
/*	double		x1 = -2.1;
	double		x2 = 0.6;
	double		y1 = -1.2;
	double		y2 = 1.2;*/
	double		rapport = (double)fract->size_win_x / (double)fract->size_win_y;
//	printf("double %.60f\n", fract->h);
	long double		x1 = fract->mouse_x - fract->h;
	long double		x2 = fract->mouse_x + fract->h;
	long double		y1 = fract->mouse_y - (fract->h / (long double)rapport);
	long double		y2 = fract->mouse_y + (fract->h / (long double)rapport);
//	printf("rapport fract->h %.36f\n", (fract->h / rapport));
//	printf("fract->zoom %.36f\n", fract->zoom);
//	printf(" %.36f %.36f\n", (x2 - x1) , (y2 - y1) );
	int			img_x = (int)((x2 - x1) * fract->zoom);
	int			img_y = (int)((y2 - y1) * fract->zoom);
//	printf(" %d %d\n", img_x, img_y);
	int			x = 0;
	int			y = 0;
	//long double			cr;
	//long double			ci;
	long double			zr;
	long double			zi;
	int			i;
	//double			tmp;

	while (x < img_x)
	{
		while (y < img_y)
		{
			/*
			cr = x / fract->zoom + x1;
			ci = y / fract->zoom + y1;
			*/
			/*
			cr = fract->julia_r;
			ci = fract->julia_i;
			zr = x / fract->zoom + x1;
			zi = y / fract->zoom + y1;
			*/
			zr = x / fract->zoom + x1;
			zi = y / fract->zoom + y1;
			/*
			zr = 0.0;
			zi = 0.0;
			*/
			i = 0;
			while ((zr*zr + zi*zi) < 4.0 && i < fract->iter_max)
			{
				/*
				tmp = zr;
				zr = zr*zr - zi*zi + cr;
				zi = 2*zi*tmp + ci;
				*/
				zi = fabsl(zr*zi);
				zi = zi + zi;
				zr = zr*zr - zi*zi;
				i++;
			}
			put_image(fract, x, y, i);
			y++;
		}
		y = 0;
		x++;
	}
	return (TRUE);
}
