/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:27:12 by aosobliv          #+#    #+#             */
/*   Updated: 2016/11/30 18:32:31 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if ((tmp = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	if (content)
	{
		if ((tmp->content = malloc(content_size)) == NULL)
			return (NULL);
		tmp->content_size = content_size;
		while ((content_size--) + 1 > 0)
		{
			*(char *)(tmp->content + content_size) =
				*(char *)(content + content_size);
		}
	}
	tmp->next = NULL;
	return (tmp);
}
