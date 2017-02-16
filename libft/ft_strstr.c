/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:16:10 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/02 19:59:41 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int ii;

	i = -1;
	ii = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[++i] != '\0')
	{
		while (big[i + ii] == little[ii])
		{
			ii++;
			if (little[ii] == '\0')
				return ((char *)&big[i]);
		}
		ii = 0;
	}
	return (NULL);
}
