/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:06:17 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/05 17:06:19 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *nextptr;

	ptr = *alst;
	while (ptr)
	{
		del(ptr->content, ptr->content_size);
		nextptr = ptr->next;
		free(ptr);
		ptr = nextptr;
	}
	ptr = NULL;
	*alst = NULL;
}
