/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:27:51 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/12 12:14:30 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fractol.h"

int			init(t_fract *fract)
{
	fract->size_win_x = 1920;
	fract->size_win_y = 1080;
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
	return (TRUE);
}
