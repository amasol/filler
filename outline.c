/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:25:25 by amasol            #+#    #+#             */
/*   Updated: 2018/09/14 14:25:26 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		matrix(t_fl *inf)
{
	int heig;
	int wid;

	inf->end_y = -1;
	inf->end_x = -1;
	heig = 0;
	inf->mites = 9999;
	if (!(inf->matrix = (int **)malloc(sizeof(int *) * (inf->map_y + 1))))
		return (0);
	inf->matrix[inf->map_y + 1] = NULL;
	while (inf->map_y > heig)
	{
		wid = 0;
		if (!(inf->matrix[heig] =
			(int *)malloc(sizeof(int) * (inf->map_x + 1))))
			return (0);
		inf->matrix[heig][inf->map_x + 1] = '\0';
		while (inf->map_x > wid)
		{
			inf->matrix[heig][wid] = 9999;
			wid++;
		}
		heig++;
	}
	return (enemy_figure(inf));
}

int		enemy_figure(t_fl *inf)
{
	inf->en_f_y = 0;
	while (inf->map_y > inf->en_f_y)
	{
		inf->en_f_x = 0;
		while (inf->map_x > inf->en_f_x)
		{
			if (inf->map[inf->en_f_y][inf->en_f_x] == inf->bot_enemy)
				distance(inf);
			inf->en_f_x++;
		}
		inf->en_f_y++;
	}
	return (1);
}

int		distance(t_fl *inf)
{
	int		distance;

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
				if (inf->matrix[inf->dis_y][inf->dis_x]
					> distance && distance > -1)
					inf->matrix[inf->dis_y][inf->dis_x] = distance;
			}
			inf->dis_x++;
		}
		inf->dis_y++;
	}
	return (1);
}
