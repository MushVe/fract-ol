/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 05:21:59 by cseguier          #+#    #+#             */
/*   Updated: 2019/06/23 05:01:46 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_julia(t_param *p)
{
	p->name = ft_strdup("Fract'ol : Julia");
	p->m_julia = 1;
	p->re_min = -1.9;
	p->re_max = 1.9;
	p->im_min = -2.0;
	p->im_max = 2.2;
	p->re_c = 0.4;
	p->im_c = 0.2;
	p->red = 255;
	p->green = 255;
	p->blue = 255;
}

static void	init_mandel(t_param *p)
{
	p->name = ft_strdup("Fract'ol : Mandelbrot");
	p->m_julia = 0;
	p->re_min = -2.4;
	p->re_max = 1;
	p->im_min = -1.2;
	p->im_max = 1.2;
	p->re_c = 0;
	p->im_c = 0;
	p->red = 255;
	p->green = 255;
	p->blue = 255;
}

static void	init_ship(t_param *p)
{
	p->name = ft_strdup("Fract'ol : Burning Ship");
	p->m_julia = 0;
	p->re_min = -2.4;
	p->re_max = 1.2;
	p->im_min = -2.0;
	p->im_max = 1.0;
	p->re_c = 0;
	p->im_c = 0;
	p->red = 255;
	p->green = 100;
	p->blue = 20;
}

void		init_param(t_param *p)
{
	p->max_iter = 30;
	p->re_z = 0;
	p->im_z = 0;
	p->tmp = 0;
	p->mx = 0;
	p->my = 0;
	if (p->id_set == 1)
		init_julia(p);
	else if (p->id_set == 2)
		init_mandel(p);
	else if (p->id_set == 3)
		init_ship(p);
	else
		put_exit("Select a set:\n1 - Julia\n2 - Mandelbrot\n3 - BurningShip");
}
