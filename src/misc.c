/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:14:25 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/16 03:18:26 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fractol.h"
#include <stdio.h>

int			free_fract(t_fract **fract)
{
	t_fract	*f;

	f = *fract;
	//ft_freearg(&(fd->arg));
	ft_memdel((void**)&(f->mlx));
	ft_memdel((void**)fract);
	return (TRUE);
}

int			put_image(t_fract *f, int x, int y, int i)
{
	f->img.addr[y * f->img.size_line + x * (f->img.bpp / 8) + 0] = color(f, i, 0);
	f->img.addr[y * f->img.size_line + x * (f->img.bpp / 8) + 1] = color(f, i, 1);
	f->img.addr[y * f->img.size_line + x * (f->img.bpp / 8) + 2] = color(f, i, 2);
	return (TRUE);
}

int			color(t_fract *f, int i, int n)
{
	if (n == 1)
	{
		if (f->color >= 1 && f->color <= 3)
			return (i * i);
		else
			return (i);
	}
	else if (n == 2)
	{
		if ((f->color >= 1 && f->color <= 2) || f->color > 2)
			return (i * i);
		else
			return (i);
	}
	else
	{
		if (f->color == 1 || f->color > 3)
			return (i * i);
		else
			return (i);
	}
}
