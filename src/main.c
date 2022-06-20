#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        return (0);
    }
    else if (error_check(argv))
    {
        write(2, "Error\n", 7);
    }
    return (0);
}
