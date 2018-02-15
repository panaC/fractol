/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:59:28 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/15 21:11:41 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fractol.h"
#include <stdio.h>

int			draw_mandelbrot(t_fract *fract)
{
/*	double		x1 = -2.1;
	double		x2 = 0.6;
	double		y1 = -1.2;
	double		y2 = 1.2;*/
	double		rapport = (double)fract->size_win_x / (double)fract->size_win_y;
//	printf("double %.60f\n", fract->h);
	double		x1 = fract->mouse_x - fract->h;
	double		x2 = fract->mouse_x + fract->h;
	double		y1 = fract->mouse_y - (fract->h / rapport);
	double		y2 = fract->mouse_y + (fract->h / rapport);
//	printf("rapport fract->h %.36f\n", (fract->h / rapport));
//	printf("fract->zoom %.36f\n", fract->zoom);
	int			iter_max = 255;
//	printf(" %.36f %.36f\n", (x2 - x1) , (y2 - y1) );
	int			img_x = (int)((x2 - x1) * (double)fract->zoom);
	int			img_y = (int)((y2 - y1) * (double)fract->zoom);
//	printf(" %d %d\n", img_x, img_y);
	int			x = 0;
	int			y = 0;
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	int			i;
	double			tmp;

	while (x < img_x)
	{
		while (y < img_y)
		{
			cr = x / (double)fract->zoom + x1;
			ci = y / (double)fract->zoom + y1;
			zr = 0.0;
			zi = 0.0;
			i = 0;
			
			while ((zr*zr + zi*zi) < 4.0 && i < iter_max)
			{
				tmp = zr;
				zr = zr*zr - zi*zi + cr;
				zi = 2*zi*tmp + ci;
				i++;
			}
			int size_x = (fract->size_win_x / 2) - (img_x / 2);
			int size_y = (fract->size_win_y / 2) - (img_y / 2);
			fract->img.addr[(y + size_y) * fract->img.size_line + (x + size_x) * (fract->img.bpp / 8) + 0] = i;
			fract->img.addr[(y + size_y) * fract->img.size_line + (x + size_x) * (fract->img.bpp / 8) + 1] = i;
			fract->img.addr[(y + size_y) * fract->img.size_line + (x + size_x) * (fract->img.bpp / 8) + 2] = i;
			y++;
		}
		y = 0;
		x++;
	}
	return (TRUE);
}
