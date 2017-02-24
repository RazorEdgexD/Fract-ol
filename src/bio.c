/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bio.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:31:50 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/22 19:31:51 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_bio(t_frac *frac, int i, int j)
{
	double	x;
	double	y;
	double	x_tmp;
	int		iteration;

	x = frac->x_win;
	y = frac->y_win;
	frac->iter = 50;
	iteration = 0;
	while (x * x < 70 && y * y < 70 && iteration < frac->iter)
	{
		x_tmp = x * x * x * x - y * y * y * y - 6 * x * x * y * y + 1;
		y = 4 * x * x * x * y - 4 * x * y * y * y + 1;
		x = x_tmp;
		iteration++;
	}
	if (fabs(x) > 10 * frac->iter / 50 || fabs(y) > 1000 * frac->iter / 50)
		ft_image_pixel_put(frac, j, i, frac->color * iteration);
	else
		ft_image_pixel_put(frac, j, i, 0);
}

void	bio(t_frac *frac)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	frac->color = 27200;
	if (frac->zoom < 0.246637)
		frac->zoom = 0.246637;
	while (++i <= WIN_Y)
	{
		j = 0;
		frac->y_win = ((i + frac->shifty - WIN_Y / 2) * 4. + (WIN_Y * 1.)
				* frac->m_shy * frac->zoom) / (WIN_Y * frac->zoom);
		while (j <= WIN_X)
		{
			frac->x_win = ((j + frac->shiftx - 500.) * 4. + (1000. * 1.)
					* frac->m_shx * frac->zoom) / (1000. * frac->zoom);
			calc_bio(frac, i, j);
			j++;
		}
	}
	frac->name = "Bio";
	mlx_put_image_to_window(frac->mlx, frac->win, frac->image, 0, 0);
	ft_print_info(frac);
	ft_hooks(frac);
}
