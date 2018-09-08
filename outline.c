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

int				pars_figure_xy(t_fl *inf)
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

int				pars_figure(t_fl *inf)
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


