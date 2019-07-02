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

static void	mandel_suite(t_param *p)
{
	p->iter = 0;
	while (p->re_z * p->re_z + p->im_z * p->im_z < 60 && p->iter < p->max_iter)
	{
		p->tmp = p->re_z;
		p->re_z = p->re_z * p->re_z - p->im_z * p->im_z + p->re_c;
		p->im_z = 2 * p->im_z * p->tmp + p->im_c;
		p->iter++;
	}
}

void		mandelbrot(t_param *p)
{
	int		x;
	int		y;

	x = -1;
	while (++x < W_X)
	{
		y = -1;
		while (++y < W_Y)
		{
			p->re_c = x / (W_X / (p->re_max - p->re_min)) + p->re_min;
			p->im_c = y / (W_Y / (p->im_max - p->im_min)) + p->im_min;
			p->re_z = 0;
			p->im_z = 0;
			mandel_suite(p);
			if (p->iter < p->max_iter)
				put_color(p, x, y);
			else
				put_color_no(p, x, y);
		}
	}
}
