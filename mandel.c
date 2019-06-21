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
	double	re_tmp;
	double	im_tmp;

	while (++n < p->max_iter)
	{
		re_tmp = p->re->z * p->re->z;
		im_tmp = p->im->z * p->im->z;
		if (re_tmp + im_tmp > 4)
		{
			put_color_regular(p, ((p->y0 * W_HEI) + p->x0) * 4, n);
			return ;
		}
		p->im->z = 2 * p->re->z * p->im->z + p->im->c;
		p->re->z = re_tmp - im_tmp + p->re->c;
	}
}

void	mandelbrot(t_param *p)
{
	p->y0 = -1;
	while (++p->y0 < W_HEI)
	{
		p->im->c = p->im->max - p->y0 * p->im->f;
		p->x0 = -1;
		while (++p->x0 < W_LEN)
		{
			p->re->c = p->re->min + p->x0 * p->re->f;
			p->re->z = p->re->c;
			p->im->z = p->im->c;
			mandel_suite(p, -1);
		}
	}
}

// static void		mandel_suite(t_param *p)
// {
// 	p->iter = 0;
// 	while (p->zr * p->zr + p->zi * p->zi < 60 && p->iter < p->max_iter)
// 	{
// 		p->tmp = p->zr;
// 		p->zr = p->zr * p->zr - p->zi * p->zi + p->cr;
// 		p->zi = 2 * p->zi * p->tmp + p->ci;
// 		p->iter++;
// 	}
// }

// void	mandelbrot(t_param *p)
// {
// 	int		x;
// 	int		y;

// 	x = p->x0 - 1;
// 	y = p->y0 - 1;
// 	while (++x < W_HEI + p->x0)
// 	{
// 		while (++y < W_LEN + p->y0)
// 		{
// 			p->cr = x / (W_HEI / p->x2 - p->x1) + p->x1;
// 			p->ci = y / (W_LEN / p->y2 - p->y1) + p->y1;
// 			p->zr = 0;
// 			p->zi = 0;
// 			mandel_suite(p);
// 			if (p->iter < p->max_iter)
// 				put_color_regular(p, x - p->x0, y - p->y0);
// 			else
// 				put_color_no(p, x - p->x0, y - p->y0);
// 		}
// 		y = p->y0;
// 	}
// }