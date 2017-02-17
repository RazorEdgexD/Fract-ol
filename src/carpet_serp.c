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
	frac->draw.point1.x = (200 + -frac->shiftx) * frac->zoom;
	frac->draw.point1.y = (200 + -frac->shifty) * frac->zoom;
	frac->draw.point2.x = (800 + -frac->shiftx) * frac->zoom;
	frac->draw.point2.y = (200 + -frac->shifty) * frac->zoom;
	frac->draw.point3.x = (800 + -frac->shiftx) * frac->zoom;
	frac->draw.point3.y = (800 + -frac->shifty) * frac->zoom;
	frac->draw.point4.x = (200 + -frac->shiftx) * frac->zoom;
	frac->draw.point4.y = (800 + -frac->shifty) * frac->zoom;
	frac->color = 255;
	frac->x_win = 0;
	frac->y_win = 0;
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

t_tr	fill(int x1, int y1, int x2, int y2)
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

void	draw(t_frac *frac, int i, t_tr t)
{
	t_point p1;
	t_point p2;
	t_point p3;
	t_point p4;

	if (i > 0)
	{
		p1.x = t.p1.x + (t.p2.x - t.p1.x) / 3;
		p1.y = t.p1.y + (t.p4.y - t.p1.y) / 3;
		p2.x = t.p1.x + (2 * (t.p2.x - t.p1.x)) / 3;
		p2.y = t.p1.y + (t.p4.y - t.p1.y) / 3;
		p3.x = t.p1.x + (2 * (t.p2.x - t.p1.x)) / 3;
		p3.y = t.p1.y + (2 * (t.p4.y - t.p1.y)) / 3;
		p4.x = t.p1.x + (t.p2.x - t.p1.x) / 3;
		p4.y = t.p1.y + (2 * (t.p4.y - t.p1.y)) / 3;
		ft_brezen(frac, &frac->draw, &p1, &p2);
		ft_brezen(frac, &frac->draw, &p2, &p3);
		ft_brezen(frac, &frac->draw, &p3, &p4);
		ft_brezen(frac, &frac->draw, &p4, &p1);
		draw(frac, i - 1, fill(t.p1.x, t.p1.y, p1.x, p1.y));
		draw(frac, i - 1, fill(t.p1.x + (p2.x - p1.x), t.p1.y, p1.x + (p2.x - p1.x), p1.y));
		draw(frac, i - 1, fill(t.p1.x + 2 * (p2.x - p1.x), t.p1.y, p1.x + 2 * (p2.x - p1.x), p1.y));
		draw(frac, i - 1, fill(t.p1.x, t.p1.y + (p3.y - p1.y), p1.x, p1.y + (p3.y - p1.y)));
		draw(frac, i - 1, fill(t.p1.x, t.p1.y + 2 * (p3.y - p1.y), p1.x, p1.y + 2 * (p3.y - p1.y)));
		draw(frac, i - 1, fill(t.p1.x + (p2.x - p1.x), t.p1.y + 2 * (p3.y - p1.y), p1.x + (p2.x - p1.x), p1.y + 2 * (p3.y - p1.y)));
		draw(frac, i - 1, fill(t.p1.x + 2 * (p2.x - p1.x), t.p1.y + 2 * (p3.y - p1.y), p1.x + 2 * (p2.x - p1.x), p1.y + 2 * (p3.y - p1.y)));
		draw(frac, i - 1, fill(t.p1.x + 2 * (p2.x - p1.x), t.p1.y + (p3.y - p1.y), p1.x + 2 * (p2.x - p1.x), p1.y + (p3.y - p1.y)));
	}
}

void	carp_serp(t_frac *frac)
{
	init_carp(frac);
	draw(frac, frac->iter_line, new_carp(frac->draw.point1,
		frac->draw.point2, frac->draw.point3, frac->draw.point4));
	mlx_put_image_to_window(frac->mlx, frac->win, frac->image, 0, 0);
	ft_putstr("Printing...\n");
	ft_hooks(frac);
}
