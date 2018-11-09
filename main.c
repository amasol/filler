/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:24:37 by amasol            #+#    #+#             */
/*   Updated: 2018/09/14 14:24:50 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_fl inf;

	parsing(&inf);
	while (&(inf))
	{
		if (pars_map_xy(&inf))
		{
			matrix(&inf);
			territory(&inf);
			ft_output(&inf);
			ft_refreshers(&inf);
		}
		else
			return (0);
	}
	return (0);
}
