/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:49:51 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/16 10:20:43 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H

#include <libft.h>
#include <arg.h>

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
#  define M_LEFT		1
#  define M_RIGHT		3
#  define M_UP			5
#  define M_DOWN		4
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
#  define K_Q			12
#  define K_W			13
#  define K_E			14
#  define K_R			15
#  define K_T			17
#  define K_Y			16
#  define K_0			82
#  define K_1			83
#  define K_2			84
#  define M_LEFT		1
#  define M_RIGHT		2
#  define M_UP			7
#  define M_DOWN		4
# endif
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2
# define PI				3.14159265358979323846
# define ITER			255
# define SPEED			20
# define SIZE_X			1280
# define SIZE_Y			720
# define MANDEL			1
# define JULIA			2
# define BURN			3

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
	long double				mouse_x;
	long double				mouse_y;
	long double				h;
	long double				zoom;
	int						iter_max;
	int						speed;
	t_arg					*arg;
	int						color;
	long double				julia_r;
	long double				julia_i;
	int						select;
}							t_fract;

typedef struct				s_draw
{
	long double				x1;
	long double				x2;
	long double				y1;
	long double				y2;
	long double				cr;
	long double				ci;
	long double				zr;
	long double				zi;
	int						x;
	int						y;
	int						img_x;
	int						img_y;
}							t_draw;
	

/*
** init.c
*/

int			init_mlx(t_fract *fract);
int			init(t_fract *fract);
int			init_fract(t_fract *fract, int s);

/*
** it.c
*/

int			expose_win(t_fract *fract);
int			key_win(int key, t_fract *fract);
int			mouse_win(int but, int x, int y, void *p);
int			motion_win(int x, int y, void *p);

/*
** mandelbrot.c
*/

int			draw(t_fract *fract);

/*
** misc.c
*/

int			free_fract(t_fract **fract);
int			put_image(t_fract *f, int x, int y, int i);
int			color(t_fract *f, int i, int n);

/*
** arg.c
*/

t_bool		check_arg(t_fract *fract, int ac, char **av);

#endif
