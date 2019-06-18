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

int		expose_hook(t_param *p)
{
	ft_bzero(p->img_data, W_LEN * W_HEI * p->bpp / 8);

	if (p->id_set == 1)
		julia(p);
	if (p->id_set == 2)
		mandelbrot(p);
//	if (p->id_set == 3)
//		vacant();
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	return (0);
}

void	slide(t_param *p, int key)
{
	if (key == 69)
		p->max_iter += 10;
	if (key == 78)
		p->max_iter -= 10;
	expose_hook(p);
}

int		key_hook(int key, void *p)
{
	if (key == 53)
		put_exit("exit ./fdf");
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
	(void)x;
	(void)y;
	if (button == 1)
		;
	if (button == 2)
		;
	if (button == 3)
		;
	if (button == 4)
		;
	if (button == 5)
		;
	expose_hook(p);
	return (0);
}
