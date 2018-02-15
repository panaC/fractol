/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:48:36 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/15 11:01:43 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fractol.h"

int		main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	ac = 0;
	av = NULL;
	t_fract		*fract;
	if ((!(fract = (t_fract*)ft_memalloc(sizeof(*fract)))))
		return (TRUE);
	if ((!init(fract)))
		return (TRUE);
	mlx_loop(fract->mlx);
	return (FALSE);
}
