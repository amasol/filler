/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supportive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:24:29 by amasol            #+#    #+#             */
/*   Updated: 2018/09/14 14:24:30 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_refreshers(t_fl *inf)
{
	int y;

	y = 0;
	while (inf->pic_y > y)
	{
		free(inf->figure[y]);
		y++;
	}
	free(inf->figure);
	return (1);
}

int		dist_forml(t_fl *inf)
{
	int	distance;
	int	distance2;

	distance = (inf->dis_y - inf->en_f_y);
	if (distance < 0)
		distance *= -1;
	distance2 = (inf->dis_x - inf->en_f_x);
	if (distance2 < 0)
		distance2 *= -1;
	return (distance + distance2);
}
