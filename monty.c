#include "monty.h"
g_t supp;

/**
 * sizze - size
 * @linea: line
 * Return: line
 */
int sizze(char *linea)
{
	unsigned int cont = 0;

	while (linea[cont])
	{
		cont++;
	}
	return (cont);
}


/**
 * nojum - remove line
 * @linea: line
 * Return: line
 */
char nojum(char *linea)
{
	int ta = sizze(linea);

	linea[ta - 1] = '\0';
	return (*linea);
}

/**
 * pop - delete first noce
 * @stack: head
 * @num_linea: num of line
 * Return: No
 */
void pop(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;

	ey = *stack;
	if (ey == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", num_linea);
		free(supp.linea);
		fclose(supp.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		*stack = ey->next;
		(*stack)->prev = NULL;
		free(ey);
	}
	else
		free_l(stack);
}

/**
 * func - pointers to functions
 * @tokens: arg
 * Return: No
 */

void (*func(char *tokens))(stack_t **stack, unsigned int num_linea)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{"err", err},
		{"#", nop},
		{NULL, NULL}
	};
	int i = 0;
	int o;

	while (i < 19)
	{
		o = strcmp(ops[i].opcode, tokens);
		if (o == 0)
			return (ops[i].f);
		i++;
	}

	return (ops[17].f);
}

/**
 * main - main function
 * @argc: num arg
 * @argv: arg
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	size_t numbytes = 0;
	int bytesleidos = 0;
	unsigned int cont = 1;

	supp.flag = 1;
	supp.linea = NULL;
	if (argc != 2)
	{
		fputs("USAGE: monty file\n", stderr);
		exit(EXIT_FAILURE);
	}
	supp.fil = fopen(argv[1], "r");
	if (supp.fil == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((bytesleidos = getline(&supp.linea, &numbytes, supp.fil)) != EOF)
	{
		nojum(supp.linea);
		if (supp.linea[0] != 35)
		{
			supp.token = strtok(supp.linea, " \t\n");
			supp.opco = supp.token;
			if (supp.opco != NULL)
			{
				supp.token = strtok(NULL, " \t\n");
				func(supp.opco)(&stack, cont);
			}
			cont++;
		}
	}
	free_l(&stack);
	free(supp.linea);
	fclose(supp.fil);
	return (0);
}
