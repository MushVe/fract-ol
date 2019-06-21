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

//	if (p->id_set == 1)
//		julia(p);
	p->x0 = 0;
	p->y0 = 0;

	ft_putstr("x0: "); ft_putnbr((int)(100 * p->x0));
	ft_putstr("\t\t"); 
	ft_putstr("y0: "); ft_putnbr((int)(100 * p->y0));
	ft_putstr("\n"); 
	ft_putstr("re.min: "); ft_putnbr((int)(100 * p->re->min));
	ft_putstr("\t\t"); 
	ft_putstr("re->max: "); ft_putnbr((int)(100 * p->re->max));
	ft_putstr("\n"); 
	ft_putstr("im->min: "); ft_putnbr((int)(100 * p->im->min));
	ft_putstr("\t\t"); 
	ft_putstr("im->max: "); ft_putnbr((int)(100 * p->im->max));
	ft_putstr("\n"); 
	ft_putstr("mx: "); ft_putnbr((int)(100 * p->mx));
	ft_putstr("\t\t"); 
	ft_putstr("my: "); ft_putnbr((int)(100 * p->my));
	ft_putstr("\n++++++++++++++++++++++++++++\n"); 

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
	if (key == 126)
		p->y1 += 0.1;
	if (key == 125)
		p->y1 -= 0.1;
	if (key == 123)
		p->y2 += 0.1;
	if (key == 124)
		p->y2 -= 0.1;
	if (key == 91)
		p->x1 += 0.1;
	if (key == 87)
		p->x1 -= 0.1;
	if (key == 92)
		p->x2 += 0.1;
	if (key == 88)
		p->x2 -= 0.1;
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
	if (button == 1)
		p->x1 += 0.1;
	if (button == 2)
		p->x1 -= 0.1;
	if (button == 3)
		;
	if (button == 4)
		zoom(p, x, y, 0);
	if (button == 5)
		zoom(p, x, y, 1);

	
	expose_hook(p);
	return (0);
}
