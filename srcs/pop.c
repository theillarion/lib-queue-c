#include "queue.h"

static void	ft_delete_element(t_node	**node)
{
	if (node == NULL || *node == NULL || (*node)->element == NULL)
		return;
	free((*node)->element);
	free(*node);
	*node = NULL;
}

void	ft_pop(t_queue	**queue)
{
	t_node	*backup;

	if (queue == NULL || *queue == NULL || (*queue)->head == NULL)
		return;
	backup = (*queue)->head->next;
	ft_delete_element(&(*queue)->head);
	(*queue)->head = backup;
}
