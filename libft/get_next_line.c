/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:43:01 by klut              #+#    #+#             */
/*   Updated: 2017/09/12 16:49:06 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_gnl_node	*ft_lst_create(int fd)
{
	t_gnl_node					*file;

	file = (t_gnl_node *)malloc((sizeof(t_gnl_node)));
	file->file_descr = fd;
	file->inf = NULL;
	file->next = NULL;
	return (file);
}

static	t_gnl_node	*ft_lst_managment(int fd, t_gnl_node *ptr)
{
	while (ptr)
	{
		if (fd != ptr->file_descr)
		{
			if (ptr->next == NULL)
			{
				ptr->next = ft_lst_create(fd);
				return (ptr->next);
			}
			else
				ptr = ptr->next;
		}
		else
			return (ptr);
	}
	return (ptr);
}

int					newline_finder(t_gnl_node *pf, char *buff, char **line,
		int number)
{
	char						*position;
	char						*ptr;
	unsigned long				len;

	ptr = *line;
	if (ft_strchr(buff, '\n'))
	{
		position = ft_strchr(buff, '\n');
		len = position - buff;
		buff[len] = '\0';
		position++;
		*line = ft_strjoin(*line, buff);
		if (ptr != NULL)
			free(ptr);
		pf->inf = ft_strdup(position);
		return (1);
	}
	*line = ft_strjoin(*line, buff);
	if (ptr != NULL)
		free(ptr);
	ft_bzero(buff, number);
	return (0);
}

int					main_sequence(t_gnl_node *pf, char **line, int fd,
		char *buff)
{
	int number;

	*line = ft_strnew(1);
	if (pf->inf != NULL)
	{
		number = ft_strlen(pf->inf);
		if (newline_finder(pf, pf->inf, line, number))
			return (1);
	}
	while ((number = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[number] = '\0';
		if (newline_finder(pf, buff, line, number))
			return (1);
	}
	if (number == 0 && ft_strlen(*line) == 0)
		return (0);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static	t_gnl_node			*primary_node;
	t_gnl_node					*temporary_node;
	char						array_buffer[BUFF_SIZE + 1];

	if ((fd < 0 || BUFF_SIZE < 1 || line == NULL
				|| read(fd, array_buffer, 0) < 0) || fd > OPEN_MAX)
		return (-1);
	while (primary_node)
	{
		temporary_node = ft_lst_managment(fd, primary_node);
		return (main_sequence(temporary_node, line, fd, array_buffer));
	}
	if (!primary_node)
		primary_node = ft_lst_create(fd);
	return (main_sequence(primary_node, line, fd, array_buffer));
}
