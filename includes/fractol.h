/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:51:22 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/13 19:50:14 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_X 1000
# define WIN_Y 1000
# define sin60 -0.86602540378
# define cos60 0.5
# define RAD 0.0175433

# include "../libft/libft.h"
# include <math.h>
# include "mlx.h"


#include <stdio.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_draw
{
	int				deltax;
	int				deltay;
	int				signx;
	int				signy;
	int				error;
	int				error2;
	struct s_point	point1;
	struct s_point	point2;
	struct s_point	point3;
	struct s_point	point4;

}					t_draw;

typedef struct		s_tr
{
	struct s_point	p1;
	struct s_point	p2;
	struct s_point	p3;
	struct s_point	p4;
}					t_tr;

typedef struct		s_frac
{
	int				d_barn;
	int				d_julia;
	int				d_mandel;
	int				d_kox;
	int				d_burning;
	int				d_tri;
	int				d_carpet;
	double			x_win;
	double			y_win;
	int				color;
	int				iter_line;
	void			*win;
	void			*mlx;
	void			*image;
	int				shift;
	int				rad;

	struct s_draw	draw;
}					t_frac;

void			ft_image_pixel_put(t_frac *frac, int x, int y, int rgb);
int				ft_hooks(t_frac *frac);
void			ft_calc_point(t_tr t, t_frac *frac);
void			mandel(t_frac *frac);
void			burningship(t_frac *frac);
void			julia(t_frac *frac);
void			tri_serp(t_frac *frac);
void			carp_serp(t_frac *frac);
void			kox(t_frac *frac);
void			barnsley(t_frac *frac);
void			ft_brezen(t_frac *frac, t_draw *draw, t_point *t0, t_point *t1);

#endif
