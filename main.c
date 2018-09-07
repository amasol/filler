#include "filler.h"

//	inf = (t_fl *)malloc(sizeof(t_fl));
int main(void)
{
	t_fl inf;

	zero_out(&inf);
	parsing(&inf);
	free(inf.len);
//	system("leaks filler");
	return (0);
}