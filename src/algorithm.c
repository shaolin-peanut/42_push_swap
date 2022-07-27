#include "push_swap.h"

void	sort(t_meta	*pkg)
{
	if (pkg->a_size < 4)
		fast_sort(pkg);
	else
		split_in_groups(pkg);
}

void	split_in_groups(pkg)
{
	int	pivot;

	pivot = pkg->a_size / 
}
