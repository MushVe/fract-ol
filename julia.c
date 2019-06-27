/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:50:10 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/09 15:49:24 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_suite(t_param *p)
{
	double tmp;

	p->iter = 0;
	while (p->re_z * p->re_z + p->im_z * p->im_z < 4 && p->iter < p->max_iter)
	{
		p->tmp = p->re_z;
		tmp = p->mx / (double)100 + p->re_min;
		p->re_z = p->re_z * p->re_z - p->im_z * p->im_z + tmp;
		tmp = p->my / (double)100 + p->im_min;
		p->im_z = 2 * p->im_z * p->tmp + tmp;
		p->iter++;
	}
}

void		julia(t_param *p)
{
	int x;
	int y;

	x = -1;
	while (++x < W_X)
	{
		y = -1;
		while (++y < W_Y)
		{
			p->re_z = x / (W_X / (p->re_max - p->re_min)) + p->re_min;
			p->im_z = y / (W_Y / (p->im_max - p->im_min)) + p->im_min;
			julia_suite(p);
			if (p->iter != p->max_iter)
				put_color_regular(p, x, y);
			else
				put_color_no(p, x, y);
		}
	}
}
