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

void 			zero_out(t_fl *inf)
{
	inf->map_x = 0;
	inf->map_y = 0;
	inf->fd = 0;
}


int				parsing(t_fl *inf)
{
	pars_line(inf);
	pars_map(inf);
//	printf("%s\n", inf->len);

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

int			pars_map(t_fl *inf)
{
	if (get_next_line(inf->fd, &inf->len) > 0)
	{
		inf->map_y = ft_atoi(inf->len + 8);
		inf->map_x = ft_atoi(inf->len + 10);




	}
//	free(inf->len);
	return (1);
}
