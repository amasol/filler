/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:25:17 by amasol            #+#    #+#             */
/*   Updated: 2018/09/14 14:25:18 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		pars_line(t_fl *inf)
{
	if (get_next_line(0, &inf->line) > 0)
	{
		if (*(inf->line + 10) == '1')
			inf->my_bot = 'O';
		else
			inf->my_bot = 'X';
		if (inf->my_bot == 'O')
			inf->bot_enemy = 'X';
		else
			inf->bot_enemy = 'O';
	}
	free(inf->line);
	return (pars_map_xy(inf));
}

int		pars_map_xy(t_fl *inf)
{
	if (get_next_line(0, &inf->line) > 0)
	{
		inf->map_y = ft_atoi(inf->line + 8);
		inf->map_x = ft_atoi(inf->line + 11);
		free(inf->line);
	}
	else
		return (0);
	return (save_map(inf));
}

int		save_map(t_fl *inf)
{
	int		i_map_y;

	i_map_y = 0;
	get_next_line(0, &inf->line);
	free(inf->line);
	if (!(inf->map = (char **)malloc(sizeof(char *) * (inf->map_y + 1))))
		return (0);
	while (get_next_line(0, &inf->line) && i_map_y < inf->map_y)
	{
		inf->map[i_map_y] = ft_strsub(inf->line, 4, (size_t)inf->map_x);
		i_map_y++;
		free(inf->line);
	}
	return (pars_figure_xy(inf));
}

int		pars_figure_xy(t_fl *inf)
{
	int i_fig_y;

	if (inf->line)
	{
		inf->pic_y = ft_atoi(inf->line + 6);
		inf->pic_x = ft_atoi(inf->line + 8);
		free(inf->line);
	}
	if (!(inf->figure = (char **)malloc(sizeof(char *) * (inf->pic_y + 1))))
		return (0);
	i_fig_y = -1;
	while (++i_fig_y < inf->pic_y && get_next_line(0, &inf->line))
	{
		inf->figure[i_fig_y] = ft_strdup(inf->line);
		free(inf->line);
	}
	return (1);
}
