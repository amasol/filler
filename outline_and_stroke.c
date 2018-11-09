/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outline_and_stroke.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:24:58 by amasol            #+#    #+#             */
/*   Updated: 2018/09/14 14:25:04 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		territory(t_fl *inf)
{
	inf->t_y = 0;
	while (inf->map_y - inf->pic_y + 1 > inf->t_y)
	{
		inf->t_x = 0;
		while (inf->map_x - inf->pic_x + 1 > inf->t_x)
		{
			if (valid_check(inf))
				determ_course(inf);
			inf->t_x++;
		}
		inf->t_y++;
	}
	return (1);
}

int		valid_check(t_fl *inf)
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
				if (!(val_fig) && (inf->map[y + inf->t_y][x + inf->t_x]
					== inf->my_bot))
					val_fig = 1;
				else if (inf->map[inf->t_y + y][inf->t_x + x] != '.')
					return (0);
			}
			y++;
		}
		x++;
	}
	return ((val_fig) ? 1 : 0);
}

int		determ_course(t_fl *inf)
{
	int dc_y;
	int dc_x;

	dc_x = 0;
	inf->opt_turn = 0;
	while (dc_x < inf->pic_x)
	{
		dc_y = 0;
		while (dc_y < inf->pic_y)
		{
			if (inf->figure[dc_y][dc_x] == '*')
				inf->opt_turn +=
				(inf->matrix)[dc_y + inf->t_y][dc_x + inf->t_x];
			dc_y++;
		}
		dc_x++;
	}
	return (ft_final_decision(inf));
}

int		ft_final_decision(t_fl *inf)
{
	if (inf->mites > inf->opt_turn)
	{
		inf->end_y = inf->t_y;
		inf->end_x = inf->t_x;
		inf->mites = inf->opt_turn;
	}
	return (1);
}

int		ft_output(t_fl *inf)
{
	ft_putnbr(inf->end_y);
	write(1, " ", 1);
	ft_putnbr(inf->end_x);
	write(1, "\n", 1);
	return (1);
}
