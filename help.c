/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:28:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/19 16:19:57 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	printman2(void)
{
	ft_putstr("'1' Julia\t\t\t'Q' Regular\t\t\t");
	ft_putendl("             * * *   * * * * * * * * * * *");
	ft_putstr("'2' Mandelbrot\t\t\t'W' Smooth\t\t\t");
	ft_putendl("           * * * * * * * * * * * * * * * *");
	ft_putstr("'3' BurningShip\t\t\t'E' Psyche\t\t\t");
	ft_putendl(" * * * * * * * * * * * * * * * * * * *");
	ft_putstr("'4' Multibrot\t\t\t'R' Binary\t\t\t");
	ft_putendl("           * * * * * * * * * * * * * * * *");
	ft_putstr("\t\t\t\t\t\t\t\t");
	ft_putendl("             * * *   * * * * * * * * * * *");
	ft_putstr(" #### Other  ####\t\t #### Zoom Options  ####\t");
	ft_putendl("                       * * * * * * * * * *");
	ft_putstr("'+' More Iterations\t\t'Home' Reset Fractal\t\t");
	ft_putendl("                       * * * * * * * * * *");
	ft_putstr("'-' Less Iterations\t\t'Page Up' Auto Zoom In\t\t");
	ft_putendl("                         * * * * * * * * *");
	ft_putstr("'>' Multibrot + 1\t\t'Page Down' Auto Zoom Out\t");
	ft_putendl("                         *   * * * * *");
	ft_putstr("'<' Multibrot - 1\t\t'End' Freeze Zoom\t\t");
	ft_putendl("                               * *");
	ft_putstr("'L' Multibrot * 10\t\t'< ^ v >' Move Around\t\t");
	ft_putendl("                               * *");
	ft_putstr("'K' Multibrot / 10\n'Fn' Freeze Julia Mouse\n\n");
}

void	printman(void)
{
	system("clear");
	ft_putstr("\n                        ..\n");
	ft_putstr("                      / __)  Hi! Welcome to my Fract'ol.\n");
	ft_putstr("               .-^^^-/ /\t\t\t\t\t");
	ft_putendl("                               * *");
	ft_putstr("            __/       /   I'm here to help!\t\t\t");
	ft_putendl("                               * *");
	ft_putstr("           <__.|_|-|_|\t\t\t\t\t\t");
	ft_putendl("                         *   * * * * *");
	ft_putstr("\t\t\t\t\t\t\t\t");
	ft_putendl("                         * * * * * * * * *");
	ft_putstr("\t\t\t\t\t\t\t\t");
	ft_putendl("                       * * * * * * * * * *");
	ft_putstr(" #### Select Set  ####\t\t #### Select Color  ####\t");
	ft_putendl("                       * * * * * * * * * *");
	printman2();
}
