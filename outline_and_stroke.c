/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outline_and_stroke.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:32:49 by amasol            #+#    #+#             */
/*   Updated: 2018/09/12 16:32:53 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			dist_forml(t_fl *inf)
{
	int dest;
	int dest_two;
	int dest_three;

	dest = 0;
	dest_two = (inf->dis_y - inf->en_f_heig);
	if (dest_two < 0)
		dest_two *= -1;
	dest_three = (inf->dis_x - inf->en_f_wid);
	if (dest_three < 0)
		dest_three *= -1;
	return (dest_two + dest_three);
}

void	territory(t_fl *inf)
{
	int y;
	int x;

	y = 0;
	while (y < inf->map_y - (inf->pic_y + 1))
	{
		x = 0;
		while (x < inf->map_x - (inf->pic_x + 1))
		{
			if (valit_check(x, y, inf)) // можно ли поставить фигуру в данную точку
				determ_course(x, y, inf); // определение оптимального хода
		}
		x++;
	}
	y++;
}

int				valit_check(int ter_x, int ter_y, t_fl *inf)
{
	int y;
	int x;
	int val_fig;

	x = 0;
	val_fig = 0;
	while (x < inf->pic_x)
	{
		y = 0;
		while (y < inf->pic_y)
		{
			if (inf->figure[y][x] == '*')
			{
				if (!(val_fig) && (inf->map[y + ter_y][x + ter_x] == inf->my_bot))
					val_fig = 1;
				else if (inf->map[ter_y + y][ter_x + x] != '.')
					return (0);
			}
			y++;
		}
		x++;
	}
	return ((val_fig) ? 1 : 0);
}

void			determ_course(int x, int y, t_fl *inf)
{
	int dc_y;
	int dc_x;
	int opt_turn;

	dc_x = 0;
	opt_turn = 0;
	while (dc_x < inf->pic_x)
	{
		dc_y = 0;
		while (dc_y < inf->pic_y)
		{
			if (inf->figure[dc_y][dc_x] == '*')
				opt_turn += (inf->matrix[dc_y + y][dc_x + x]);
			dc_y++;
		}
		dc_x++;
	}
	put(inf, opt_turn, dc_y, dc_y);
}

int 		put(t_fl *inf, int optimal, int y, int x)
{
	if (optimal < inf->mites)
	{
		inf->mites = optimal;
		inf->end_y = y;
		inf->end_x = x;
	}
	return (0);
}
