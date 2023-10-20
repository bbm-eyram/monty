#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - Combines the foremost two elements of a stack_t linked list.
 * @stack: Pointer to the uppermost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode script.
 *
 * Overview: This function adds the first two elements on the stack and
 * stores the result in the second element, while discarding the top element.
 */

void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - Computes the difference between the top two elements
 *             of a stack_t linked list and updates the list.
 *
 * @stack: A pointer to the top element of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Description: This function calculates the result of subtracting
 * the top element from the second element on the stack. The result
 * is stored in the second element, and the top element is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - Execute division on the second and top elements of a stack.
 * @stack: Pointer to the top node of a stack linked list.
 * @line_number: Line number in the Monty bytecode file.
 *
 * Description: Divides the second value by the top, stores the result in
 *              the second node, and removes the top value.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - Calculates and stores the product of the top two
 *                       values in a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 *
 * Description: This function multiplies the top two values, stores the result
 * in the second value from the top, and removes the top value.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - Calculates the remainder when the second value from the
 *                 top of a stack_t linked list is divided by the top value.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Description: This function computes the modulus and stores it in the second
 *              value from the top, removing the top value from the stack.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
