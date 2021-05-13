#include "monty.h"

/**
 * err - err function
 * @stack: header
 * @x: int
 * Return: No
 */
void err(stack_t **stack, unsigned int x)
{
	dprintf(2, "L%u: unknown instruction %s\n", x, supp.linea);
	free(supp.linea);
	fclose(supp.fil);
	free_l(stack);
	if (stack)
	{
	}
	exit(EXIT_FAILURE);
}

/**
 * chek2 - chek2 check2
 * @stack: header
 * @cont: int
 * Return: No
 */
void chek2(stack_t **stack, unsigned int cont)
{
	if (chek(supp.token) == 0)
		supp.numero = atoi(supp.token);
	else
	{
		dprintf(2, "L%u: usage: push integer\n", cont);
		free_l(stack);
		free(supp.linea);
		fclose(supp.fil);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mul - _mul function
 * @stack: header
 * @num_linea: int
 * Return: No
 */

void _mul(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;
	stack_t *ey2;
	int mul = 0;

	if (*stack && (*stack)->next)
	{
		ey2 = (*stack)->next;
		mul = ey2->n * (*stack)->n;
		ey = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ey);
		(*stack)->n = mul;
	}
	else
	{
		dprintf(2, "L%u: can't mul, stack too short\n", num_linea);
		free(supp.linea);
		fclose(supp.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * _mod - _mod function
 * @stack: header
 * @num_linea: int
 * Return: No
 */

void _mod(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;
	stack_t *ey2;
	int mul = 0;

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
		mul = ey2->n % (*stack)->n;
		ey = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ey);
		(*stack)->n = mul;
	}
	else
	{
		dprintf(2, "L%d: can't mod, stack too short\n", num_linea);
		free(supp.linea);
		fclose(supp.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * pchar - pchar function
 * @stack: header
 * @num_linea: int
 * Return: No
 */

void pchar(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;

	ey = *stack;
	if (ey == NULL)
	{
		free(supp.linea);
		fclose(supp.fil);
		free_l(stack);
		dprintf(2, "L%u: can't pchar, stack empty\n", num_linea);
		exit(EXIT_FAILURE);
	}
	if (ey->n >= 128 || ey->n < 0)
	{
		free(supp.linea);
		fclose(supp.fil);
		free_l(stack);
		dprintf(2, "L%d: can't pchar, value out of range\n", num_linea);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ey->n);
}
