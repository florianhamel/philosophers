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

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	t_elem		*elem_lst;

	pthread_mutex_init(&mutex, NULL);
	elem_lst = malloc(sizeof(t_elem));
	elem_lst->status = 0;
	elem_lst->next = malloc(sizeof(t_elem));
	elem_lst->next->status = 0;
	elem_lst->prev = elem_lst->next;
	pthread_create(&t1, NULL, f1, (void *)elem_lst);
	pthread_create(&t2, NULL, f1, (void *)elem_lst);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}