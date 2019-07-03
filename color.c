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
{
	int incr;

	incr = (x * 4) + (y * p->size_line);
	p->img_data[incr] = p->bn + p->bi * (p->b * p->iter / p->max_iter);
	p->img_data[incr + 1] = p->gn + p->gi * (p->g * p->iter / p->max_iter);
	p->img_data[incr + 2] = p->rn + p->ri * (p->r * p->iter / p->max_iter);
	p->img_data[incr + 3] = 0x00;
}

void	put_color_random(t_param *p, int x, int y)
{
	int incr;
	int re;

	re = (W_X / (p->re_max - p->re_min)) - (W_Y / (p->im_max - p->im_min));
	incr = (x * 4) + (y * p->size_line);
	p->img_data[incr] = (p->iter * re) / 2;
	p->img_data[incr + 1] = (p->iter * re) / 3;
	p->img_data[incr + 2] = (p->iter * re) / 4;
	p->img_data[incr + 3] = 0x00;
}

/*
**	(rand() % 255);
*/

void	put_color_no(t_param *p, int x, int y)
{
	int incr;
	int	c;

	c = 0x00;
	if (p->id_color == 0)
		c = 0xFF;
	incr = (x * 4) + (y * p->size_line);
	p->img_data[incr] = c;
	p->img_data[incr + 1] = c;
	p->img_data[incr + 2] = c;
	p->img_data[incr + 3] = 0x00;
}

void	put_color_smooth(t_param *p, int x, int y)
{
	int		incr;
	double	i;
	double	log_zn;
	double	nu;

	log_zn = log(p->re_z * p->re_z + p->im_z * p->im_z) / 2;
	nu = log(log_zn / log(2)) / log(2);
	i = p->iter + 1 - nu;
	i = i / p->max_iter;
//	i = i / (p->my * p->mx);
	incr = (x * 4) + (y * p->size_line);
	p->img_data[incr] = (int)(8.5 * (1 - i) * (1 - i) * (1 - i) * i * 255);
	p->img_data[incr + 1] = (int)(15 * (1 - i) * (1 - i) * i * i * 255);
	p->img_data[incr + 2] = (int)(9 * (1 - i) * i * i * i * 255);
	p->img_data[incr + 3] = 0;
}

void	put_color_ship(t_param *p, int x, int y)
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

void	put_color_chess(t_param *p, int x, int y)
{
	int		incr;
	int		c;

	incr = (x * 4) + (y * p->size_line);
	if (p->iter == p->max_iter)
		c = 0x00;
	else if (p->im_z > 0)
		c = 0x00;
	else
		c = 255;
	p->img_data[incr] = c;
	p->img_data[incr + 1] = c;
	p->img_data[incr + 2] = c;
	p->img_data[incr + 3] = 0;
}