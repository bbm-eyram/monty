#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Swirls the front element of a stack to the back.
 * @stack: Pointer to the stack_t linked list's leading node.
 * @line_number: Current line in a Monty bytecode script.
 */

void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_rotr - Elevates the lowermost item of a stack_t
 * linked list to the zenith.
 * @stack: A reference to the paramount node in a stack_t linked list.
 * @line_number: The ongoing line number in a Monty bytecode manuscript.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_stack - Transforms a queue into a stack, a feat of Monty magic.
 *
 * @stack: Pointer to the foremost node of a stack_t linked list.
 * @line_number: The line where Monty bytecodes weave their enchantment.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Transforms a stack into a queue.
 *
 * @stack: Pointer to the top element of a stack_t linked list.
 * @line_number: The current line in a Monty bytecode file.
 *
 * This function takes the stack and makes it behave like a queue.
 * It shifts the order of elements to process them in a FIFO manner.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
