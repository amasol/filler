
#include "filler.h"

int		territory(t_fl *inf)
{
	int		y;
	int		x;

	y = 0;
	while (inf->map_y - inf->pic_y + 1 > y)
	{
		x = 0;
		while (inf->map_x - inf->pic_x + 1 > x)
		{
			if (valid_check(inf, y, x))
				determ_course(inf, y, x);
			x++;
		}
		y++;
	}
	return (1);
}

int		valid_check(t_fl *inf, int ter_y, int ter_x)
{
	int y;
	int x;
	int val_fig;

	x = 0;
	val_fig = 0;
	while (x < inf->pic_x)
	{
		y = 0;
		while (y < inf->pic_y)
		{
			if (inf->figure[y][x] == '*')
			{
				if (!(val_fig) && (inf->map[y + ter_y][x + ter_x] == inf->my_bot))
				{
					val_fig = 1;
				}
				else if (inf->map[ter_y + y][ter_x + x] != '.')
					return (0);
			}
			y++;
		}
		x++;
	}
	return ((val_fig) ? 1 : 0);
}

void	determ_course(t_fl *inf, int h, int w)
{
	int dc_y;
	int dc_x;
	int	opt_turn;

	dc_x = 0;
	opt_turn = 0;
	while (dc_x < inf->pic_x)
	{
		dc_y = 0;
		while (dc_y < inf->pic_y)
		{
			if (inf->figure[dc_y][dc_x] == '*')
			{
				opt_turn += (inf->matrix)[dc_y + h][dc_x + w];
			}
			dc_y++;
		}
		dc_x++;
	}
	ft_final_decision(inf, opt_turn, h, w);
}

int		ft_final_decision(t_fl *inf, int optimal, int h, int w)
{
	if (inf->mites > optimal)
	{
		inf->end_y = h;
		inf->end_x = w;
		inf->mites = optimal;
	}
	return (1);
}

void	ft_output(t_fl *inf)
{
	ft_putnbr(inf->end_y);
	write(1, " ", 1);
	ft_putnbr(inf->end_x);
	write(1, "\n", 1);
}
