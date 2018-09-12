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
	int			**matrix;
	int			fd;
	char		*len;
	char		my_bot;
	char 		bot_enemy;
	int			map_x;
	int			map_y;
	int			pic_y;
	int			pic_x;
	char		**map;
	char		**figure;
	int			mites;
	int			end_y;
	int			end_x;
/*
** --------------------------iterator in enemy_figure--------------------
*/
	int			en_f_heig;
	int			en_f_wid;
/*
** --------------------------iterator in distance --------------------
*/
	int			dis_y;
	int			dis_x;
}				t_fl;

int				main(void);
int				parsing(t_fl *inf);
int				pars_line(t_fl *inf);
int				pars_map_xy(t_fl *inf);
void			zero_out(t_fl *inf);
int				save_map(t_fl *inf);
int				pars_figure_xy(t_fl *inf);
int				pars_figure(t_fl *inf);
int				matrix(t_fl *inf);
void			enemy_figure(t_fl *inf);
void			distance(t_fl *inf);
int				dist_forml(t_fl *inf);
void			territory(t_fl *inf);
int				valit_check(int ter_x, int ter_y, t_fl *inf);
void			determ_course(int x, int y, t_fl *inf);
int				put(t_fl *inf, int optimal, int y, int x);

#endif
