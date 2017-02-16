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

#include "fractol.h"


void	check_type(char *argv1, char *argv2, t_frac *frac)
{
	frac->d_julia = 0;
	frac->d_kox = 0;
	frac->d_mandel = 0;
	frac->d_burning = 0;
	frac->d_tri = 0;
	frac->d_carpet = 0;
	frac->d_barn = 0;
	if (argv2 == NULL)
		argv2 = "NULL";
	if (!ft_strcmp(argv1, "1") || !ft_strcmp(argv2, "1"))
		frac->d_tri = 1;
	if (!ft_strcmp(argv1, "2") || !ft_strcmp(argv2, "2"))
		frac->d_julia = 1;
	if (!ft_strcmp(argv1, "3") || !ft_strcmp(argv2, "3"))
		frac->d_mandel = 1;
	if (!ft_strcmp(argv1, "4") || !ft_strcmp(argv2, "4"))
		frac->d_kox = 1;
	if (!ft_strcmp(argv1, "5") || !ft_strcmp(argv2, "5"))
		frac->d_burning = 1;
	if (!ft_strcmp(argv1, "6") || !ft_strcmp(argv2, "6"))
		frac->d_carpet = 1;
	if (!ft_strcmp(argv1, "7") || !ft_strcmp(argv2, "7"))
		frac->d_barn = 1;
	if (frac->d_julia == 0 && frac->d_kox == 0 && frac->d_mandel == 0 &&
		frac->d_burning == 0 && frac->d_tri == 0 && frac->d_carpet == 0 && frac->d_barn == 0)
	{
		ft_putstr("Usage ./fractol fractal_number\nList of availble fractals:\n");
		ft_putstr("Triangle Sierpinski - 1\nJulia - 2\nMandel - 3\nKox - 4\nBurningShip - 5\nCarpet Sierpinski - 6\nBarnsley fern - 7\n");
		exit(666);
	}
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
	if (frac->d_barn == 1)
		barnsley(frac);
}

int		main(int argc, char **argv)
{
	t_frac	frac;

	if (argc == 2 || argc == 3)
	{
		check_type(argv[1], argv[2], &frac);
		check_draw(&frac);
	}
	else
	{
		ft_putstr("Usage ./fractol fractal_number\nList of availble fractals:\n");
		ft_putstr("Triangle Sierpinski - 1\nJulia - 2\nMandel - 3\nKox - 4\nBurningShip - 5\nCarpet Sierpinski - 6\nBarnsley fern - 7\n");
	}
	return (0);
}
