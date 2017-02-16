/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:04:10 by aosobliv          #+#    #+#             */
/*   Updated: 2016/11/27 14:12:03 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *arr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	arr = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (arr != NULL)
	{
		arr = ft_strcat(arr, s1);
		arr = ft_strcat(arr, s2);
		return (arr);
	}
	return (NULL);
}
