/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:43:49 by amasol            #+#    #+#             */
/*   Updated: 2018/09/07 12:43:50 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_fl
{
	int			fd;
	char		*len;
	char		my_o;
	char 		bot_x;
	int			map_x;
	int			map_y;
	int			pic_y;
	int			pic_x;
	char		**map;
	char		**figure;
}				t_fl;

int				main(void);
int				parsing(t_fl *inf);
int				pars_line(t_fl *inf);
int				pars_map_xy(t_fl *inf);
void 			zero_out(t_fl *inf);
int				save_map(t_fl *inf);
int				pars_figure_xy(t_fl *inf);
int				pars_figure(t_fl *inf);

#endif
