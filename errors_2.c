#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - Dispenses wisdom on empty stacks.
 * @line_number: Line where this profound error was birthed.
 *
 * Emitting sage advice, this function reflects on emptiness,
 * urging you to fill your stacks with care. When the void
 * consumes your aspirations, it returns (EXIT_FAILURE) unfailingly.
 *
 * Return: (EXIT_FAILURE) invariably.
 */

int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Displays an error message when attempting to print an integer
 *              from an empty stack in Monty bytecodes.
 * @line_number: The line number in the Monty bytecodes file
 * where the error occurred.
 *
 * This function is responsible for handling errors related to the
 * 'pint' opcode.
 *
 * Return: Always returns EXIT_FAILURE to indicate a failure.
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Generates an error message for Monty math
 * operations when
 * the stack or queue contains fewer than two nodes.
 *
 * This function is responsible for printing an error message when an operation
 * in a Monty interpreter is attempted on a stack or queue that contains fewer
 * than two nodes, which is an invalid condition for certain operations.
 *
 * @line_number: The line number in the Monty bytecode
 * file where the error occurred.
 * @op: The operation that triggered the error.
 *
 * Return: Always returns EXIT_FAILURE to indicate an error condition.
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Handles division by zero errors in Monty bytecodes.
 * @line_number: Line number where the error occurred.
 *
 * This function is responsible for printing an informative error message
 * when a division by zero is attempted in a Monty bytecode file. It takes
 * the line number as input and prints the error message along with the line
 * number, highlighting the location of the error.
 *
 * Return: Always returns EXIT_FAILURE to indicate an error condition.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Signalizes a problem: empty stacks
 * or invalid character values.
 * @line_number: Line in Monty bytecode file where the issue arises.
 * @message: Custom error message to be displayed.
 *
 * This function displays error messages for situations involving
 * empty stacks or non-character values in a Monty bytecode file.
 *
 * Return: Always exits with code (EXIT_FAILURE) to indicate an error.
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
