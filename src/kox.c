/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kox.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:37:48 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/24 17:01:38 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_kox(t_frac *frac)
{
	frac->draw.point1.x = (-1. * WIN_X * frac->zoom) / 4. +
		(WIN_X / 2) - (frac->m_shx * WIN_X * frac->zoom) / 4. - frac->shiftx *
			frac->zoom;
	frac->draw.point1.y = (WIN_Y / 2) - (frac->m_shy * WIN_Y * frac->zoom) / 4.
		- frac->shifty * frac->zoom;
	frac->draw.point2.x = (1. * WIN_X * frac->zoom) / 4. +
		(WIN_X / 2) - (frac->m_shx * WIN_X * frac->zoom) / 4. - frac->shiftx *
			frac->zoom;
	frac->draw.point2.y = (WIN_Y / 2) - (frac->m_shy * WIN_Y * frac->zoom) / 4.
		- frac->shifty *
			frac->zoom;
	frac->color = 255;
	frac->name = "Kox";
}

t_tr	init_p(t_point p1, t_point p2)
{
	t_tr	new;

	new.p1 = p1;
	new.p2 = p2;
	new.p3.x = 0;
	new.p3.y = 0;
	return (new);
}

t_tr	fill_k(int x1, int y1, int x2, int y2)
{
	t_tr	new;

	new.p1.x = x1;
	new.p2.x = x2;
	new.p1.y = y1;
	new.p2.y = y2;
	return (new);
}

void	draw_k(t_frac *frac, int i, t_tr t)
{
	t_point b;
	t_point d;

	if (i == 0)
		ft_brezen(frac, &frac->draw, &t.p1, &t.p2);
	else
	{
		b.x = t.p1.x + (t.p2.x - t.p1.x) / 3;
		b.y = t.p1.y + (t.p2.y - t.p1.y) / 3;
		d.x = t.p1.x + (2 * (t.p2.x - t.p1.x)) / 3;
		d.y = t.p1.y + (2 * (t.p2.y - t.p1.y)) / 3;
		t.p3.x = b.x + (d.x - b.x) * COS60 - SIN60 * (d.y - b.y);
		t.p3.y = b.y + (d.x - b.x) * SIN60 + COS60 * (d.y - b.y);
		draw_k(frac, i - 1, fill_k(t.p1.x, t.p1.y, b.x, b.y));
		draw_k(frac, i - 1, fill_k(b.x, b.y, t.p3.x, t.p3.y));
		draw_k(frac, i - 1, fill_k(t.p3.x, t.p3.y, d.x, d.y));
		draw_k(frac, i - 1, fill_k(d.x, d.y, t.p2.x, t.p2.y));
	}
}

void	kox(t_frac *frac)
{
	init_kox(frac);
	draw_k(frac, frac->iter_line, init_p(frac->draw.point1, frac->draw.point2));
	mlx_put_image_to_window(frac->mlx, frac->win, frac->image, 0, 0);
	ft_print_info2(frac);
}
