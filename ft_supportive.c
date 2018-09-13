
#include "filler.h"

void	ft_refreshers(t_fl *inf)
{
	int h;

	h = 0;
	while (h < inf->pic_y)
	{
		free(inf->figure[h]);
		h++;
	}
	free(inf->figure);
	h = 0;
}
