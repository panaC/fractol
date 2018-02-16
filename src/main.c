/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:48:36 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/16 01:54:02 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fractol.h"

int		main(int ac, char **av)
{
	t_fract		*fract;
	if ((!(fract = (t_fract*)ft_memalloc(sizeof(*fract)))))
		return (TRUE);
	if (!check_arg(fract, ac, av))
		return (TRUE);
	if ((!init(fract)))
		return (free_fract(&fract));
	mlx_loop(fract->mlx);
	return (FALSE);
}
