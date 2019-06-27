/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 05:21:59 by cseguier          #+#    #+#             */
/*   Updated: 2019/06/23 05:01:46 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_absd(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static void		ship_suite(t_param *p)
{
	p->iter = 0;
	while (p->re_z * p->re_z + p->im_z * p->im_z < 60 && p->iter < p->max_iter)
	{
		p->tmp = p->re_z;
		p->re_z = p->re_z * p->re_z - p->im_z * p->im_z + p->re_c;
		p->im_z = 2 * ft_absd(p->im_z * p->tmp) + p->im_c;
		p->iter++;
	}
}

void			burningship(t_param *p)
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
			ship_suite(p);
			if (p->iter < p->max_iter)
				put_color_regular(p, x, y);
			else
				put_color_no(p, x, y);
		}
	}
}
