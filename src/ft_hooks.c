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

int		keys_for_win1(int keycode, void *par)
{
	par = NULL;
	if (keycode == 53)
		exit(777);
	return (0);
}

int		ft_hooks(t_frac *frac)
{
	mlx_key_hook(frac->win, keys_for_win1, 0);
	return (0);
}
