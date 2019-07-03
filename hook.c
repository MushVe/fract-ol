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

void	slide(t_param *p, int key)
{
	if (key == 116)
		p->zoom = 1;
	if (key == 121)
		p->zoom = 0;
	if (key == 119)
		p->zoom = -1;
	if (key == 33)
		p->id_color = 0;
	if (key == 30)
		p->id_color = 1;
	if (key == 42)
		p->id_color = 2;
	if (key == 35)
		p->id_color = 3;
	if (key == 43)
		p->n_multi += 1;
	if (key == 47)
		p->n_multi -= 1;
	if (key == 115)
		init_param(p);
	expose_hook(p);
}

int		key_hook(int key, t_param *p)
{
	if (key == 53)
		put_exit("exit ./fdf");
	if (key == 69)
		p->max_iter += 10;
	if (key == 78)
		p->max_iter -= 10;
	if (key == 83)
	{
		p->id_set = 1;
		init_param(p);
	}
	if (key == 84)
	{
		p->id_set = 2;
		init_param(p);
	}
	if (key == 85)
	{
		p->id_set = 3;
		init_param(p);
	}
	if (key == 86)
	{
		p->id_set = 4;
		init_param(p);
	}
	if (key == 82)
		p->m_julia = !p->m_julia;
	slide(p, key);
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

int		mouse_hook(int button, int x, int y, t_param *p)
{
	if (p->id_set == 1 && p->m_julia == 0)
		return (0);
	p->mx = x;
	p->my = y;
	if (button == 4)
		zoom(p, 1);
	if (button == 5)
		zoom(p, 0);
	expose_hook(p);
	return (0);
}

int		julia_mouse(int x, int y, t_param *p)
{
	if (((x < 0 || x > W_X || y < 0 || y > W_Y) && p->id_set == 1)
		|| p->m_julia == 0)
		return (0);
	p->mx = x;
	p->my = y;
	expose_hook(p);
	return (0);
}
