/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:00:47 by aosobliv          #+#    #+#             */
/*   Updated: 2016/11/27 14:13:41 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *arr;

	arr = (unsigned char*)malloc(sizeof(unsigned char) * size);
	if (arr != NULL)
	{
		ft_bzero(arr, size);
		return (arr);
	}
	return (NULL);
}
