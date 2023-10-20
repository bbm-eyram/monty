#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - Tokenize a string into an array of words using delimiters
 *
 * This function takes a string and splits it into individual words based on
 * the specified delimiters. It allocates memory for an array of pointers, each
 * pointing to a separate word extracted from the input string. The resulting
 * 2D array can be used to manipulate and analyze the individual words.
 *
 * @str: The string to be tokenized into words.
 * @delims: The delimiters used to separate words within the input string.
 *
 * Return: A 2D array of pointers, each pointing to a distinct word extracted
 * from the input string. The caller is responsible for freeing the allocated
 * memory when it is no longer needed. If memory allocation fails, or if the
 * input string is empty, NULL is returned.
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * is_delim - Checks if the given character is a delimiter in
 * the provided array.
 *
 * @ch: The character to check for delimiting.
 * @delims: Pointer to a null-terminated array of delimiter characters.
 *
 * Return:
 * - 1 if the character is a delimiter (success).
 * - 0 if the character is not a delimiter (failure).
 */

int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - Determine the length of the current word in a string
 *
 * This function calculates the length of the word that begins at the current
 * position in the input string 'str',
 * using the specified delimiters in 'delims'.
 *
 * @str:    The input string from which to extract the word length.
 * @delims: A string containing delimiters to identify word boundaries.
 *
 * Return:  The length of the current word in the input string.
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * get_word_count - Determines the word count of the string
 * using custom delimiters
 *
 * @str: The text in which to count words.
 * @delims: The characters that define word boundaries.
 *
 * Return: The count of words in the input text.
 */
int get_word_count(char *str, char *delims)
int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_next_word - Extracts the next word from a given string
 *
 * This function parses a string and retrieves the next word, which is
 * delimited by the provided delimiters.
 *
 * @str: The string to extract the next word from
 * @delims: A set of delimiters used for word separation
 *
 * Return: A pointer to the first character of the next word
 */

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
