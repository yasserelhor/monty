#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
vars var;

/**
 * main - Entry point for the Monty interpreter.
 * @ac: Number of command-line arguments.
 * @av: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main(int ac, char **av)
{
	char *jo;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_vars(&var) != 0)
		return (EXIT_FAILURE);


	var.file = fopen(av[1], "r");

	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free_all();

		return (EXIT_FAILURE);
	}



	while (getline(&var.buff, &var.tmp, var.file) != EOF)
	{
		jo = strtok(var.buff, " \r\t\n");
		if (jo != NULL)
			if (call_funct(&var, jo) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}

		var.line_number++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
