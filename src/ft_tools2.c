/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:28:10 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/24 16:28:14 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		close_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

void	reset(t_frac *frac)
{
	frac->zoom = 1;
	frac->iter = 30;
	frac->iter_line = 5;
	frac->shiftx = 0;
	frac->shifty = 0;
	frac->m_shx = 0;
	frac->m_shy = 0;
	if (frac->d_julia == 1)
	{
		frac->c_r = 0.285;
		frac->c_i = 0.01;
	}
}

t_tr	calc_catpet(t_tr t)
{
	t_tr	poi;

	poi.p1.x = t.p1.x + (t.p2.x - t.p1.x) / 3;
	poi.p1.y = t.p1.y + (t.p4.y - t.p1.y) / 3;
	poi.p2.x = t.p1.x + (2 * (t.p2.x - t.p1.x)) / 3;
	poi.p2.y = t.p1.y + (t.p4.y - t.p1.y) / 3;
	poi.p3.x = t.p1.x + (2 * (t.p2.x - t.p1.x)) / 3;
	poi.p3.y = t.p1.y + (2 * (t.p4.y - t.p1.y)) / 3;
	poi.p4.x = t.p1.x + (t.p2.x - t.p1.x) / 3;
	poi.p4.y = t.p1.y + (2 * (t.p4.y - t.p1.y)) / 3;
	return (poi);
}

void	draw_carpet(t_frac *frac, t_tr p)
{
	ft_brezen(frac, &frac->draw, &p.p1, &p.p2);
	ft_brezen(frac, &frac->draw, &p.p2, &p.p3);
	ft_brezen(frac, &frac->draw, &p.p3, &p.p4);
	ft_brezen(frac, &frac->draw, &p.p4, &p.p1);
}

void	start_draw(t_bon frac)
{
	frac.fir.mlx = mlx_init();
	frac.fir.win = mlx_new_window(frac.fir.mlx, WIN_X, WIN_Y, "Fractol");
	frac.fir.image = mlx_new_image(frac.fir.mlx, WIN_X, WIN_Y);
	frac.fir.color = 272;
	frac.fir.x_win = 0;
	frac.fir.y_win = 0;
/*	if (i == 2)
	{
		frac.fir.mlx = mlx_init();
		frac.fir.win = mlx_new_window(frac.fir.mlx, WIN_X, WIN_Y, "Fractol(1)");
		frac.fir.image = mlx_new_image(frac.fir.mlx, WIN_X, WIN_Y);
		frac.fir.color = 272;
		frac.fir.x_win = 0;
		frac.fir.y_win = 0;
		frac.sec.mlx = mlx_init();
		frac.sec.win = mlx_new_window(frac.sec.mlx, WIN_X, WIN_Y, "Fractol(2)");
		frac.sec.image = mlx_new_image(frac.sec.mlx, WIN_X, WIN_Y);
		frac.sec.color = 272;
		frac.sec.x_win = 0;
		frac.sec.y_win = 0;
	} */
}
