#include "queue.h"

static void	*ft_memcpy(void	*dest, const void	*src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

static t_node	*ft_create_element(void	*element, size_t size_element)
{
	t_node	*result;

	result = (t_node *)malloc(sizeof(*result));
	if (result == NULL)
		return (NULL);
	result->element = (void *)malloc(size_element);
	ft_memcpy(result->element, element, size_element);
	result->next = NULL;
	return (result);
}

void	ft_push(t_queue	**queue, void	*element)
{
	t_node	*current;

	if (queue == NULL || *queue == NULL)
		return;
	if ((*queue)->head == NULL)
		(*queue)->head = ft_create_element(element, (*queue)->size_element);
	else
	{
		current = (*queue)->head;
		while (current->next != NULL)
			current = current->next;
		current->next = ft_create_element(element, (*queue)->size_element);
	}
}
