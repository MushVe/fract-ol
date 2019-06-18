/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:33:14 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/11 18:28:20 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_regular(t_param *p, int incr, int n)
{
	p->img_data[incr] = (p->blue * n / p->max_iter);
	p->img_data[incr + 1] = (p->green * n / p->max_iter);
	p->img_data[incr + 2] = (p->red * n / p->max_iter);
	p->img_data[incr + 3] = 0x00;
}

void	put_color_smooth(t_param *p, int incr, int n)
{
	p->img_data[incr] = (p->blue * n / p->max_iter);
	p->img_data[incr + 1] = (p->green * n / p->max_iter);
	p->img_data[incr + 2] = (p->red * n / p->max_iter);
	p->img_data[incr + 3] = 0x00;
}
