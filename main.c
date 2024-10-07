#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack = create_stack();
    push(stack, 2);
    push(stack, 4);
    pop(stack);
    printf("%i\n", peek(stack)->data);
    return (0);
}