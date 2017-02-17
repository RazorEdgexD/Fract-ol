/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:18:36 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/12 17:18:39 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	additional_key(int keycode, t_frac *frac)
{
	if (keycode == 53)
		exit(777);
	if (keycode == 69)
		frac->zoom *= 0.9;
	if (keycode == 78)
		frac->zoom *= 1.1;
	if (keycode == 123)
		frac->shiftx -= 10;
	if (keycode == 124)
		frac->shiftx += 10;
	if (keycode == 125)
		frac->shifty += 10;
	if (keycode == 126)
		frac->shifty -= 10;
	if (keycode == 121)
		if (frac->iter_line > 1)
			frac->iter_line -= 1;
	if (keycode == 116)
		if (frac->iter_line <= 10)
			frac->iter_line += 1;
	if (keycode == 83)
		frac->iter += 5;
	if (keycode == 84)
		if (frac->iter > 25)
			frac->iter -= 5;
}

int		keys_for_win1(int keycode, t_frac *frac)
{
	additional_key(keycode, frac);
	mlx_destroy_image(frac->mlx, frac->image);
	frac->image = mlx_new_image(frac->mlx, WIN_X, WIN_Y);
	check_draw(frac);
	return (0);
}

int		move_mouse(int x, int y, t_frac *frac)
{
	frac->c_r = (x * 1. - WIN_X / 2.) / WIN_X + 0.285;
	frac->c_i = (y * 1. - WIN_Y / 2.) / WIN_Y + 0.01;
	mlx_destroy_image(frac->mlx, frac->image);
	frac->image = mlx_new_image(frac->mlx, WIN_X, WIN_Y);
	check_draw(frac);
	return (0);
}

/*
int		key_mouse(int key, int x, int y, t_frac * frac)
{
	if (key == 4)
	{

	}
}
*/

int		ft_hooks(t_frac *frac)
{
	mlx_key_hook(frac->win, keys_for_win1, frac);
	mlx_hook(frac->win, 6, 0, move_mouse, frac);
//	mlx_mouse_hook(frac->win, key_mouse, frac);
	mlx_loop(frac->mlx);
	return (0);
}
