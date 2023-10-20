#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - Deallocates memory used by a stack_t structure.
 *
 * This function releases the memory allocated for a stack_t structure.
 * It takes a pointer to the top (for stacks) or bottom (for queues) of
 * a stack_t and frees the associated memory, preventing memory leaks.
 *
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Sets up a stack_t with start and end nodes.
 * @stack: Pointer to an uninit. stack_t.
 *
 * Return: EXIT_FAILURE on error, else EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Analyzes the operational mode of a stack_t linked list.
 *
 * This function examines a given stack_t linked list to determine whether it
 * behaves as a stack or a queue. It assesses the order of elements and
 * provides a clear indication of the list's operational mode.
 *
 * @stack: A pointer to the head of the stack_t linked list to be analyzed.
 *
 * Return:
 *   - STACK (0) if the list operates as a stack.
 *   - QUEUE (1) if the list operates as a queue.
 *   - INDETERMINATE (2) if the behavior cannot be conclusively determined.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
