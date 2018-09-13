
#include "filler.h"
#include <stdio.h>

int		main(void)
{
	t_fl *inf;

	inf = (t_fl *)ft_memalloc(sizeof(t_fl));
	zero_out(inf);
	pars_line(inf);
	matrix(inf);
	territory(inf);
	ft_output(inf);
	ft_refreshers(inf);
	while (inf)
	{
		if (pars_map_xy(inf))
		{
			matrix(inf);
			territory(inf);
			ft_output(inf);
			ft_refreshers(inf);
		}
		else
			return (0);
	}
	//	free(inf.len);
	return (0);
}