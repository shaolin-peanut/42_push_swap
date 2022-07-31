# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_list	t_list;
typedef struct s_meta	t_meta;

struct s_list
{
	int	num;
	t_list	*next;
	t_list	*previous;
};

struct s_meta
{
	t_list	*list_a_head;
	t_list	*list_a_butt;
	int		a_size;
	t_list	*list_b_head;
	t_list	*list_b_butt;
	int		b_size;
};

// algorithm.c
void	sort(t_meta	*pkg);
// small_algorithms.c
void	fast_sort(t_meta	*pkg);
void	sort_six(t_meta	*pkg);
void	sort_two(t_meta *pkg);
void	sort_three_a(t_meta	*pkg, int one, int two, int three);
void	sort_three_b(t_meta	*pkg, int one, int two, int three);
void	split_in_groups(t_meta	*pkg);
// processing.c
int war_room(int	c, char    **argv);
// list_utils.c
t_list	*init_list();
t_list	*put(int	num, t_meta	*pkg);
void	connect_ab(t_list	*a, t_list	*b);
void	update_list_butt(t_meta	*pkg);
t_list	*save_and_cut_head(char	id, t_meta	*pkg);
// memory_utils.c
t_meta	*init_pkg(t_meta	*pkg);
void	errormsg(char	*msg, t_meta	*pkg);
void	free_list(char	id, t_list	*list);
void	free_all(t_meta	*pkg);
// dev_utils.c
void	print_list(int	id, t_meta	*pkg);
// utils.c
int		is_sorted(t_list	*head);
int		list_min(t_list	*list, int limit);
int		list_max(t_list	*list, int limit);
// operations.c
int	sa(t_meta	*pkg);
int	sb(t_meta	*pkg);
int	pa(t_meta	*pkg);
int	pb(t_meta	*pkg);
int	ra(t_meta	*pkg);
int	rb(t_meta	*pkg);
int	rra(t_meta	*pkg);
int	rrb(t_meta	*pkg);
int	rr(char	sign, t_meta	*pkg);
void	ss(t_meta	*pkg);
int		choose_pivot(t_list	*list, int limit);
