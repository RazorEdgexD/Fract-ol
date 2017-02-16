/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:53:39 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/02 20:08:09 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		module(int len, int i)
{
	if (len - i > 0)
		return (len - i);
	if (len - i < 0)
		return (-(len - i));
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	char	*arr;
	int		len;
	int		j;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && s[i] != '\0')
		i++;
	len = ft_strlen(s);
	while ((s[len - 1] == '\t' || s[len - 1] == '\n'
		|| s[len - 1] == ' ') && s[len - 1] != '\0')
		len--;
	arr = ft_strnew(module(len, i));
	if (arr == NULL)
		return (NULL);
	j = 0;
	while (i < len)
		arr[j++] = s[i++];
	return (arr);
}
