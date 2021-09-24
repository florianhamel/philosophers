#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

long int	get_elapsed_ms(struct timeval tv_start)
{
	struct timeval	tv;
	long			time_start;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec - tv_start.tv_sec) * 1000;
	time += (tv.tv_usec - tv_start.tv_usec) / 1000;
	return (time - time_start);
}

int	main(void)
{
	struct timeval	tv_start;
	struct timeval	tv;

	gettimeofday(&tv_start, NULL);
	sleep(5);
	printf("%ld\n", get_elapsed_ms(tv_start));
	return (0);
}