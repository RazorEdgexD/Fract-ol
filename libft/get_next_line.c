/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:07:50 by aosobliv          #+#    #+#             */
/*   Updated: 2017/01/11 14:06:23 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_sj_f(char *s1, char *s2)
{
	char	*arr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	arr = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (arr != NULL)
	{
		arr = ft_strcat(arr, s1);
		arr = ft_strcat(arr, s2);
		free(s1);
		return (arr);
	}
	return (NULL);
}

static t_gnl	*ft_pick_lst(t_gnl **lst, int fd)
{
	t_gnl	**tmp;

	tmp = lst;
	while (*tmp)
	{
		if ((*tmp)->fd == fd)
			return (*tmp);
		tmp = &(*tmp)->next;
	}
	if (*tmp == NULL)
	{
		*tmp = malloc(sizeof(**tmp));
		(*tmp)->fd = fd;
		(*tmp)->str = NULL;
		(*tmp)->next = NULL;
	}
	return (*tmp);
}

static int		ft_line_from_lst(char **line, t_gnl *lst)
{
	char	*tmp;

	if (!lst->str)
		return (0);
	if ((tmp = ft_strchr(lst->str, '\n')))
	{
		*line = ft_sj_f(*line, ft_strsub(lst->str, 0, tmp - lst->str));
		lst->str = ft_strdup(lst->str + (tmp - lst->str) + 1);
		return (1);
	}
	else
	{
		*line = ft_sj_f(*line, lst->str);
		ft_strdel(&(lst->str));
		lst->str = NULL;
	}
	return (0);
}

static int		ft_line_from_fd(char **line, t_gnl *lst)
{
	int		handle;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((handle = read(lst->fd, buf, BUFF_SIZE)))
	{
		if (handle == -1)
			return (-1);
		buf[handle] = '\0';
		if ((tmp = ft_strchr(buf, '\n')))
		{
			*line = ft_sj_f(*line, ft_strsub(buf, 0, tmp - buf));
			lst->str = ft_strdup(buf + (tmp - buf) + 1);
			return (1);
		}
		else
			*line = ft_sj_f(*line, buf);
	}
	if (handle == 0 && **line == '\0')
		return (0);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*list = NULL;
	t_gnl			*tmp;

	if (!line || fd < 0)
		return (-1);
	if (*line)
		*line = NULL;
	*line = ft_strdup("");
	tmp = ft_pick_lst(&list, fd);
	if (ft_line_from_lst(line, tmp))
		return (1);
	return (ft_line_from_fd(line, tmp));
}
