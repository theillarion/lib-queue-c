#include "queue.h"

void	ft_deinit(t_queue	**queue)
{
	if (queue == NULL || *queue == NULL)
		return;
	while ((*queue)->head != NULL)
		ft_pop(queue);
	free(*queue);
	*queue = NULL;
}
