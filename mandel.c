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

void	mandelbrot(t_param *p)
{
	double	min_real;
	double	max_real;
	double	min_img;
	double	max_img;
	double	f_real;
	double	f_img;
	double	c_real;
	double	c_img;
	double	z_real;
	double	z_img;
	double	z_real2;
	double	z_img2;
	int		max_iter;
	int		x;
	int		y;
	int		n;
	char	inside;

	min_real = -2.0;
	max_real = 1.0;
	min_img = -1.2;
	max_img = min_img + (max_real - min_real) * W_HEI / W_LEN;
	f_real = (max_real - min_real) / (W_LEN - 1);
	f_img = (max_img - min_img) / (W_HEI - 1);
	max_iter = 10;

//	ft_putendl("000");

	y = -1;
	while (++y < W_HEI)
	{
		x = -1;
		while (++x < W_LEN)
		{
			if (y % 100 == 0 || x % 100 == 0)
				put_data(p, ((y * W_HEI) + x) * 4);
		}
	}

//	ft_putendl("111");

	y = -1;
	while (++y < W_HEI)
	{
		c_img = max_img - y * f_img;
		x = -1;
		while (++x < W_LEN)
		{
			c_real = min_real + x * f_real;
			z_real = c_real;
			z_img = c_img;
			inside = 1;
			n = -1;
			while (++n < max_iter)
			{
			// 	ft_putstr("\t"); ft_putnbr(x);
			// 	ft_putstr("\t:\t"); ft_putnbr(y);
			// 	ft_putstr("\t:\t"); ft_putnbr(n); ft_putstr("\n");
				z_real2 = z_real * z_real;
				z_img2 = z_img * z_img;
				if(z_real2 + z_img2 > 4)
				{
					inside = 0;
					break;
				}
				z_img = 2 * z_real * z_img + c_img;
				z_real = z_real2 - z_img2 + c_real;
			}
			
			if (inside) 
				put_data(p, ((y * W_HEI) + x) * 4);
		}
	}
}