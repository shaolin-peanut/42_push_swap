#include "push_swap.h"

int	ra(t_meta	*pkg)
{
	t_list	*head;

	if (pkg->a_size < 2)
		return (0);
	head = save_and_cut_head('a', pkg);
	update_list_butt(pkg);
	pkg->list_a_butt->next = head;
	head->previous = pkg->list_a_butt;
	pkg->list_a_butt = head;
	printf("ra\n");
	return (0);
}

int	rb(t_meta	*pkg)
{
	t_list	*head;

	if (pkg->b_size < 2)
		return (0);
	head = save_and_cut_head('b', pkg);
	update_list_butt(pkg);
	pkg->list_b_butt->next = head;
	head->previous = pkg->list_b_butt;
	pkg->list_b_butt = head;
	printf("rb\n");
	return (0);
}

int	rra(t_meta	*pkg)
{
	t_list	*butt;

	if (pkg->a_size < 2)
		return (0);
	// cut from butt
	update_list_butt(pkg);
	butt = pkg->list_a_butt;
	if (pkg->list_a_butt->previous != NULL)
		pkg->list_a_butt = pkg->list_a_butt->previous;
	pkg->list_a_butt->next = NULL;
	butt->previous = NULL;
	// link to top
	butt->next = pkg->list_a_head;
	pkg->list_a_head->previous = butt;
	pkg->list_a_head = butt;
	update_list_butt(pkg);
	return (0);
}

int	rrb(t_meta	*pkg)
{
	t_list	*butt;

	if (pkg->b_size < 2)
		return (0);
	update_list_butt(pkg);
	butt = pkg->list_b_butt;
	if (pkg->list_b_butt->previous != NULL)
		pkg->list_b_butt = pkg->list_b_butt->previous;
	pkg->list_b_butt->next = NULL;
	butt->previous = NULL;
	// link to top
	butt->next = pkg->list_b_head;
	pkg->list_b_head->previous = butt;
	pkg->list_b_head = butt;
	update_list_butt(pkg);
	printf("rrb\n");
	return (0);
}

int	rr(char	sign, t_meta	*pkg)
{
	if (sign == 0)
	{
		ra(pkg);
		rb(pkg);
	}
	else if (sign == -1)
	{
		rra(pkg);
		rrb(pkg);
	}
	else
		return (-1);
	return (0);
}
