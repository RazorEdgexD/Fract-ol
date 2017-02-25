/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:49:59 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/25 14:50:01 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_draw(t_bon frac)
{
	frac.fir.mlx = mlx_init();
	frac.fir.win = mlx_new_window(frac.fir.mlx, WIN_X, WIN_Y, "Fractol");
	frac.fir.image = mlx_new_image(frac.fir.mlx, WIN_X, WIN_Y);
	frac.fir.color = 272;
	frac.sec.color = 272;
	frac.fir.x_win = 0;
	frac.fir.y_win = 0;
	check_draw(&frac.fir);
	ft_hooks(&frac.fir);
	mlx_loop(frac.fir.mlx);
}

void	start_draw2(t_bon frac)
{
	frac.fir.mlx = mlx_init();
	frac.fir.win = mlx_new_window(frac.fir.mlx, WIN_X, WIN_Y, "Fractol");
	frac.fir.image = mlx_new_image(frac.fir.mlx, WIN_X, WIN_Y);
	frac.fir.color = 272;
	frac.sec.color = 272;
	frac.fir.x_win = 0;
	frac.fir.y_win = 0;
	check_draw(&frac.fir);
	ft_hooks(&frac.fir);
	frac.sec.mlx = frac.fir.mlx;
	frac.sec.win = mlx_new_window(frac.sec.mlx, WIN_X, WIN_Y, "Fractol");
	frac.sec.image = mlx_new_image(frac.sec.mlx, WIN_X, WIN_Y);
	frac.sec.color = 272;
	frac.sec.x_win = 0;
	frac.sec.y_win = 0;
	check_draw(&frac.sec);
	ft_hooks(&frac.sec);
	mlx_loop(frac.fir.mlx);
}
