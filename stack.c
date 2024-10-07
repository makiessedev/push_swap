#include "push_swap.h"

t_stack *create_stack(void)
{
    t_stack *stack;
    stack = malloc(sizeof(t_stack));
    stack->size = 0;
    stack->top = NULL;
    return (stack);
}

t_node  *create_node(int data)
{
    t_node *node;
    node = malloc(sizeof(t_node));
    node->data = data;
    return (node);
}

void    push(t_stack *stack, int data)
{
    if (stack == NULL)
        fprintf(stderr, "invalid stack");
    t_node  *node = create_node(data);

    node->next = stack->top;
    stack->top = node;
    stack->size = stack->size + 1;
}

t_node  *pop(t_stack *stack)
{
    if (stack->size == 0)
    {
            fprintf(stderr, "stack is empty");
            return (NULL);
    }
    t_node  *node;
    node = stack->top;
    stack->top = node->next;
    return (node);
}

t_node  *peek(t_stack *stack)
{
    return (stack->top);
}
