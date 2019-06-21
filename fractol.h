/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:28:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/19 16:19:57 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"

# define W_LEN 1000
# define W_HEI 1000

typedef struct	s_re
{
	double	max;
	double	min;
	double	c;
	double	z;
	double	f;
}				t_re;

typedef struct	s_im
{
	double	max;
	double	min;
	double	c;
	double	z;
	double	f;
}				t_im;

typedef struct	s_param
{
	double		radius;
	int			id_set;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		tmp;
	int			max_iter;
	int			iter;
	int			x0;
	int			y0;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	int			mx;
	int			my;
	int			red;
	int			green;
	int			blue;

	t_re		*re;
	t_im		*im;

	char		*img_data;
	int			bpp;
	int			size_line;
	int			e;
	void		*img_ptr;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_param;

void			put_exit(char *msg);
void			put_color_regular(t_param *p, int x, int y);
void			put_color_no(t_param *p, int x, int y);
int				key_hook(int key, void *p);
int				mouse_hook(int button, int x, int y, t_param *param);
int				expose_hook(t_param *p);
void			zoom(t_param *p, int x, int y, int id);
void			julia(t_param *p);
void			mandelbrot(t_param *p);

#endif
