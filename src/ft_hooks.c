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
		frac->shiftx -= 25;
	if (keycode == 124)
		frac->shiftx += 25;
	if (keycode == 125)
		frac->shifty += 25;
	if (keycode == 126)
		frac->shifty -= 25;
	if (keycode == 121)
		if (frac->iter_line > 1)
			frac->iter_line -= 1;
	if (keycode == 116)
		if (frac->iter_line < 11)
			frac->iter_line += 1;
	if (keycode == 83)
		frac->iter += 5;
	if (keycode == 84)
		if (frac->iter > 25)
			frac->iter -= 5;
}

int		keys_for_win1(int keycode, t_frac *frac)
{
	if (keycode == 87)
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
	if (keycode == 85)
	{
		if (frac->mouse_on == 0)
			frac->mouse_on = 1;
		else
			frac->mouse_on = 0;
	}
	if (keycode == 8)
		ft_change_color(frac);
	additional_key(keycode, frac);
	mlx_destroy_image(frac->mlx, frac->image);
	frac->image = mlx_new_image(frac->mlx, WIN_X, WIN_Y);
	check_draw(frac);
	return (0);
}

int		move_mouse(int x, int y, t_frac *frac)
{
	if (frac->mouse_on == 1)
	{
		frac->c_r = (x * 1. - WIN_X / 2.) / WIN_X + 0.285;
		frac->c_i = (y * 1. - WIN_Y / 2.) / WIN_Y + 0.01;
		mlx_destroy_image(frac->mlx, frac->image);
		frac->image = mlx_new_image(frac->mlx, WIN_X, WIN_Y);
		check_draw(frac);
	}
	return (0);
}

int		key_mouse(int key, int x, int y, t_frac *frac)
{
	if (key == 5)
	{
		frac->m_zoom = 2;
		frac->m_shift_x = (x * 1. - WIN_X / 2) * 4. / (WIN_X * frac->zoom);
		frac->m_shift_y = (y * 1. - WIN_Y / 2) * 4. / (WIN_Y * frac->zoom);
		frac->m_shift_dx = (x * 1. - WIN_X / 2) * 4. / (WIN_X);
		frac->m_shift_dy = (y * 1. - WIN_Y / 2) * 4. / (WIN_Y);
	}
	if (key == 4)
	{
		frac->m_zoom = 1;
		frac->m_shift_x = (x * 1. - WIN_X / 2.) * 4. / (WIN_X * frac->zoom);
		frac->m_shift_y = (y * 1. - WIN_X / 2.) * 4. / (WIN_X * frac->zoom);
		frac->m_shift_dx = (x * 1. - WIN_X / 2.) * 4. / (WIN_X);
		frac->m_shift_dy = (y * 1. - WIN_Y / 2.) * 4. / (WIN_Y);
	}
	ft_mouse_zoom(frac);
	mlx_destroy_image(frac->mlx, frac->image);
	frac->image = mlx_new_image(frac->mlx, WIN_X, WIN_Y);
	check_draw(frac);
	return (0);
}

int		ft_hooks(t_frac *frac)
{
	mlx_key_hook(frac->win, keys_for_win1, frac);
	if (frac->d_julia == 1)
		mlx_hook(frac->win, 6, 0, move_mouse, frac);
	mlx_hook(data->win, 17, 0L, close_x, data);
	mlx_mouse_hook(frac->win, key_mouse, frac);
	mlx_loop(frac->mlx);
	return (0);
}
