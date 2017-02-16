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

	double 	x;
	double	y;
	double	x_tmp;
	int	iteration;

	x = frac->x_win;
	y = frac->y_win;
	iteration = 0;
	while (x * x + y * y < 4. && iteration < 200)
	{
		x_tmp = x * x - y * y + 0.285;
		y = 2 * x * y + 0.01;
		x = x_tmp;
		iteration++;
	}
	if (iteration < 25)
		ft_image_pixel_put(frac, j, i, frac->color * iteration);
	else
		ft_image_pixel_put(frac, j, i, 0);
}

void	julia(t_frac *frac)
{
	int		i = 0;
	int		j = 0;

	frac->color = 272;
	frac->x_win = 0;
	frac->y_win = 0;
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, WIN_X, WIN_Y, "Fractol (Julia)");
	frac->image = mlx_new_image(frac->mlx, WIN_X, WIN_Y);
	while (i <= WIN_Y)
	{
		j = 0;
		frac->y_win = ((i - WIN_Y / 2.) * 4.) / WIN_Y;
		while (j <= WIN_X)
		{
	//		printf("JULIAxwin=%f ywin=%f\n", frac->x_win, frac->y_win);
			frac->x_win = ((j - WIN_X / 2.) * 4.) / WIN_X;
			calc_julia(frac, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->image, 0, 0);
	ft_hooks(frac);
	ft_putstr("Printing...\n");
	mlx_loop(frac->mlx);
}
