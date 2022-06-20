#include "push_swap.h"

// TODOS
// - Return 1 on success, -1 on failure
// - convert argument[i] to string with atoi, if atoi fails, return -1
// - check if size is over int min and under int max
// - check if there's another identical already in the list, if so return -1
t_list	*init_list()
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(t_list *) * 1);
	if (list == NULL)
		errormsg("Malloc error\n");
	return (list);
}

t_meta	*init_pkg(t_meta	*pkg)
{
	pkg = (t_meta *)malloc(sizeof(t_meta *) * 1);
	pkg->list_a_head = NULL;
	pkg->list_a_head = init_list();
	pkg->list_a_butt = NULL;
	pkg->list_b_head = NULL;
	pkg->list_b_head = init_list();
	pkg->list_b_butt = NULL;
	return (pkg);
}

void	errormsg(char	*msg)
{
	int	i;

	i = -1;
	while (msg[i++])
		write(2, &msg[i], 1);
	exit(EXIT_FAILURE);
}

int	check_repetitions(char	*num, t_meta	*meta)
{
	int	i;
	t_list	*tmp;

	i = -1;
	tmp = meta->list_a_head;
	(void) tmp;
	(void) num;

	return (i);
}

int	check_and_place(char	**argv)
{
	int	i;
	t_meta	*pkg;

	i = 0;
	pkg = 0;
	pkg = init_pkg(pkg);
	while (argv[i++])
	{
		if (ft_atoi(argv[i]) == 0 || ft_strncmp(argv[i], "0", 2) != 0)
			errormsg("Error!\n");
		if (check_repetitions(argv[i], pkg) != 0)
			errormsg("Error!\n");
		/*else
			push(pkg, 0);*/
	}
	return (1);
}

// push(argv[i], 1);
