#include <stdio.h>
#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: character
 * Return: length of @s
 */
int strlen(char *s)
{
	int number;

	for (number = 0; *s != '\0'; s++)
		number++;
	return (number);
}
