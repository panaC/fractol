/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:14:25 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/15 21:28:00 by pleroux          ###   ########.fr       */
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
