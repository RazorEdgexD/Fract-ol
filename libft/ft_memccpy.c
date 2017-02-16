/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:36:37 by aosobliv          #+#    #+#             */
/*   Updated: 2016/11/28 19:09:15 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	size_t				i;
	unsigned char		*newdst;
	unsigned const char *newsrc;

	i = 0;
	newdst = (unsigned char *)dst;
	newsrc = (unsigned const char *)src;
	while (i < n)
	{
		newdst[i] = newsrc[i];
		if (newsrc[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
