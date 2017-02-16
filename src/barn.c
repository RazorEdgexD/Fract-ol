/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:15:30 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/16 21:15:31 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_b(t_frac *frac)
{
	frac->draw.point1.x = 400;
	frac->draw.point1.y = 600;
	frac->draw.point2.x = 200;
	frac->draw.point2.y = 600;
	frac->color = 16777215;
	frac->iter_line = 5;
	frac->rad = 60 * RAD;
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, WIN_X, WIN_Y
	, "Fractol (Barnsley fern)");
	frac->image = mlx_new_image(frac->mlx, WIN_X, WIN_Y);
}

t_tr	fill_b(int x1, int y1, int x2, int y2)
{
	t_tr	new;

	new.p1.x = x1;
	new.p1.y = y1;
	new.p2.x = x2;
	new.p2.y = y2;
	return (new);
}
void	draw_b(t_frac *frac, int i, t_tr t)
{
	t_point p1;
	if (i > 0)
	{
		ft_brezen(frac, &frac->draw, &t.p1, &t.p2);
		p1.x = round(t.p1.x + t.p2.x * cos(frac->rad));
		p1.y = round(t.p1.y - t.p2.y * sin(frac->rad));
		draw_b(frac, i - 1, fill_b(p1.x, p1.y, (int)t.p2.x * 0.4, (int)frac->rad - 14 * 3.14 / 30));
		draw_b(frac, i - 1, fill_b(p1.x, p1.y, (int)t.p2.x * 0.4, (int)frac->rad - 14 * 3.14 / 30));
		draw_b(frac, i - 1, fill_b(p1.x, p1.y, (int)t.p2.x * 0.7, (int)frac->rad - 3.14 / 30));
	}
}


void	barnsley(t_frac *frac)
{
	init_b(frac);
//	draw_k(frac, frac->iter_line, init_p(frac->draw.point1, frac->draw.point2));
	mlx_put_image_to_window(frac->mlx, frac->win, frac->image, 0, 0);
	ft_hooks(frac);
	ft_putstr("Printing...\n");
	mlx_loop(frac->mlx);
}
