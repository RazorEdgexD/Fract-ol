/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:47:42 by aosobliv          #+#    #+#             */
/*   Updated: 2016/11/30 17:42:06 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*newdst;
	unsigned char		*newsrc;
	size_t				i;

	newdst = (unsigned char*)dst;
	newsrc = (unsigned char*)src;
	i = 0;
	if (newdst < newsrc)
	{
		while (len-- != 0)
		{
			newdst[i] = newsrc[i];
			i++;
		}
	}
	if (newdst > newsrc)
	{
		while (len-- != 0)
			newdst[len] = newsrc[len];
	}
	return (dst);
}
