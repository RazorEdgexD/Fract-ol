/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:57:47 by aosobliv          #+#    #+#             */
/*   Updated: 2016/11/28 19:00:23 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((arr = ft_strnew(len)) == NULL)
		return (NULL);
	while (len > 0)
	{
		arr[i] = s[start];
		start++;
		i++;
		len--;
	}
	arr[start] = '\0';
	return (arr);
}
