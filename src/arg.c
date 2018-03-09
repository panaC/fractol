/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 23:39:29 by pleroux           #+#    #+#             */
/*   Updated: 2018/03/09 10:32:37 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arg.h>
#include <libft.h>
#include "fractol.h"

static t_bool		error_arg(t_string s)
{
	ft_putstr("Usage ");
	ft_putstr(s);
	ft_putstr(" [option] fractal\n\n");
	ft_putstr("Fractal explorer\n"
			"fractal : mandelbrot / julia / burn\n\n");
	ft_putstr(" OPTIONS :        \n"
			" --iter=NUM\t\tNumber of iteration fractal suit\n"
			" --speed=NUM\t\tSpeed between 10 to 20\n"
			" --size-win=NUM,NUM\tWindow size by x,y\n"
			" --threads=NUM\t\tNumber of threads between 4 to 200\n"
			" --help\t\t\tThis help\n\n"
			" CONTROLS :\n"
			" q-w-e-r-t-y-u-i-o-p :\n"
			"\tChange the color\n"
			" Mouse left-right click :\n"
			"\tzoom In or Out\n");
	return (FALSE);
}

static t_list		*set_arg(void)
{
	t_list			*lst;

	lst = NULL;
	ft_lstaddstr(&lst, "iter");
	ft_lstaddstr(&lst, "speed");
	ft_lstaddstr(&lst, "size-win");
	ft_lstaddstr(&lst, "threads");
	ft_lstaddstr(&lst, "help");
	return (lst);
}

t_bool				check_arg(t_fract *fract, int ac, char **av)
{
	if ((!(fract->arg = ft_get_arg(ac, av))))
		return (FALSE);
	if (!fract->arg->state || ft_lstlen(fract->arg->data_param) != 1 ||
			!ft_check_longparam(fract->arg->long_param, set_arg(), TRUE))
		return (error_arg(av[0]));
	if (ft_search_param(fract->arg->long_param, NULL, "help"))
		return (error_arg(av[0]));
	if (!(!ft_strcmp(fract->arg->data_param->content, "mandelbrot") ||
			!ft_strcmp(fract->arg->data_param->content, "julia") ||
			!ft_strcmp(fract->arg->data_param->content, "burn")))
		return (error_arg(av[0]));
	return (TRUE);
}
