#include "shell.h"
/**
 * str_len - returns the length of a string
 * @s: character
 * Return: length of @s
 */
int str_len(const char *s)
{
	int number;

	for (number = 0; *s != '\0'; s++)
		number++;

	return (number);
}
