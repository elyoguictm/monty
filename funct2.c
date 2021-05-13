#include "monty.h"

/**
 * chek - check
 * @numero: number
 * Return: 0
 */
int chek(char *numero)
{
	int ey = 0;

	if (!numero)
		return (1);

	if (numero[ey] == 45)
		ey++;
	while (numero[ey])
	{
		if (numero[ey] < 48 || numero[ey] > 57)
			return (-1);
		ey++;
	}
	return (0);
}

/**
 * nop - nop
 * @stack: node head
 * @num_linea: num line
 * Return: No
 */
void nop(stack_t **stack, unsigned int num_linea)
{
	if (*stack)
	{};
	if (num_linea)
	{};
}

/**
 * sub - sub
 * @stack: node head
 * @num_linea: num line
 * Return: No
 */
void sub(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;
	stack_t *ey2;
	int resta = 0;

	if (*stack && (*stack)->next)
	{
		ey2 = (*stack)->next;
		resta = ey2->n - (*stack)->n;
		ey = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ey);
		(*stack)->n = resta;
	}
	else
	{
		dprintf(2, "L%u: can't sub, stack too short\n", num_linea);
		free(supp.linea);
		fclose(supp.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * divi - divi
 * @stack: node head
 * @num_linea: num line
 * Return: No
 */
void divi(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;
	stack_t *ey2;
	int div = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			dprintf(2, "L%u: division by zero\n", num_linea);
			free(supp.linea);
			fclose(supp.fil);
			free_l(stack);
			exit(EXIT_FAILURE);
		}
		ey2 = (*stack)->next;
		div = ey2->n / (*stack)->n;
		ey = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ey);
		(*stack)->n = div;
	}
	else
	{
		dprintf(2, "L%u: can't div, stack too short\n", num_linea);
		free(supp.linea);
		fclose(supp.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * free_l - free
 * @stack: node head
 * Return: No
 */
void free_l(stack_t **stack)
{
	stack_t *cleaner = *stack;

	while (*stack)
	{
		cleaner = cleaner->next;
		free(*stack);
		*stack = cleaner;
	}
}
