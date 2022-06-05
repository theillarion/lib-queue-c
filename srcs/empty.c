#include "queue.h"

bool	ft_empty(const t_queue	**queue)
{
	if (queue == NULL || *queue == NULL || (*queue)->head == NULL)
		return (true);
	return (false);
}
