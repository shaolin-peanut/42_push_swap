#include "push_swap.h"

int	check_repetitions(int	num, t_meta	*pkg)
{
	int	i;
	t_list	*current_node;

	i = -1;
	current_node = pkg->list_a_head;
	while (current_node != NULL)
	{
		if (num == current_node->num)
			errormsg("Don't enter the same number twice!\n", pkg);
		current_node = current_node->next;
	}
	i = 1;
	return (i);
}

// Where all the cool stuff is coordinated
int	war_room(int c, char	**argv)
{
	int	i;
	int	tmp_num;
	t_meta	*pkg;

	i = c;
	pkg = NULL;
	pkg = init_pkg(pkg);
	tmp_num = 0;
	while (--i > 0)
	{
		// Don't forget to check min and max int
		if ((tmp_num = ft_atoi(argv[i])) == 0)
			errormsg("Error!\n", pkg);
		if (check_repetitions(tmp_num, pkg) == -1)
			errormsg("Error!\n", pkg);
		else
			pkg->list_a_head = put(tmp_num, pkg);
		//printf("tmp_num:%d\n", tmp_num);
	}
	qwhacksort(pkg);
	free_all(pkg);
	return (1);
}

