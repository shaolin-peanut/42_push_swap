#include "push_swap.h"

t_list	*init_list(t_meta	*pkg)
{
		t_list *list;

		list = (t_list *) malloc(sizeof(t_list) * 1);
		if (list == NULL)
			errormsg("Malloc error\n", pkg);
		list->num = 0;
		list->next = 0;
		list->previous = 0;
		return (list);	
}

t_list	*put(int	num, t_meta	*pkg)
{
	t_list	*new;

	new = init_list(pkg);
	new->num = num;
	//printf("new->num:%d\n", new->num);
	// if there's an existing node, link new to current top.
	if (pkg->list_a_head != NULL)
	{
		new->next = pkg->list_a_head;
		new->next->previous = new;
	}
	pkg->a_size++;	
	return (new);
}

void	update_list_butt(t_meta	*pkg)
{
	t_list	*node;

	// Find list A's end
	if (pkg->list_a_head != NULL)
	{
		node = pkg->list_a_head;
		while (node->next != NULL)
			node = node->next;
		pkg->list_a_butt = node;
	}
	// Find list B's end
	if (pkg->list_b_head != NULL)
	{
		node = pkg->list_b_head;
		while(node->next != NULL)
			node = node->next;
		pkg->list_b_butt = node;
	}
	node = NULL;
}

void	connect_ab(t_list	*a, t_list	*b)
{
	if (a == 0)
		b->next = NULL;
	else if (b == 0)
		a->next = NULL;
	else
	{
		a->next = b;
		b->previous = a;
	}
}

t_list *save_and_cut_head(char id, t_meta *pkg)
{
	t_list*				head;
	if (id == 'a')
	{
		head = pkg->list_a_head;
		pkg->list_a_head = pkg->list_a_head->next;
		pkg->list_a_head->previous = NULL;
		head->next = NULL;									
	}
	if (id == 'b')
	{
		head = pkg->list_b_head;
		pkg->list_b_head = pkg->list_b_head->next;
		if (pkg->list_b_head != NULL)
			pkg->list_b_head->previous = NULL;
		head->next = NULL;
	}
	return (head);					
}
