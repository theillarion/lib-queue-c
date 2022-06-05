#include "../includes/queue.h"
#include <stdio.h>
#include <stdint.h>

void	ft_my_push(t_queue	**queue, int	element)
{
	ft_push(queue, (void *)&element);
}

int	ft_my_top(t_queue	**queue)
{
	return (*(int *)ft_top((const t_queue	**)queue));
}

int main()
{
	t_queue	*queue;
	int		number = 100;

	ft_init(&queue, sizeof(int));

	ft_push(&queue, (void *)&number);
	ft_my_push(&queue, INT32_MAX);
	ft_my_push(&queue, 0);
	ft_my_push(&queue, INT32_MIN);
	ft_my_push(&queue, 777);

	printf("First elem: %d\n", *(int *)ft_top((const t_queue **)&queue));

	printf("All elemes with first:\n");
	while (!ft_empty((const t_queue **)&queue))
	{
		printf("%d\n", ft_my_top(&queue));
		ft_pop(&queue);
	}
	
	ft_deinit(&queue);

	return (0);
}
