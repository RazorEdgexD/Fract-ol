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
	if (frac->zoom < 2000000000)
		ft_print_str(frac, ft_strjoin("Zoom = x", ft_itoa(frac->zoom)));
	else
		ft_print_str(frac, "Zoom = Over99999");
	ft_print_str(frac, "~~~~~~~~~~~~~Key~~~~~~~~~~~");
	ft_print_str(frac, "Mouse Scroll  - Change zoom");
	ft_print_str(frac, "Mouse Move (3)- Rotation on Julia");
	ft_print_str(frac, "'1','2'       - Change iteration");
	ft_print_str(frac, "'-', '+'      - Zoom in center");
	ft_print_str(frac, "'Arrows'      - Move");
	ft_print_str(frac, "'c','v','b'   - Disco");
	ft_print_str(frac, "'5'           - Restart");
}

void	ft_print_info2(t_frac *frac)
{
	frac->text_y = 20;
	ft_print_str(frac, ft_strjoin("Fractal = ", frac->name));
	ft_print_str(frac, ft_strjoin("Iteration = ", ft_itoa(frac->iter_line)));
	if (frac->zoom < 2000000000)
		ft_print_str(frac, ft_strjoin("Zoom = x", ft_itoa(frac->zoom)));
	else
		ft_print_str(frac, "Zoom = Over99999");
	ft_print_str(frac, "~~~~~~~~~~~~~Key~~~~~~~~~~~");
	ft_print_str(frac, "Mouse Scroll  - Change zoom");
	ft_print_str(frac, "Mouse Move (3)- Rotation on Julia");
	ft_print_str(frac, "'pU','pD'     - Change iteration line Fractal");
	ft_print_str(frac, "'-', '+'      - Zoom in center");
	ft_print_str(frac, "'Arrows'      - Move");
	ft_print_str(frac, "'c','v','b'   - Disco");
	ft_print_str(frac, "'5'           - Restart");
}
