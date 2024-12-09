/*
 * ________________________________________________________________________________
 * |  File: s_stack.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:59 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/libdanc.h"

t_stack *create_stack(int data)
{
	t_stack *new;
	new = safe_malloc(sizeof(t_stack), "Stack could not be created");
	int *data_ptr = safe_malloc(sizeof(int), "create_stack() malloc failed");
	*data_ptr = data;
	new->top = create_node(data_ptr);
	return (new);
}

void push(t_stack *stack, int data)
{
	int *data_ptr = safe_malloc(sizeof(int), "push() malloc failed");
	*data_ptr = data;
	insert_front(&stack->top, data_ptr);
}

int pop(t_stack *stack)
{
	if (stack->top == NULL)
		return 0;
	int data = *(int *)stack->top->data;
	delete_front(&(stack->top));
	return data;
}

void print_stack(t_stack *stack)
{
	print_nodes(stack->top);
}

