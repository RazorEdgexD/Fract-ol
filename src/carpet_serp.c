/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet_serp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 12:47:56 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/16 12:47:58 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_carp(t_frac *frac)
{
	frac->draw.point1.x = (-1. * WIN_X * frac->zoom) / 4 +
		(WIN_X / 2) - (frac->m_shx * WIN_X * frac->zoom) / 4 - frac->shiftx *
			frac->zoom;
	frac->draw.point1.y = (-1. * WIN_Y * frac->zoom) / 4 +
		(WIN_Y / 2) - (frac->m_shy * WIN_Y * frac->zoom) / 4 - frac->shifty *
			frac->zoom;
	frac->draw.point2.x = (1. * WIN_X * frac->zoom) / 4 +
		(WIN_X / 2) - (frac->m_shx * WIN_X * frac->zoom) / 4 - frac->shiftx *
			frac->zoom;
	frac->draw.point2.y = (1. * WIN_Y * frac->zoom) / 4 +
		(WIN_Y / 2) - (frac->m_shy * WIN_Y * frac->zoom) / 4 - frac->shifty *
			frac->zoom;
	frac->draw.point3.x = (1. * WIN_X * frac->zoom) / 4 +
		(WIN_X / 2) - (frac->m_shx * WIN_X * frac->zoom) / 4 - frac->shiftx *
			frac->zoom;
	frac->draw.point3.y = (-1. * WIN_Y * frac->zoom) / 4 +
		(WIN_Y / 2) - (frac->m_shy * WIN_Y * frac->zoom) / 4 - frac->shifty *
			frac->zoom;
	frac->draw.point4.x = (-1. * WIN_X * frac->zoom) / 4 +
		(WIN_X / 2) - (frac->m_shx * WIN_X * frac->zoom) / 4 - frac->shiftx *
			frac->zoom;
	frac->draw.point4.y = (1. * WIN_Y * frac->zoom) / 4 +
		(WIN_Y / 2) - (frac->m_shy * WIN_Y * frac->zoom) / 4 - frac->shifty *
			frac->zoom;
}

t_tr	new_carp(t_point p1, t_point p2, t_point p3, t_point p4)
{
	t_tr	new;

	new.p1 = p1;
	new.p2 = p2;
	new.p3 = p3;
	new.p4 = p4;
	return (new);
}

t_tr	f(int x1, int y1, int x2, int y2)
{
	t_tr	new;

	new.p1.x = x1;
	new.p2.x = x2;
	new.p3.x = x2;
	new.p4.x = x1;
	new.p1.y = y1;
	new.p2.y = y1;
	new.p3.y = y2;
	new.p4.y = y2;
	return (new);
}

void	d(t_frac *frac, int i, t_tr t)
{
	t_tr p;

	if (i > 0)
	{
		p = calc_catpet(t);
		draw_carpet(frac, p);
		d(frac, i - 1, f(t.p1.x, t.p1.y, p.p1.x, p.p1.y));
		d(frac, i - 1, f(t.p1.x + (p.p2.x - p.p1.x), t.p1.y, p.p1.x +
			(p.p2.x - p.p1.x), p.p1.y));
		d(frac, i - 1, f(t.p1.x + 2 * (p.p2.x - p.p1.x), t.p1.y, p.p1.x + 2 *
			(p.p2.x - p.p1.x), p.p1.y));
		d(frac, i - 1, f(t.p1.x, t.p1.y + (p.p3.y - p.p1.y), p.p1.x, p.p1.y +
			(p.p3.y - p.p1.y)));
		d(frac, i - 1, f(t.p1.x, t.p1.y + 2 * (p.p3.y - p.p1.y), p.p1.x,
			p.p1.y + 2 * (p.p3.y - p.p1.y)));
		d(frac, i - 1, f(t.p1.x + (p.p2.x - p.p1.x), t.p1.y + 2 * (p.p3.y -
			p.p1.y), p.p1.x + (p.p2.x - p.p1.x), p.p1.y + 2 * (p.p3.y -
				p.p1.y)));
		d(frac, i - 1, f(t.p1.x + 2 * (p.p2.x - p.p1.x), t.p1.y + 2 * (p.p3.y
			- p.p1.y), p.p1.x + 2 * (p.p2.x - p.p1.x), p.p1.y + 2 * (p.p3.y -
				p.p1.y)));
		d(frac, i - 1, f(t.p1.x + 2 * (p.p2.x - p.p1.x), t.p1.y + (p.p3.y -
			p.p1.y), p.p1.x + 2 * (p.p2.x - p.p1.x), p.p1.y + (p.p3.y -
				p.p1.y)));
	}
}

void	carp_serp(t_frac *frac)
{
	init_carp(frac);
	frac->name = "Carpet Sierpinski";
	frac->color = 255;
	d(frac, frac->iter_line, new_carp(frac->draw.point1,
		frac->draw.point2, frac->draw.point3, frac->draw.point4));
	mlx_put_image_to_window(frac->mlx, frac->win, frac->image, 0, 0);
}
