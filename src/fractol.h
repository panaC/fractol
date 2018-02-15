/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:49:51 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/15 21:17:59 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H

# ifdef __linux__
#  define K_ESCAPE		65307
#  define K_LEFT		65361
#  define K_UP			65362
#  define K_RIGHT		65363
#  define K_DOWN		65364
#  define K_A			'a'
#  define K_Z			'z'
#  define K_S			's'
#  define K_X			'x'
#  define K_H			'h'
#  define K_J			'j'
#  define K_K			'k'
#  define K_L			'l'
# endif
# ifdef __APPLE__
#  define K_ESCAPE		53
#  define K_LEFT		123
#  define K_UP			126
#  define K_RIGHT		124
#  define K_DOWN		125
#  define K_A			0
#  define K_Z			6
#  define K_S			1
#  define K_X			7
#  define K_H			4
#  define K_J			38
#  define K_K			40
#  define K_L			37
# endif
/*
 * ** Key event, Key mask
 * */
#  define PTR_MOTION_MASK (1L<<6)
#  define MOTION_NOTIFY 6
#  define KEY_PRESS_MASK (1L<<0)
#  define KEY_PRESS 2
# define PI				3.14159265358979323846
#

typedef struct				s_img
{
	void					*img;
	char					*addr;
	int						bpp;
	int						size_line;
	int						endian;
}							t_img;

typedef struct				s_fractol
{
	void					*mlx;
	void					*win;
	int						size_win_x;
	int						size_win_y;
	t_img					img;
	double					mouse_x;
	double					mouse_y;
	double					h;
	double					zoom;
}							t_fract;

/*
** init.c
*/

int			init_mlx(t_fract *fract);
int			init(t_fract *fract);

/*
** it.c
*/

int			expose_win(t_fract *fract);
int			key_win(int key, t_fract *fract);
int			mouse_win3(int but, int x, int y, void *p);

/*
** mandelbrot.c
*/

int			draw_mandelbrot(t_fract *fract);

/*
** misc.c
*/

int			free_fract(t_fract **fract);

#endif
