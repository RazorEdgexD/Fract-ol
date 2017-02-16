/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:40:35 by aosobliv          #+#    #+#             */
/*   Updated: 2016/11/28 19:07:54 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*news;

	i = 0;
	news = (unsigned char *)s;
	while (i < n)
	{
		if (news[i] == (unsigned char)c)
			return (&news[i]);
		i++;
	}
	return (NULL);
}
