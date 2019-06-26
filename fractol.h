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

# define W_X 600
# define W_Y 400

typedef struct	s_param
{
	double		re_max;
	double		re_min;
	double		re_c;
	double		re_z;

	double		im_max;
	double		im_min;
	double		im_c;
	double		im_z;

	int			mx;
	int			my;

	int			id_set;
	double		tmp;
	int			max_iter;
	int			iter;
	int			red;
	int			green;
	int			blue;

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
int				key_hook(int key, t_param *p);
int				mouse_hook(int button, int x, int y, t_param *param);
int				expose_hook(t_param *p);
void			zoom(t_param *p, int id);
void			julia(t_param *p);
void			mandelbrot(t_param *p);

#endif
