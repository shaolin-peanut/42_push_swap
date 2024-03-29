/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:30:25 by sbars             #+#    #+#             */
/*   Updated: 2022/08/17 16:33:35 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_list	t_list;
typedef struct s_meta	t_meta;

struct s_list
{
	int		num;
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

typedef struct s_radix
{
	int	max_bits;
	int	i;
	int	j;
	int	num;
	int	size;
}	t_radix;

// algorithm.c
void	sort(t_meta	*pkg);
void	push_min_to_b(t_meta	*pkg);
void	radix_sort(t_meta	*pkg);
// small_algorithms.c
void	sort_two(t_meta *pkg);
void	sort_three(t_meta	*pkg);
void	sort_small(t_meta *pkg);
void	split_in_groups(t_meta	*pkg);
int		choose_pivot(t_list	*list, int limit);
void	split_in_groups(t_meta	*pkg);
// processing.c
int		parsing_multi_args(int c, char **argv);
int		parsing_one_arg(int c, char **argv);
// list_utils.c
t_list	*init_list(t_meta	*pkg);
t_list	*put(int num, t_meta *pkg);
void	connect_ab(t_list	*a, t_list	*b);
void	update_list_butt(t_meta	*pkg);
t_list	*save_and_cut_head(char id, t_meta *pkg);
// memory_utils.c
t_meta	*init_pkg(t_meta *pkg);
void	errormsg(char *msg, t_meta *pkg);
void	free_list(t_list *list);
void	free_all(t_meta	*pkg);
// dev_utils.c
void	print_list(int id, t_meta *pkg);
// utils.c
int		is_sorted(t_list	*head);
int		list_min(t_list	*list, int limit);
int		list_max(t_list	*list, int limit);
// utils2.c
int		ft_isnumber(char	*str);
int		ft_tablen(char	**tab);
// descretize_stack.c
int		replace_by_tidy_num(t_meta	*pkg);
// operations.c
int		sa(t_meta	*pkg);
int		sb(t_meta	*pkg);
int		pa(t_meta	*pkg);
int		pb(t_meta	*pkg);
int		ra(t_meta	*pkg);
int		rb(t_meta	*pkg);
int		rra(t_meta	*pkg);
int		rrb(t_meta	*pkg);
int		rr(char sign, t_meta *pkg);
void	ss(t_meta	*pkg);
int		choose_pivot(t_list	*list, int limit);
// libft
int		count_digits(char	const *s2, char sep);

#endif
