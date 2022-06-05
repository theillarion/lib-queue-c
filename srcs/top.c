#include "queue.h"

void	*ft_top(const t_queue	**queue)
{
	if (queue == NULL || *queue == NULL || (*queue)->head == NULL)
		return (NULL);
	return ((*queue)->head->element);
}
