/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:50:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/11 18:06:40 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	multi_suite(t_param *p)
{
	double	repow;
	double	impow;

	p->iter = 0;
	while (p->re_z * p->re_z + p->im_z * p->im_z < 60 && p->iter < p->max_iter)
	{
		repow = ft_pow(p->re_z * p->re_z + p->im_z * p->im_z, p->n_multi / 2);
		impow = ft_pow(p->re_z * p->re_z + p->im_z * p->im_z, p->n_multi / 2);
		p->tmp = repow * cos(p->n_multi * atan2(p->im_z, p->re_z)) + p->re_c;
		p->im_z = impow * sin(p->n_multi * atan2(p->im_z, p->re_z)) + p->im_c;
		p->re_z = p->tmp;
		p->iter++;
	}
}

void		multibrot(t_param *p)
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
			multi_suite(p);
			if (p->iter < p->max_iter)
				put_color(p, x, y);
			else
				put_color_no(p, x, y);
		}
	}
}
