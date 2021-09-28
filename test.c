#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

pthread_mutex_t	mutex;

typedef struct s_elem
{
	int				status;
	struct s_elem	*prev;
	struct s_elem	*next;
}		t_elem;

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

void	*f1(void *arg)
{
	t_elem	*elem_lst;

	elem_lst = (t_elem *)arg;
	pthread_mutex_lock(&mutex);
	usleep(2 * 1000000);
	elem_lst->status = 42;
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

void	*f2(void *arg)
{
	t_elem	*elem_lst;

	elem_lst = (t_elem *)arg;
	usleep(50000);
	printf("%d\n", elem_lst->status);
	return (NULL);
}

int	ft_usleep(long micros)
{
	struct timeval	start;
	struct timeval	tv;
	long			time;

	gettimeofday(&start, NULL);
	time = 0;
	while (time < micros)
	{
		usleep(time / 1000);
		gettimeofday(&tv, NULL);
		time = (tv.tv_sec - start.tv_sec) * 1000000;
		time += (tv.tv_usec - start.tv_usec);
	}
	return (0);
}

long	ft_time()
{
	struct timeval	t1;
	struct timeval	t2;
	long			time;

	gettimeofday(&t1, NULL);
	ft_usleep(500);
	gettimeofday(&t2, NULL);
	time = (t2.tv_sec - t1.tv_sec) * 1000;
	time += (t2.tv_usec - t1.tv_usec) / 1000;
	return (time);
}

int	main(void)
{
	printf("%lu\n", ft_time());
	return (0);
}