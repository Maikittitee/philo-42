#include "philo.h"

int	main()
{
	long ms_start;

	ms_start = ms_from_epoch();
	usleep(5000000);
	printf("take time : %ld", ms_time_diff(ms_start));

	return (0);
}