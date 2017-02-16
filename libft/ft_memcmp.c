/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:34:57 by aosobliv          #+#    #+#             */
/*   Updated: 2016/11/30 17:12:18 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	unsigned const char		*news1;
	unsigned const char		*news2;

	news1 = (unsigned char*)s1;
	news2 = (unsigned char*)s2;
	i = 0;
	while (n > i)
	{
		if ((news1[i] != news2[i]))
			return ((news1[i]) - (news2[i]));
		i++;
	}
	return (0);
}
