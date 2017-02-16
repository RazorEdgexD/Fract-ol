/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:06:38 by aosobliv          #+#    #+#             */
/*   Updated: 2016/11/23 15:11:42 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int res;
	int minus;
	int i;

	i = 0;
	minus = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	res = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			break ;
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * minus);
}
