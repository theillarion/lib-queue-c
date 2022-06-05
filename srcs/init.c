#include "queue.h"

void	ft_init(t_queue	**queue, size_t size_element)
{
	if (queue == NULL || size_element == 0)
		return;
	*queue = (t_queue *)malloc(sizeof(**queue));
	(*queue)->size_element = size_element;
	(*queue)->head = NULL;
}
