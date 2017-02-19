/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:44:01 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/12 15:44:03 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_julia(t_frac *frac, int i, int j)
{
	double	x;
	double	y;
	double	x_tmp;
	int		iteration;

	x = frac->x_win;
	y = frac->y_win;
	iteration = 0;
	while (x * x + y * y < 4. && iteration < frac->iter)
	{
		x_tmp = x * x - y * y + frac->c_r;
		y = 2 * x * y + frac->c_i;
		x = x_tmp;
		iteration++;
	}
	if (iteration < frac->iter / 2)
		ft_image_pixel_put(frac, j, i, frac->color * iteration);
	else
		ft_image_pixel_put(frac, j, i, 0);
}

void	julia(t_frac *frac)
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
		frac->y_win = frac->zoom * ((i + frac->shifty - WIN_Y / 2.) * 4.)
			/ WIN_Y;
		while (j <= WIN_X)
		{
			frac->x_win = frac->zoom * ((j + frac->shiftx - WIN_X / 2.) * 4.)
				/ WIN_X;
			calc_julia(frac, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->image, 0, 0);
	ft_hooks(frac);
}
