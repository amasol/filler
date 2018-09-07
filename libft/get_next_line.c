/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:36:14 by amasol            #+#    #+#             */
/*   Updated: 2018/04/11 21:28:35 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_check_n(char **line, t_str **lst)
{
	t_help r;

	r.len = 0;
	r.tmp = (*lst)->buff;
	if ((*lst)->buff && !(r.i = 0))
	{
		while ((*lst)->buff[r.i] && (*lst)->buff[r.i] != '\n')
			r.i++;
		r.j = 0;
		if ((*lst)->buff[r.j] == '\n')
		{
			*line = ft_strdup("\0");
			(*lst)->buff = ft_strsub((*lst)->buff, r.i + 1,
			ft_strlen((*lst)->buff) - r.i);
			ft_strdel(&r.tmp);
			return (1);
		}
		else
			*line = ft_strsub((*lst)->buff, 0, r.i);
		(*lst)->buff = ft_strsub((*lst)->buff, r.i + 1,
		ft_strlen((*lst)->buff) - r.i);
		ft_strdel(&r.tmp);
	}
	r.len = ft_strlen(*line);
	return ((r.len = r.len > 0 ? 1 : 0));
}

static t_str	*ft_check_fd(t_str **memory, int fd)
{
	t_str *lst;

	if (!(*memory))
	{
		*memory = (t_str *)malloc(sizeof(t_str));
		(*memory)->fd = fd;
		(*memory)->buff = ft_strnew(0);
		(*memory)->next = NULL;
	}
	lst = *memory;
	while (lst->fd != fd && lst->next)
		lst = lst->next;
	if (lst->fd != fd)
	{
		lst->next = (t_str *)malloc(sizeof(t_str));
		lst = lst->next;
		lst->fd = fd;
		lst->next = NULL;
		lst->buff = ft_strnew(0);
	}
	return (lst);
}

int				get_next_line(const int fd, char **line)
{
	t_str			*lst;
	static t_str	*memory;
	char			*clean;
	int				flag;

	flag = 0;
	if (fd < 0 || !line)
		return (-1);
	lst = ft_check_fd(&memory, fd);
	if (read(lst->fd, lst->data, 0) < 0)
		return (-1);
	while ((flag = read(lst->fd, lst->data, BUFF_SIZE)) > 0)
	{
		lst->data[flag] = '\0';
		clean = lst->buff;
		lst->buff = ft_strjoin(lst->buff, lst->data);
		ft_strdel(&clean);
		if (lst->buff && ft_strchr(lst->buff, '\n'))
			break ;
	}
	if (lst->buff[0] == '\0')
		return (0);
	flag = ft_check_n(line, &lst);
	return (flag);
}
