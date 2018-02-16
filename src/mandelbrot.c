/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:59:28 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/16 10:19:31 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fractol.h"
#include <stdio.h>
#include <math.h>

static void		init_draw(t_draw *d, t_fract *fract)
{
	double			rapport;
	
	rapport = (double)fract->size_win_x / (double)fract->size_win_y;
	d->x1 = fract->mouse_x - fract->h;
	d->x2 = fract->mouse_x + fract->h;
	d->y1 = fract->mouse_y - (fract->h / (long double)rapport);
	d->y2 =  fract->mouse_y + (fract->h / (long double)rapport);
	d->img_x = (int)((d->x2 - d->x1) * fract->zoom);
	d->img_y = (int)((d->y2 - d->y1) * fract->zoom);
	d->x = 0;
	d->y = 0;
}

static void		mandelbrot(t_draw *d, t_fract *fract, int *i)
{
	long double		tmp;

	d->cr = d->x / fract->zoom + d->x1;
	d->ci = d->y / fract->zoom + d->y1;
	d->zr = 0.0;
	d->zi = 0.0;
	*i = 0;
	while ((d->zr*d->zr + d->zi*d->zi) < 4.0 && *i < fract->iter_max)
	{
		tmp = d->zr;
		d->zr = d->zr*d->zr - d->zi*d->zi + d->cr;
		d->zi = 2*d->zi*tmp + d->ci;
		*i = *i + 1;
	}
}

static void		julia(t_draw *d, t_fract *fract, int *i)
{
	long double		tmp;

	d->cr = fract->julia_r;
	d->ci = fract->julia_i;
	d->zr = d->x / fract->zoom + d->x1;
	d->zi = d->y / fract->zoom + d->y1;
	*i = 0;
	while ((d->zr*d->zr + d->zi*d->zi) < 4.0 && *i < fract->iter_max)
	{
		tmp = d->zr;
		d->zr = d->zr*d->zr - d->zi*d->zi + d->cr;
		d->zi = 2*d->zi*tmp + d->ci;
		*i = *i + 1;
	}
}

static void		burningball(t_draw *d, t_fract *fract, int *i)
{
	long double		tmp;

	d->cr = d->x / fract->zoom + d->x1;
	d->ci = d->y / fract->zoom + d->y1;
	d->zr = 0.0;
	d->zi = 0.0;
	*i = 0;
	while ((d->zr*d->zr + d->zi*d->zi) < 4.0 && *i < fract->iter_max)
	{
		tmp = d->zr;
		d->zr = d->zr*d->zr - d->zi*d->zi + d->cr;
		d->zi = 2*d->zi*fabsl(tmp) + d->ci;
		*i = *i + 1;
	}
}

int			draw(t_fract *fract)
{
	int				i;
	t_draw			draw;

	init_draw(&draw, fract);
	while (draw.x < draw.img_x)
	{
		while (draw.y < draw.img_y)
		{
			if (fract->select == MANDEL)
				mandelbrot(&draw, fract, &i);
			else if (fract->select == JULIA)
				julia(&draw, fract, &i);
			else if (fract->select == BURN)
				burningball(&draw, fract, &i);
			put_image(fract, draw.x, draw.y, i);
			draw.y++;
		}
		draw.y = 0;
		draw.x = draw.x + 1;
	}
	return (TRUE);
}
