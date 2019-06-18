/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:50:10 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/09 15:49:24 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	c_add(t_complex x, t_complex y)
{
	t_complex c;

	c.a = x.a + y.a;
	c.b = x.b + y.b;
	return (c);
}

t_complex	c_sqr(t_complex n)
{
	t_complex c;

	c.a = n.a * n.a - n.b * n.b;
	c.b = 2 * n.a * n.b;
	return (c);
}

t_complex	c_map(int x, int y, t_param *p)
{
	t_complex	c;
	int			l;

	l = (W_LEN < W_HEI) ? W_LEN : W_HEI;
	c.a = 2 * p->radius * (x - W_LEN / 2.0) / l;
	c.b = 2 * p->radius * (y - W_HEI / 2.0) / l;
	return (c);
}

void		julia(t_param *p)
{
	int x;
	int y;
	int iter;
	t_complex z0;
	t_complex z1; 

	x = -1;
	y = -1;
	iter = 0;

	while (++x < W_LEN)
	{
		while (++y < W_HEI)
		{
			z0 = c_map(x, y, p);
			while (++iter < 3)
			{
				z1 = c_add(c_sqr(z0), p->c_var);
				if (ft_sqrt(z1.a * z1.a + z1.b * z1.b) > p->radius)
				{
					put_color_regular(p, ((y * W_HEI) + x) * 4, 0);
					break;
				}
				z0 = z1;
			}
			if (iter > 3)
				put_color_regular(p, ((y * W_HEI) + x) * 4, 0);
		}
	}
}
