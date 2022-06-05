#include "../includes/queue.h"
#include <stdio.h>
#include <stdint.h>

void	ft_my_push(t_queue	**queue, char	*element)
{
	ft_push(queue, (void *)&element);
}

char	*ft_my_top(t_queue	**queue)
{
	return (*(char	**)ft_top((const t_queue	**)queue));
}

int main()
{
	t_queue	*queue;
	char	*my_string = "ffff";

	ft_init(&queue, sizeof(char *));

	ft_push(&queue, (void *)&my_string);
	ft_my_push(&queue, "Hello");
	ft_my_push(&queue, "World");
	ft_my_push(&queue, "0");
	ft_my_push(&queue, "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ");

	printf("First elem: %s\n", *(char **)ft_top((const t_queue **)&queue));

	printf("All elemes with first:\n");
	while (!ft_empty((const t_queue **)&queue))
	{
		printf("%s\n", ft_my_top(&queue));
		ft_pop(&queue);
	}
	
	ft_deinit(&queue);

	return (0);
}
