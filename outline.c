/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:09:20 by amasol            #+#    #+#             */
/*   Updated: 2018/09/08 19:09:21 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			pars_figure_xy(t_fl *inf)
{
	if (inf->len)
	{
		inf->pic_y = ft_atoi(inf->len + 6);
		inf->pic_x = ft_atoi(inf->len + 8);
		free(inf->len);
	}
	else
		return (0);
	return (1);
}

int			pars_figure(t_fl *inf)
{
	int i_fig_y;

	i_fig_y = 0;
	if (!(inf->figure = (char **)malloc(sizeof(char *) * (inf->pic_y + 1))))
		return (0);
	while (get_next_line(inf->fd, &inf->len) && i_fig_y < inf->pic_y)
	{
		inf->figure[i_fig_y] = ft_strsub(inf->len, 0, (size_t)inf->pic_x);
		free(inf->len);
		i_fig_y++;
	}
	return (1);
}

int			matrix(t_fl *inf)
{
	int wid;
	int heig;

	if (!(inf->matrix = (int **)malloc(sizeof(int *) * (inf->map_y + 1))))
		return (0);
	heig = 0;
	inf->map[inf->map_y + 1] = NULL;
	inf->mites = 9999;
	while (inf->map_y > heig)
	{
		wid = 0;
		if (!(inf->matrix[heig] = (int *)malloc(sizeof(int) * (inf->map_x + 1))))
			return (0);
		inf->matrix[heig][inf->map_x + 1] = '\0';
		while (inf->map_x > wid)
		{
			inf->matrix[heig][wid] = 9999;
			wid++;
		}
		heig++;
	}
	enemy_figure(inf);
	return (1);
}

void		enemy_figure(t_fl *inf) //находим вражескую фигуру
{
	inf->en_f_heig = 0;
	while (inf->map_y > inf->en_f_heig)
	{
		inf->en_f_wid = 0;
		while (inf->map_x > inf->en_f_wid)
		{
			if (inf->map[inf->en_f_heig][inf->en_f_wid] == inf->bot_enemy)
				distance(inf);
			inf->en_f_wid++;
		}
		inf->en_f_heig++;
	}
}

void		distance(t_fl *inf) // дистанцию
{
	int distance;

	distance = 0;
	inf->dis_y = 0;
	while (inf->map_y > inf->dis_y)
	{
		inf->dis_x = 0;
		while (inf->map_x > inf->dis_x)
		{
			if (inf->map[inf->dis_y][inf->dis_x] == inf->my_bot)
				inf->matrix[inf->dis_y][inf->dis_x] = -1;
			else if (inf->map[inf->dis_y][inf->dis_x] == inf->bot_enemy)
				inf->matrix[inf->dis_y][inf->dis_x] = -2;
			else
			{
				distance = dist_forml(inf);
				if (distance > -1 && distance < inf->matrix[inf->dis_y][inf->dis_x])
					inf->matrix[inf->dis_y][inf->dis_x] = distance;
			}
			inf->dis_x++;
		}
		inf->dis_y++;
	}
}