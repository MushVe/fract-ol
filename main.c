/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:33:14 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/11 18:28:20 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_exit(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

void	init_param(t_param *p)
{
	p->max_iter = 30;

	// p->re->min = -2.3;
	// p->re->max = 0.7;
	// p->re->min = -1.5;
	// p->im->max = p->re->min + (p->re->max - p->re->min) * W_HEI / W_LEN;

	p->re_min = -2.2;
	p->re_max = 3.7;
	p->im_min = -1.3;
	p->im_max = 2.6;

	// p->re_min = -2.5;
	// p->re_max = 1;
	// p->im_min = -1;
	// p->im_max = 1;

	p->re_c = 0;
	p->re_z = 0;
	p->re_f = 0;
	p->im_c = 0;
	p->im_z = 0;
	p->im_f = 0;

	p->red = 155;
	p->green = 255;
	p->blue = 100;
}

int		main(int ac, char **av)
{
	t_param	p;

	if (ac != 2)
		put_exit("Select a set:\n1 - Julia\n2 - Mandelbrot\n3 - ...");
	p.id_set = ft_atoi(av[1]);
	init_param(&p);
	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, W_X, W_Y, "fractol");
	p.img_ptr = mlx_new_image(p.mlx_ptr, W_X, W_Y);
	p.img_data = mlx_get_data_addr(p.img_ptr, &p.bpp, &p.size_line, &p.e);
	mlx_key_hook(p.win_ptr, key_hook, &p);
	mlx_mouse_hook(p.win_ptr, mouse_hook, &p);
	mlx_expose_hook(p.win_ptr, expose_hook, &p);
	mlx_loop(p.mlx_ptr);
	return (0);
}
