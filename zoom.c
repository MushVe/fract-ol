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

#include "fractol.h"

void	zoom(t_param *p, int id)
{
	double	re_m;
	double	im_m;
	double	it;

	re_m = p->mx / (W_X / (p->re_max - p->re_min)) + p->re_min;
	im_m = p->my / (W_Y / (p->im_max - p->im_min)) + p->im_min;
	if (id == 1)
		it = 1.0 / 1.02;
	else
		it = 1.0 * 1.02;
	p->re_min = re_m + ((p->re_min - re_m) * it);
	p->re_max = re_m + ((p->re_max - re_m) * it);
	p->im_min = im_m + ((p->im_min - im_m) * it);
	p->im_max = im_m + ((p->im_max - im_m) * it);
}

int		auto_zoom(t_param *p)
{
	if (p->zoom == 1)
		zoom(p, 1);
	if (p->zoom == 0)
		zoom(p, 0);
	expose_hook(p);
	return (0);
}
