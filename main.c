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

void	init_param(t_param *p, t_im	*im, t_re *re)
{
	p->re = re;
	p->im = im;

	p->max_iter = 30;

//	p->re->min = -2.3;
//	p->re->max = 0.7;
//	p->im->min = -1.5;
//	p->im->max = p->im->min + (p->re->max - p->re->min) * W_HEI / W_LEN;
//	p->re->f = (p->re->max - p->re->min) / (W_LEN - 1);
//	p->im->f = (p->im->max - p->im->min) / (W_HEI - 1);

	p->x0 = 0;
	p->y0 = 0;
	p->re->min = -2.2;
	p->re->max = 3;
	p->im->min = -1.4;
	p->im->max = 3;

	p->red = 155;
	p->green = 255;
	p->blue = 100;
}

int		main(int ac, char **av)
{
	t_param	p;
	t_im	im;
	t_re	re;

	if (ac != 2)
		put_exit("Select a set:\n1 - Julia\n2 - Mandelbrot\n3 - ...");
	p.id_set = ft_atoi(av[1]);
	init_param(&p, &im, &re);
	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, W_LEN, W_HEI, "fractol");
	p.img_ptr = mlx_new_image(p.mlx_ptr, W_LEN, W_HEI);
	p.img_data = mlx_get_data_addr(p.img_ptr, &p.bpp, &p.size_line, &p.e);
	mlx_key_hook(p.win_ptr, key_hook, &p);
	mlx_mouse_hook(p.win_ptr, mouse_hook, &p);
	mlx_expose_hook(p.win_ptr, expose_hook, &p);
	mlx_loop(p.mlx_ptr);
	return (0);
}
