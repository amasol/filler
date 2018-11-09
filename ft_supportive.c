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

	y = -1;
	while (++y < inf->pic_y)
		free(inf->figure[y]);
	free(inf->figure);
	y = -1;
	while (++y < inf->map_y)
		free(inf->map[y]);
	free(inf->map);
	y = -1;
	while (++y < inf->map_y)
		free(inf->matrix[y]);
	free(inf->matrix);
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
