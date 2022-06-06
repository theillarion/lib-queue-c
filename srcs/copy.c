#include "queue.h"

void	ft_copy(const t_queue	**src, t_queue	**dst)
{
	t_node	*current;

	if (src == NULL || *src == NULL || dst == NULL || *dst == NULL)
		return;
	current = (*src)->head;
	while (current != NULL)
	{
		ft_push(dst, current->element);
		current = current->next;
	}
}
