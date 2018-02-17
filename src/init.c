/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:27:51 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/17 19:03:40 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <arg.h>
#include "fractol.h"
#include <stdio.h>

int			init_fract(t_fract *fract, int s)
{
	fract->h = 4.0;
	fract->mouse_x = 0.0;
	fract->mouse_y = 0.0;
	fract->select = s;
	fract->zoom = fract->size_win_x / fract->h / 2.0;
	return (TRUE);
}

int			init(t_fract *fract)
{
	ft_setparam_int(fract->arg, "threads", &(fract->nb_threads), NB_THREADS);
	ft_setparam_int(fract->arg, "iter", &(fract->iter_max), ITER);
	ft_setparam_int(fract->arg, "speed", &(fract->speed), SPEED);
	ft_setparam_doubleint(fract->arg, "size-win", &(fract->size_win_x), SIZE_X);
	ft_setparam_doubleint(fract->arg, "size-win", &(fract->size_win_y), SIZE_Y);
	if (!ft_strcmp(fract->arg->data_param->content, "burn"))
		init_fract(fract, BURN);
	else if (!ft_strcmp(fract->arg->data_param->content, "julia"))
		init_fract(fract, JULIA);
	else
		init_fract(fract, MANDEL);
	fract->color = 3;
	if ((!init_mlx(fract)))
		return (FALSE);
	return (TRUE);
}

int			init_mlx(t_fract *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		return (FALSE);
	fract->win = mlx_new_window(fract->mlx, fract->size_win_x,
			fract->size_win_y, "fract_ol");
	mlx_expose_hook(fract->win, expose_win, fract);
	mlx_key_hook(fract->win, key_win, fract);
	mlx_hook(fract->win, MOTION_NOTIFY, PTR_MOTION_MASK, motion_win, fract);
	mlx_mouse_hook(fract->win, mouse_win, fract);
	return (TRUE);
}
