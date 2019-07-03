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

void	put_color(t_param *p, int x, int y)
{
	if (p->id_color == 1 && p->id_set != 3)
		put_color_smooth(p, x, y);
	else if (p->id_color == 1 && p->id_set == 3)
		put_color_ship(p, x, y);
	else if (p->id_color == 2)
		put_color_random(p, x, y);
	else if (p->id_color == 3)
		put_color_chess(p, x, y);
	else
		put_color_regular(p, x, y);
}

int		main(int ac, char **av)
{
	t_param	p;

	if (ac != 2)
		put_exit("Select a set:\n1 - Julia\n2 - Mandelbrot\n\
		3 - BurningShip\n4 - Multibrot\n");
	p.id_set = ft_atoi(av[1]);
	init_param(&p);
	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, W_X, W_Y, "Fractol");
	p.img_ptr = mlx_new_image(p.mlx_ptr, W_X, W_Y);
	p.img_data = mlx_get_data_addr(p.img_ptr, &p.bpp, &p.size_line, &p.e);
	mlx_hook(p.win_ptr, 6, (1L << 6), &julia_mouse, &p);
	mlx_key_hook(p.win_ptr, key_hook, &p);
	mlx_mouse_hook(p.win_ptr, mouse_hook, &p);
	mlx_expose_hook(p.win_ptr, expose_hook, &p);
	mlx_loop_hook(p.mlx_ptr, auto_zoom, &p);
	mlx_loop(p.mlx_ptr);
	return (0);
}
