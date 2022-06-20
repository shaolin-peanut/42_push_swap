# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_list	t_list;
typedef struct s_meta	t_meta;

struct s_list
{
	int	num;
	t_list	*previous;
	t_list	*next;
};

struct s_meta
{
	t_list	*list_a_head;
	t_list	*list_a_butt;
	t_list	*list_b_head;
	t_list	*list_b_butt;
};

int check_and_place(char    **argv);
void	errormsg(char	*msg);
