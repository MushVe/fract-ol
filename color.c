/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:33:14 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/11 18:28:20 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_regular(t_param *p, int x, int y)
//void	put_color_regular(t_param *p, int incr, int n)
{
	int incr;

	incr = (x * 4) + (y * p->size_line);
	p->img_data[incr] = 100 - (p->blue * p->iter / p->max_iter);
	p->img_data[incr + 1] = (p->green * p->iter / p->max_iter);
	p->img_data[incr + 2] = 100 + (p->red * p->iter / p->max_iter);
	// p->img_data[incr] = 100 - (p->blue * n / p->max_iter);
	// p->img_data[incr + 1] = (p->green * n / p->max_iter);
	// p->img_data[incr + 2] = 100 + (p->red * n / p->max_iter);
	p->img_data[incr + 3] = 0x00;
}

void	put_color_no(t_param *p, int x, int y)
{
	int incr;

	incr = (x * 4) + (y * p->size_line);
	p->img_data[incr] = 0x00;
	p->img_data[incr + 1] = 0x00;
	p->img_data[incr + 2] = 0x00;
	p->img_data[incr + 3] = 0x00;
}

void	put_color_smooth(t_param *p, int incr, int n)
{
	p->img_data[incr] = (p->blue * n / p->max_iter);
	p->img_data[incr + 1] = (p->green * n / p->max_iter);
	p->img_data[incr + 2] = (p->red * n / p->max_iter);
	p->img_data[incr + 3] = 0x00;
}

void	zoom(t_param *p, int x, int y, int id)
{
	double	mr;
	double	mi;
	double	itrpl;

	p->mx = x;
	p->my = y;
	mr = p->mx / (W_HEI / (p->re->max - p->re->min)) + p->re->min;
	mi = p->my / (W_LEN / (p->im->max - p->im->min)) + p->im->min;
	if (id == 1)
		itrpl = 1.0 / 1.02;
	else
		itrpl = 1.0 * 1.02;
	p->re->min = mr + ((p->re->min - mr) * itrpl);
	p->im->min = mi + ((p->im->min - mi) * itrpl);
	p->re->max = mr + ((p->re->max - mr) * itrpl);
	p->im->max = mi + ((p->im->max - mi) * itrpl);
}
