/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:50:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/11 18:06:40 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	ft_putstr("re_min: "); ft_putnbr((int)(100 * p->re_min));
**	ft_putstr("\t\t");
**	ft_putstr("re_max: "); ft_putnbr((int)(100 * p->re_max));
**	ft_putstr("\n");
**	ft_putstr("im_min: "); ft_putnbr((int)(100 * p->im_min));
**	ft_putstr("\t\t");
**	ft_putstr("im_max: "); ft_putnbr((int)(100 * p->im_max));
**	ft_putstr("\n+++++++++++++++++++++++++++++++\n");
*/

int		expose_hook(t_param *p)
{
	ft_bzero(p->img_data, W_X * W_Y * p->bpp / 8);
	if (p->id_set == 1)
		julia(p);
	if (p->id_set == 2)
		mandelbrot(p);
	if (p->id_set == 3)
		burningship(p);
	if (p->id_set == 4)
		multibrot(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	return (0);
}

/*
**	if (key == 12)
**		p->re_min += 0.1;
**	if (key == 0)
**		p->re_min -= 0.1;
**	if (key == 13)
**		p->re_max += 0.1;
**	if (key == 1)
**		p->re_max -= 0.1;
**	if (key == 14)
**		p->im_min += 0.1;
**	if (key == 2)
**		p->im_min -= 0.1;
**	if (key == 15)
**		p->im_max += 0.1;
**	if (key == 3)
**		p->im_max -= 0.1;
*/

void	slide_next2(t_param *p, int key)
{
	if (key == 123)
	{
		p->re_min -= 0.1 / p->i_zoom;
		p->re_max -= 0.1 / p->i_zoom;
	}
	if (key == 124)
	{
		p->re_min += 0.1 / p->i_zoom;
		p->re_max += 0.1 / p->i_zoom;
	}
	if (key == 125)
	{
		p->im_min += 0.1 / p->i_zoom;
		p->im_max += 0.1 / p->i_zoom;
	}
	if (key == 126)
	{
		p->im_min -= 0.1 / p->i_zoom;
		p->im_max -= 0.1 / p->i_zoom;
	}
}

void	slide_next(t_param *p, int key)
{
	if (key == 47)
		p->n_multi += 1;
	if (key == 43)
	{
		p->n_multi -= 1;
		if (p->n_multi <= 2)
			p->n_multi = 2;
	}
	if (key == 37)
		p->n_multi *= 10;
	if (key == 40)
	{
		p->n_multi /= 10;
		if (p->n_multi <= 2)
			p->n_multi = 2;
	}
	if (key == 115)
		init_param(p);
	if (key == 279)
		p->m_julia = !p->m_julia;
	slide_next2(p, key);
}

void	slide(t_param *p, int key)
{
	if (key == 69)
		p->max_iter += 10;
	if (key == 78)
		p->max_iter -= 10;
	if (key == 116)
		p->zoom = 1;
	if (key == 121)
		p->zoom = 0;
	if (key == 119)
		p->zoom = -1;
	if (key == 12)
		p->id_color = 0;
	if (key == 13)
		p->id_color = 1;
	if (key == 14)
		p->id_color = 2;
	if (key == 15)
		p->id_color = 3;
	slide_next(p, key);
}

int		key_hook(int key, t_param *p)
{
	if (key == 53)
		put_exit(2);
	if (key == 18)
	{
		p->id_set = 1;
		init_param(p);
	}
	if (key == 19)
	{
		p->id_set = 2;
		init_param(p);
	}
	if (key == 20)
	{
		p->id_set = 3;
		init_param(p);
	}
	if (key == 21)
	{
		p->id_set = 4;
		init_param(p);
	}
	slide(p, key);
	expose_hook(p);
	return (0);
}

/*
** mouse inputs
**   -------
**  |   4   |
**  | 1 3 2 |
**  |   5   |
**   -------
*/
