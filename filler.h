/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:24:19 by amasol            #+#    #+#             */
/*   Updated: 2018/09/14 14:24:22 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct	s_fl
{
	int			map_y;
	int			map_x;
	int			pic_y;
	int			pic_x;
	int			mites;
	int			end_y;
	int			end_x;
	char		my_bot;
	char		bot_enemy;
	char		*line;
	int			en_f_y;
	int			en_f_x;
	int			dis_y;
	int			dis_x;
	int			**matrix;
	int			opt_turn;
	int			t_y;
	int			t_x;
	char		**map;
	char		**figure;
}				t_fl;

int				main(void);
int				pars_line(t_fl *inf);
int				pars_map_xy(t_fl *inf);
int				save_map(t_fl *inf);
int				pars_figure_xy(t_fl *inf);
int				matrix(t_fl *inf);
int				enemy_figure(t_fl *inf);
int				distance(t_fl *inf);
int				dist_forml(t_fl *inf);
int				territory(t_fl *inf);
int				valid_check(t_fl *inf);
int				determ_course(t_fl *inf);
int				ft_final_decision(t_fl *inf);
int				ft_output(t_fl *inf);
int				ft_refreshers(t_fl *inf);
void			zero_out(t_fl *inf);
int				parsing(t_fl *inf);

#endif
