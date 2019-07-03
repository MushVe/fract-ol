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
				put_color(p, x, y);
			else
				put_color_no(p, x, y);
		}
	}
}

void			put_color_ship(t_param *p, int x, int y)
{
	int		incr;
	double	i;
	double	log_zn;
	double	nu;

	log_zn = log(p->re_z * p->re_z + p->im_z * p->im_z) / 2;
	nu = log(log_zn / log(2)) / log(2);
	i = p->iter + 1 - nu;
	i = i / p->max_iter;
	incr = (x * 4) + (y * p->size_line);
	p->img_data[incr] = (int)(9 * (1 - i) * i * i * i * 255);
	p->img_data[incr + 1] = (int)(15 * (1 - i) * (1 - i) * i * i * 255);
	p->img_data[incr + 2] = (int)(8.5 * (1 - i) * (1 - i) * (1 - i) * i * 255);
	p->img_data[incr + 3] = 0;
}
