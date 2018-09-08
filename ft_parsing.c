/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:15:06 by amasol            #+#    #+#             */
/*   Updated: 2018/09/07 13:15:07 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			zero_out(t_fl *inf)
{
	inf->fd = 0;
	inf->map_x = 0;
	inf->map_y = 0;
	inf->pic_y = 0;
	inf->pic_x = 0;
}

int				parsing(t_fl *inf)
{
	pars_line(inf);
	pars_map_xy(inf);
	save_map(inf);
	pars_figure_xy(inf);
	pars_figure(inf);

	return (1);
}

int				pars_line(t_fl *inf)
{
	inf->fd = open("test", O_RDONLY);
	if (get_next_line(inf->fd, &inf->len) > 0)
	{
		if (*(inf->len + 10) == '1')
			inf->my_o = 'O';
		else
			inf->bot_x = 'X';
		if (inf->my_o == 'O')
			inf->bot_x = 'X';
	}
	free(inf->len);
	return (1);
}

int				pars_map_xy(t_fl *inf)
{
	if (get_next_line(inf->fd, &inf->len) > 0)
	{
		inf->map_y = ft_atoi(inf->len + 8);
		inf->map_x = ft_atoi(inf->len + 10);
		free(inf->len);
	}
	else
		return (0);
	return (1);
}

int				save_map(t_fl *inf)
{
	int i_map_y;

	i_map_y -= 1;
	get_next_line(inf->fd, &inf->len);
	free(inf->len);
	if (!(inf->map = (char **)malloc(sizeof(char *) * (inf->map_y + 1))))
		return (0);
	while (get_next_line(inf->fd, &inf->len) && i_map_y < inf->map_y)
	{
		inf->map[i_map_y] = ft_strsub(inf->len, 4, (size_t)inf->map_x);
		free(inf->len);
		i_map_y++;
	}
	return (1);
}
