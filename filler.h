
#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
#include <stdio.h>

typedef struct	s_fl
{
	int			fd;
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
	int			**matrix;
	char		**figure;
	char		**map;
/*
** --------------------------iterator in enemy_figure--------------------
*/
	int			en_f_y;
	int			en_f_x;
/*
** --------------------------iterator in distance --------------------
*/
	int			dis_y;
	int			dis_x;
}				t_fl;

int				main(void);
void			pars_line(t_fl *inf);
int				pars_map_xy(t_fl *inf);
int				save_map(t_fl *inf);
int				pars_figure_xy(t_fl *inf);
int				pars_figure(t_fl *inf);
int				matrix(t_fl *inf);
int				enemy_figure(t_fl *inf);
int				distance(t_fl *inf);
int				dist_forml(t_fl *inf);
int				territory(t_fl *inf);
int				valid_check(t_fl *inf, int w_m, int h_m);
void			determ_course(t_fl *inf, int h, int w);
int				ft_final_decision(t_fl *inf, int optimal, int h, int w);
void			ft_output(t_fl *inf);
void			ft_refreshers(t_fl *inf);
void			zero_out(t_fl *inf);
#endif
