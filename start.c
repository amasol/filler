/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:25:31 by amasol            #+#    #+#             */
/*   Updated: 2018/09/14 14:25:32 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			zero_out(t_fl *inf)
{
	inf->map_x = 0;
	inf->map_y = 0;
	inf->pic_y = 0;
	inf->pic_x = 0;
	inf->mites = 0;
	inf->end_y = 0;
	inf->end_x = 0;
}

int				parsing(t_fl *inf)
{
	zero_out(inf);
	pars_line(inf);
	matrix(inf);
	territory(inf);
	ft_output(inf);
	ft_refreshers(inf);
	return (1);
}
