
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

void	pars_line(t_fl*inf)
{
	//	inf->fd = open("test", O_RDONLY);
	if (get_next_line(0, &(inf->line)) > 0)
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
	pars_map_xy(inf);
}

int		pars_map_xy(t_fl *inf)
{
	if (get_next_line(0, &(inf->line)) > 0)
	{
		inf->map_y = ft_atoi(inf->line + 8);
		inf->map_x = ft_atoi(inf->line + 10);
		free(inf->line);
	}
	else
		return (0);
	save_map(inf);
	return (1);
}

int		save_map(t_fl *inf)
{
	int		i_map_y;

	i_map_y = 0;
	get_next_line(0, &inf->line);
	free(inf->line);
	if (!(inf->map = (char **)malloc(sizeof(char *) * (inf->map_y + 1))))
		return (0);
	while (get_next_line(0, &(inf->line)) && i_map_y < inf->map_y)
	{
		inf->map[i_map_y] = ft_strsub(inf->line, 4, (size_t)inf->map_x);
		free(inf->line);
		i_map_y++;
	}
	pars_figure_xy(inf);
	return (1);
}
//
int		pars_figure_xy(t_fl *inf)
{
	if (inf->line)
	{
		inf->pic_y = ft_atoi(inf->line + 6);
		inf->pic_x = ft_atoi(inf->line + 8);
		free(inf->line);
	}
	pars_figure(inf);
	return (1);
}

//

int			pars_figure(t_fl *inf)
{
	int i_fig_y;

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
