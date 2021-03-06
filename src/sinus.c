/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:21 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:23 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_sin(t_frac *frac, int i, int j)
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
		x = sin(x);
		y = sin(y);
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

void	sinus(t_frac *frac)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= WIN_Y)
	{
		j = 0;
		frac->y_win = ((i + frac->shifty * frac->zoom
			- WIN_Y / 2) * 4. + (WIN_Y * 1.)
				* frac->m_shy * frac->zoom) / (WIN_Y * frac->zoom);
		while (j <= WIN_X)
		{
			frac->x_win = ((j + frac->shiftx * frac->zoom
				- 500.) * 4. + (1000. * 1.)
					* frac->m_shx * frac->zoom) / (1000. * frac->zoom);
			calc_sin(frac, i, j);
			j++;
		}
		i++;
	}
	frac->name = "Sinusoid";
	mlx_put_image_to_window(frac->mlx, frac->win, frac->image, 0, 0);
	ft_print_info(frac);
}
