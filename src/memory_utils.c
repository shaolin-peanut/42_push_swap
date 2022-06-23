#include "push_swap.h"

t_meta	*init_pkg(t_meta *pkg)
{
	pkg = (t_meta *)malloc(sizeof(t_meta) * 1);
	if (!pkg)
		errormsg("pkg malloc error!\n", pkg);
	pkg->list_a_head = 0;
	pkg->list_a_butt = 0;
	pkg->a_size = 0;
	pkg->list_b_head = 0;
	pkg->list_b_butt = 0;
	pkg->b_size = 0;
	return (pkg);
}

void	errormsg(char *msg, t_meta	*pkg)
{
	int	i;

	i = -1;
	while (msg[++i])
		write(2, &msg[i], 1);
	free_all(pkg);
	exit(EXIT_FAILURE);			
}

void	free_all(t_meta	*pkg)
{
	printf("Size of a: %d\n", pkg->a_size);
	printf("Size of b: %d\n", pkg->b_size);
	printf("pkg->list_a_butt: %p\n", pkg->list_a_butt);
	printf("pkg->list_b_butt: %p\n", pkg->list_b_butt);
	if (pkg->list_a_head != 0)
		free_list('a', pkg->list_a_head);
	if (pkg->list_b_head != 0)
		free_list('b', pkg->list_b_head);
	// The free list function should take care of the list butts, in theory. Maybe have to be freed, or at least set to NUll?
	free(pkg);
}

void	free_list(char	id, t_list *list)
{
	t_list	*current_node;

	current_node = NULL;
	while(list != NULL)
	{
		printf("%c:%p:num %d->prev:%p\n", ft_toupper(id), list, list->num, list->previous);
		current_node = list;
		list = list->next;
		free(current_node);
	}
}
