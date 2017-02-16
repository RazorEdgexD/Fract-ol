/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:09:50 by aosobliv          #+#    #+#             */
/*   Updated: 2016/11/28 19:07:40 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*arr;
	size_t	len;

	len = ft_strlen(s1);
	if ((arr = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_strncpy(arr, s1, len);
	arr[len] = '\0';
	return (arr);
}
