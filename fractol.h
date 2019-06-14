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

typedef struct	s_complex
{
	double	a;
	double	b;
}				t_complex;

typedef struct	s_param
{
	int			id_set;
	double		radius;

	t_complex	c_var;

	char		*img_data;
	int			bpp;
	int			size_line;
	int			e;
	void		*img_ptr;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_param;

void			put_exit(char *msg);
void			put_data(t_param *p, int incr);
int				key_hook(int key, void *p);
int				expose_hook(t_param *p);
void			julia(t_param *p);
void			mandelbrot(t_param *p);

#endif
