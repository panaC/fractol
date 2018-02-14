/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:27:51 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/14 20:08:23 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fractol.h"

int			init(t_fract *fract)
{
	fract->size_win_x = 1920;
	fract->size_win_y = 1080;
	fract->h = 4;
	fract->mouse_x = 0.0;
	fract->mouse_y = 0.0;
	fract->zoom = fract->size_win_x / fract->h / 2;
	if ((!init_mlx(fract)))
		return (FALSE);
	return (TRUE);
}

int			init_mlx(t_fract *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		return (FALSE);
	fract->win = mlx_new_window(fract->mlx, fract->size_win_x, fract->size_win_y,
			"fract_ol");
	mlx_expose_hook(fract->win, expose_win, fract);
	mlx_key_hook(fract->win, key_win, fract);

	mlx_hook(fract->win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_win3, fract);


	/****/


	return (TRUE);
}
