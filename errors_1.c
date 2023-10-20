#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * usage_error - Display a usage error message and exit with failure.
 *
 * This function is responsible for providing a clear error message to the
 * user when a command-line utility is used incorrectly. It assists users in
 * understanding the correct usage of the program and always exits with the
 * status code (EXIT_FAILURE) to indicate an error.
 *
 * Return:
 *     - (EXIT_FAILURE) Always, indicating an incorrect program usage.
 */

int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints an error message related to memory allocation.
 *
 * Description:
 * This function is responsible for displaying an error message when a
 * memory allocation operation, typically done using malloc, fails. It
 * informs the user about the failure, helping in diagnosing and handling
 * memory-related issues in the program.
 *
 * Return:
 * The function always returns (EXIT_FAILURE) to indicate that a memory
 * allocation error has occurred.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Reports a failed attempt to open a file.
 *
 * This function gracefully handles file opening errors and prints an
 * informative message, including the filename that could not be opened.
 *
 * @filename: The name of the file that failed to open.
 *
 * Return: Always returns EXIT_FAILURE to indicate an error.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Handles unknown instruction errors and provides a
 *                  descriptive error message, including the opcode and
 *                  the line number in the Monty bytecode file where the
 *                  error occurred.
 *
 * This function is essential for debugging and enhancing the usability
 * of your Monty interpreter, as it ensures clear error reporting.
 *
 * @opcode: The unknown opcode that caused the error.
 * @line_number: The line number in the Monty bytecode file where the
 *               error occurred.
 *
 * Return: Always returns EXIT_FAILURE to indicate an error condition.
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Outputs an error message for an invalid
 * argument in monty_push.
 * @line_number: The line number in the Monty bytecode
 * file where the error occurred.
 *
 * This function is responsible for generating an error message when an invalid
 * argument is encountered during the execution of the monty_push function. It
 * indicates the line number where the error occurred.
 *
 * @line_number: Line number where the error was encountered.
 *
 * Return: This function always returns EXIT_FAILURE to indicate the error.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
