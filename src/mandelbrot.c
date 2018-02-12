/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:59:28 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/12 14:18:07 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fractol.h"
#include <stdio.h>

int			draw_mandelbrot(t_fract *fract)
{
	float		x1 = -2.1;
	float		x2 = 0.6;
	float		y1 = -1.2;
	float		y2 = 1.2;
	int			zoom = 400;
	int			iter_max = 100;
	int			img_x = (int)((x2 - x1) * (float)zoom);
	int			img_y = (int)((y2 - y1) * (float)zoom);
	int			x = 0;
	int			y = 0;
	float			cr;
	float			ci;
	float			zr;
	float			zi;
	int			i;
	float			tmp;

	while (x < img_x)
	{
		while (y < img_y)
		{
			cr = x / (float)zoom + x1;
			ci = y / (float)zoom + y1;
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
			fract->img.addr[(y + size_y) * fract->img.size_line + (x + size_x) * (fract->img.bpp / 8) + 0] = (int)(i * 2.5);
			fract->img.addr[(y + size_y) * fract->img.size_line + (x + size_x) * (fract->img.bpp / 8) + 1] = (int)(i * 2.5);
			fract->img.addr[(y + size_y) * fract->img.size_line + (x + size_x) * (fract->img.bpp / 8) + 2] = (int)(i * 2.5);
			y++;
		}
		y = 0;
		x++;
	}
	return (TRUE);
}
