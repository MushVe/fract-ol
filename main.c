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
	p->radius = 2;
	p->c_var.a = 1;
	p->c_var.b = 1;
	p->max_iter = 10;
	p->min_real = -2.0;
	p->max_real = 1.0;
	p->min_img = -1.2;
	p->max_img = p->min_img + (p->max_real - p->min_real) * W_HEI / W_LEN;
	p->red = 80;
	p->green = 160;
	p->blue = 255;
	p->f_real = (p->max_real - p->min_real) / (W_LEN - 1);
	p->f_img = (p->max_img - p->min_img) / (W_HEI - 1);
}

int		main(int ac, char **av)
{
	t_param	p;

	if (ac != 2)
		put_exit("Select a set:\n1 - Julia\n2 - Mandelbrot\n3 - ...");

	p.id_set = ft_atoi(av[1]);

	init_param(&p);
	ft_putnbr(p.id_set);
	ft_putendl("");
	
	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, W_LEN, W_HEI, "fractol");
	p.img_ptr = mlx_new_image(p.mlx_ptr, W_LEN, W_HEI);
	p.img_data = mlx_get_data_addr(p.img_ptr, &p.bpp, &p.size_line, &p.e);
	mlx_key_hook(p.win_ptr, key_hook, &p);
	mlx_expose_hook(p.win_ptr, expose_hook, &p);
	mlx_loop(p.mlx_ptr);
	return (0);
}
