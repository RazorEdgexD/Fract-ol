/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kox.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:44:31 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/12 15:44:34 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_serp(t_frac *frac)
{
	frac->draw.point1.x = (200 - frac->shiftx) * frac->zoom;
	frac->draw.point1.y = (800 - frac->shifty) * frac->zoom;
	frac->draw.point2.x = (500 - frac->shiftx) * frac->zoom;
	frac->draw.point2.y = (200 - frac->shifty) * frac->zoom;
	frac->draw.point3.x = (800 - frac->shiftx) * frac->zoom;
	frac->draw.point3.y = (800 - frac->shifty) * frac->zoom;
	frac->color = 255;
	frac->x_win = 0;
	frac->y_win = 0;
}

t_tr	init_tr(t_point p1, t_point p2, t_point p3)
{
	t_tr	new;

	new.p1 = p1;
	new.p2 = p2;
	new.p3 = p3;
	return (new);
}

void	draw_tri(t_frac *frac, int iter, t_tr trian)
{
	t_point p1;
	t_point p2;
	t_point p3;

	if (iter > 0)
	{
		p1.x = (trian.p2.x + trian.p3.x) / 2;
		p1.y = (trian.p2.y + trian.p3.y) / 2;
		p2.x = (trian.p1.x + trian.p2.x) / 2;
		p2.y = (trian.p1.y + trian.p2.y) / 2;
		p3.x = (trian.p3.x + trian.p1.x) / 2;
		p3.y = (trian.p3.y + trian.p1.y) / 2;
		ft_brezen(frac, &frac->draw, &p1, &p2);
		ft_brezen(frac, &frac->draw, &p2, &p3);
		ft_brezen(frac, &frac->draw, &p1, &p3);
		draw_tri(frac, iter - 1, init_tr(p1, p2, trian.p2));
		draw_tri(frac, iter - 1, init_tr(p1, p3, trian.p3));
		draw_tri(frac, iter - 1, init_tr(p2, p3, trian.p1));
	}
}

void	tri_serp(t_frac *frac)
{
	init_serp(frac);
	ft_brezen(frac, &frac->draw, &frac->draw.point1, &frac->draw.point2);
	ft_brezen(frac, &frac->draw, &frac->draw.point2, &frac->draw.point3);
	ft_brezen(frac, &frac->draw, &frac->draw.point1, &frac->draw.point3);
	draw_tri(frac, frac->iter_line, init_tr(frac->draw.point1,
		frac->draw.point2, frac->draw.point3));
	mlx_put_image_to_window(frac->mlx, frac->win, frac->image, 0, 0);
	ft_putstr("Printing...\n");
	ft_hooks(frac);
}
