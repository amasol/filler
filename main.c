#include "filler.h"

int main(void)
{
	t_fl inf;

//	inf = (t_fl *)malloc(sizeof(t_fl));

	zero_out(&inf);
	parsing(&inf);


//	free(inf.len);
//	system("leaks filler");
	return (0);
}