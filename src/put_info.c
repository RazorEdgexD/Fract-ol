/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 14:34:31 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/19 14:34:33 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_str(t_frac *frac, char *str)
{
	mlx_string_put(frac->mlx, frac->win, 10, frac->text_y, 0xFFFFFF, str);
	frac->text_y += 20;
}

void	ft_print_info(t_frac *frac)
{
	frac->text_y = 20;
	ft_print_str(frac, ft_strjoin("Fractal = ", frac->name));
	ft_print_str(frac, ft_strjoin("Iteration = ", ft_itoa(frac->iter)));
	ft_print_str(frac, ft_strjoin(ft_strjoin("Zoom = x", ft_itoa(frac->zoom)),
		ft_strjoin(".", ft_itoa((int)(frac->zoom * 10) % 10))));
	ft_print_str(frac, "~~~~~~~~~~~~~Key~~~~~~~~~~~");
	ft_print_str(frac, "Mouse Scroll - Change zoom");
	ft_print_str(frac, "Mouse Move   - Rotation on Julia");
	ft_print_str(frac, "'1','2'      - Change iteration");
	ft_print_str(frac, "'pU','pD'    - Change iteration line Fractal");
	ft_print_str(frac, "'-', '+'     - Zoom in center");
	ft_print_str(frac, "'Arrows'     - Move");
	ft_print_str(frac, "'c'          - Change color");
}
