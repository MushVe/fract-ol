/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:33:14 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/11 18:28:20 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_suite(t_param *p, int n)
{
	double	z_rtmp;
	double	z_itmp;

	while (++n < p->max_iter)
	{
		z_rtmp = p->z_real * p->z_real;
		z_itmp = p->z_img * p->z_img;
		if (z_rtmp + z_itmp > 4)
		{
			put_color_regular(p, ((p->y * W_HEI) + p->x) * 4, n);
			return ;
		}
		p->z_img = 2 * p->z_real * p->z_img + p->c_img;
		p->z_real = z_rtmp - z_itmp + p->c_real;
	}
}

void	mandelbrot(t_param *p)
{
	p->y = -1;
	while (++p->y < W_HEI)
	{
		p->c_img = p->max_img - p->y * p->f_img;
		p->x = -1;
		while (++p->x < W_LEN)
		{
			p->c_real = p->min_real + p->x * p->f_real;
			p->z_real = p->c_real;
			p->z_img = p->c_img;
			mandel_suite(p, -1);
		}
	}
}
