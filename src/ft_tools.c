/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:26:15 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/12 14:26:19 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_image_pixel_put(t_frac *frac, int x, int y, int rgb)
{
	int				bpp;
	int				sl;
	int				en;
	char			*image;
	unsigned int	tmp;

	image = mlx_get_data_addr(frac->image, &bpp, &sl, &en);
	tmp = (mlx_get_color_value(frac->mlx, rgb));
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
		ft_memcpy((void *)(image + y * WIN_X * (bpp / 8)) + x * (bpp / 8),
			(void *)&tmp, 4);
}

void	count_delta(t_point *t0, t_point *t1, t_draw *draw)
{
	draw->deltax = abs(t1->x - t0->x);
	draw->deltay = abs(t1->y - t0->y);
	draw->signx = t1->x >= t0->x ? 1 : -1;
	draw->signy = t1->y >= t0->y ? 1 : -1;
	draw->error = draw->deltax - draw->deltay;
	draw->error2 = 2 * draw->error;
}

void	ft_brezen(t_frac *frac, t_draw *draw, t_point *t0, t_point *t1)
{
	int		x0;
	int		y0;

	x0 = t0->x;
	y0 = t0->y;
	count_delta(t0, t1, draw);
	ft_image_pixel_put(frac, t1->x, t1->y, frac->color);
	while (t1->x != t0->x || t1->y != t0->y)
	{
		ft_image_pixel_put(frac, t0->x, t0->y, frac->color);
		draw->error2 = draw->error * 2;
		if (draw->error2 > -draw->deltay)
		{
			draw->error -= draw->deltay;
			t0->x += draw->signx;
		}
		if (draw->error2 < draw->deltax)
		{
			draw->error += draw->deltax;
			t0->y += draw->signy;
		}
	}
	t0->x = x0;
	t0->y = y0;
}

int		ft_change_color(t_frac *frac)
{
	if (frac->color == 2050)
		frac->color = 272;
	else if (frac->color == 272)
		frac->color = 2050;
	return (0);
}

void	ft_mouse_zoom(t_frac *frac)
{
	if (frac->m_zoom == 1)
	{
		frac->zoom *= 1.1;
		frac->m_shx += frac->m_shift_x - frac->m_shift_dx / frac->zoom;
		frac->m_shy += frac->m_shift_y - frac->m_shift_dy / frac->zoom;
	}
	if (frac->m_zoom == 2)
	{
		frac->zoom /= 1.1;
		frac->m_shx += frac->m_shift_x - frac->m_shift_dx / frac->zoom;
		frac->m_shy += frac->m_shift_y - frac->m_shift_dy / frac->zoom;
	}
	frac->m_zoom = 0;
}
