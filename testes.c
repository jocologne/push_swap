#include "push_swap.h"

void print_stack(t_node *stack)
{
	printf("len = %d\n", stack_len(stack));
	while(stack)
	{
		printf("%d_%d\n", stack->position, stack->value);
		stack = stack->next;
	}
}