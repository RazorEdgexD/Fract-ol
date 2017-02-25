/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:21:03 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/14 16:15:58 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>


#include "fractol.h"

void	init_frac(t_frac *frac)
{
	frac->d_julia = 0;
	frac->d_kox = 0;
	frac->d_mandel = 0;
	frac->d_burning = 0;
	frac->d_tri = 0;
	frac->d_carpet = 0;
	frac->d_kox_k = 0;
	frac->d_sin = 0;
	frac->d_bio = 0;
	frac->zoom = 1;
	frac->shiftx = 0;
	frac->shifty = 0;
	frac->iter_line = 5;
	frac->iter = 30;
	frac->c_r = 0.285;
	frac->c_i = 0.01;
	frac->m_zoom = 1;
	frac->m_shift_x = 0;
	frac->m_shift_y = 0;
	frac->m_shift_dx = 0;
	frac->m_shift_dy = 0;
	frac->m_shx = 0.;
	frac->m_shy = 0.;
	frac->mouse_on = 0;
}

void	draw_error(void)
{
	ft_putstr("Usage ./fractol fractal_number\nList of availble fractals:\n");
	ft_putstr("Triangle Sierpinski - 1\nJulia - 2\nMandel - 3\nKox - 4\nBurni");
	ft_putstr("ngShip - 5\nCarpet Sierpinski - 6\nKox kurve - 7\nSinusoid - 8");
	ft_putstr("\nBio - 9\n");
	exit(666);
}

void	check_type(char *argv1, t_frac *frac)
{
	init_frac(frac);
	if (!ft_strcmp(argv1, "1"))
		frac->d_tri = 1;
	if (!ft_strcmp(argv1, "2"))
		frac->d_julia = 1;
	if (!ft_strcmp(argv1, "3"))
		frac->d_mandel = 1;
	if (!ft_strcmp(argv1, "4"))
		frac->d_kox = 1;
	if (!ft_strcmp(argv1, "5"))
		frac->d_burning = 1;
	if (!ft_strcmp(argv1, "6"))
		frac->d_carpet = 1;
	if (!ft_strcmp(argv1, "7"))
		frac->d_kox_k = 1;
	if (!ft_strcmp(argv1, "8"))
		frac->d_sin = 1;
	if (!ft_strcmp(argv1, "9"))
		frac->d_bio = 1;
	if (frac->d_julia == 0 && frac->d_kox == 0 && frac->d_mandel == 0 &&
		frac->d_burning == 0 && frac->d_tri == 0 && frac->d_carpet == 0 &&
		frac->d_kox_k == 0 && frac->d_sin == 0 && frac->d_bio == 0)
		draw_error();
}

void	check_draw(t_frac *frac)
{
	if (frac->d_mandel == 1)
		mandel(frac);
	if (frac->d_burning == 1)
		burningship(frac);
	if (frac->d_julia == 1)
		julia(frac);
	if (frac->d_tri == 1)
		tri_serp(frac);
	if (frac->d_carpet == 1)
		carp_serp(frac);
	if (frac->d_kox == 1)
		kox(frac);
	if (frac->d_kox_k == 1)
		kox_kurve(frac);
	if (frac->d_sin == 1)
		sinus(frac);
	if (frac->d_bio == 1)
		bio(frac);
}

int		main(int argc, char **argv)
{
	t_bon	frac;

	if (argc == 2)
	{
		check_type(argv[1], &frac.fir);
	//	start_draw(frac.fir);
		frac.fir.mlx = mlx_init();
		frac.fir.win = mlx_new_window(frac.fir.mlx, WIN_X, WIN_Y, "Fractol");
		frac.fir.image = mlx_new_image(frac.fir.mlx, WIN_X, WIN_Y);
		frac.fir.color = 272;
		frac.fir.x_win = 0;
		frac.fir.y_win = 0;
 		check_draw(&frac.fir);
		ft_print_info(&frac.fir);
		ft_hooks(&frac.fir);
		mlx_loop(frac.fir.mlx);
	}
	if (argc == 3)
	{
		check_type(argv[1], &frac.fir);
		frac.fir.mlx = mlx_init();
		frac.fir.win = mlx_new_window(frac.fir.mlx, WIN_X, WIN_Y, "Fractol");
		frac.fir.image = mlx_new_image(frac.fir.mlx, WIN_X, WIN_Y);
		frac.fir.color = 272;
		frac.fir.x_win = 0;
		frac.fir.y_win = 0;
 		check_draw(&frac.fir);
		ft_hooks(&frac.fir);

		check_type(argv[2], &frac.sec);
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
	else
		draw_error();
	return (0);
}
