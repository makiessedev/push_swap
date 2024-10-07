#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include <stdlib.h>

typedef struct  t_node
{
    int data; 
    struct t_node *next;
}   t_node;

typedef struct  t_stack
{
    t_node  *top;
    int size;
}   t_stack;

t_stack *create_stack(void);
t_node  *create_node(int data);
void    push(t_stack *stack, int data);
t_node  *pop(t_stack *stack);
t_node  *peek(t_stack *stack);

# endif