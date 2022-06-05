#include "../includes/queue.h"
#include <stdio.h>
#include <stdint.h>

typedef struct s_point
{
	int x;
	int y;
}	t_point;

void	ft_my_push(t_queue	**queue, t_point	element)
{
	ft_push(queue, (void *)&element);
}

t_point	ft_my_top(t_queue	**queue)
{
	return (*(t_point *)ft_top((const t_queue	**)queue));
}

t_point	ft_create_point(int x, int y)
{
	t_point	result;

	result.x =x;
	result.y = y;
	return (result);
}

int main()
{
	t_queue	*queue;
	t_point	point;

	point.x = INT32_MIN;
	point.y = INT32_MAX;

	ft_init(&queue, sizeof(t_point));

	ft_push(&queue, (void *)&point);
	ft_my_push(&queue, ft_create_point(10, 15));
	ft_my_push(&queue, ft_create_point(-4, 7));

	printf("First elem: {%d, %d}\n",	(*(t_point *)ft_top((const t_queue **)&queue)).x,
										(*(t_point *)ft_top((const t_queue **)&queue)).y);

	printf("All elemes with first:\n");
	while (!ft_empty((const t_queue **)&queue))
	{
		t_point	s = ft_my_top(&queue);
		printf("{%d, %d}\n", s.x, s.y);
		ft_pop(&queue);
	}
	
	ft_deinit(&queue);

	return (0);
}
