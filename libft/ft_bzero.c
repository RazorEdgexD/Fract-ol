/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:43:12 by aosobliv          #+#    #+#             */
/*   Updated: 2016/11/28 19:08:57 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*arr;
	size_t				i;

	i = 0;
	arr = (unsigned char*)s;
	if (n == 0)
		return ;
	while (i < n)
	{
		arr[i] = '\0';
		i++;
	}
}
