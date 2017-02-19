/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:44:12 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/12 15:44:24 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_madel(t_frac *frac, int i, int j)
{
	double	x;
	double	y;
	double	x_tmp;
	int		iteration;

	x = 0.0;
	y = 0.0;
	iteration = 0;
	while (x * x + y * y < 4. && iteration < frac->iter)
	{
		x_tmp = x * x - y * y + frac->x_win;
		y = 2 * x * y + frac->y_win;
		x = x_tmp;
		iteration++;
	}
	if (iteration < frac->iter / 2)
		ft_image_pixel_put(frac, j, i, frac->color * iteration);
	else
		ft_image_pixel_put(frac, j, i, 0);
}

void	mandel(t_frac *frac)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	frac->color = 272;
	frac->x_win = 0;
	frac->y_win = 0;
	while (i <= WIN_Y)
	{
		j = 0;
		frac->y_win = ((i + frac->shifty - 500) * 4. + (500 * 1.)
					* frac->m_shx * frac->zoom) / (500 * frac->zoom);
		while (j <= WIN_X)
		{
			frac->x_win = ((j + frac->shiftx - 500) * 4. + (500 * 1.)
						* frac->m_shy * frac->zoom) / (500 * frac->zoom);
			calc_madel(frac, i, j);
			j++;
		}
		i++;
	}
	frac->name = "Mandel";
	ft_image_pixel_put(frac, 500, 500, 0xFFFFFF);
	ft_image_pixel_put(frac, 501, 500, 0xFFFFFF);
	ft_image_pixel_put(frac, 502, 500, 0xFFFFFF);
	ft_image_pixel_put(frac, 500, 501, 0xFFFFFF);
	ft_image_pixel_put(frac, 500, 502, 0xFFFFFF);
	ft_image_pixel_put(frac, 500, 499, 0xFFFFFF);
	ft_image_pixel_put(frac, 500, 498, 0xFFFFFF);
	ft_image_pixel_put(frac, 499, 500, 0xFFFFFF);
	ft_image_pixel_put(frac, 498, 500, 0xFFFFFF);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->image, 0, 0);
	ft_print_info(frac);
//	printf("zoom=%f x = %d | y = %d\n", frac->zoom, frac->m_shift_x, frac->m_shift_y);
	ft_hooks(frac);
}
