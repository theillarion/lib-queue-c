#ifndef QUEUE_H
# define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

typedef	struct s_node
{
	void			*element;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	size_t	size_element;
	t_node	*head;
}	t_queue;


/*
	Before using a library function, you must initialize the structure with the function ft_init.
	Also, to prevent memory leaks, you should use the function to destroy the structure - ft_deinit.
*/

//		init.c
//		NOTE: size_element - object size in bytes
void	ft_init(t_queue	**queue, size_t size_element);

//		deinit.c
void	ft_deinit(t_queue	**queue);

//		push.c
void	ft_push(t_queue	**queue, void	*element);

//		pop.c
void	ft_pop(t_queue	**queue);

//		top.c
void	*ft_top(const t_queue	**queue);

//		empty.c
bool	ft_empty(const t_queue	**queue);

#endif