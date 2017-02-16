/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:06:21 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/02 20:02:22 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int		i;

	i = 1;
	while ((n / 10) != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char		*ft_minimum(void)
{
	char	*min;

	min = ft_strcpy(ft_strnew(11), "-2147483648");
	return (min);
}

char			*ft_itoa(int n)
{
	int		i;
	int		minus;
	char	*res;
	int		mas;

	minus = 0;
	if (n == -2147483648)
		return (ft_minimum());
	if (n < 0)
	{
		minus = 1;
		n = n * (-1);
	}
	mas = n;
	i = ft_count(n);
	if ((res = ft_strnew(i + minus)) == NULL)
		return (NULL);
	while (i > 0)
	{
		res[i-- - 1 + minus] = ((mas % 10) + '0');
		mas = mas / 10;
	}
	if (minus == 1)
		res[i] = '-';
	return (res);
}
