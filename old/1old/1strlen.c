#include "shell.h"

/**
 * str_length - returns the length of a string
 * @s: pointer character
 * Return: length of @s
 */
int str_length(const char *s)
{
	int number;

	for (number = 0; *s != '\0'; s++)
		number++;

	return (number);
}
