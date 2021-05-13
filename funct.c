#include "monty.h"

/**
 * swap - swap function
 * @stack: head node
 * @num_linea: num line
 * Return: No
 */
void swap(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;

	if (*stack && (*stack)->next)
	{
		ey = (*stack)->next;
		if (ey == NULL)
		{
			exit(0);
		}
		(*stack)->next = ey->next;
		(*stack)->prev = ey;
		ey->next = *stack;
		ey->prev = NULL;
		*stack = ey;
	}
	else
	{
		dprintf(2, "L%u: can't swap, stack too short\n", num_linea);
		free(supp.linea);
		fclose(supp.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * add - add function
 * @stack: head
 * @num_linea: num line
 * Return: No
 */
void add(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;
	stack_t *ey2;
	int suma = 0;

	if (*stack && (*stack)->next)
	{
		ey2 = (*stack)->next;
		suma = (*stack)->n + ey2->n;
		ey = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ey);
		(*stack)->n = suma;
	}
	else
	{
		dprintf(2, "L%d: can't add, stack too short\n", num_linea);
		free(supp.linea);
		fclose(supp.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * pint - pint function
 * @stack: head
 * @num_linea: num line
 * Return: No
 */
void pint(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;

	ey = *stack;
	if (ey == NULL)
	{
		free(supp.linea);
		fclose(supp.fil);
		free_l(stack);
		dprintf(2, "L%u: can't pint, stack empty\n", num_linea);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", ey->n);
}


/**
 * pall - pall function
 * @stack: head
 * @num_linea: num line
 * Return: No
 */
void pall(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;

	ey = *stack;
	if (num_linea)
		while (ey)
		{
			printf("%d\n", ey->n);
			ey = ey->next;
		}
}


/**
 * push - push function
 * @stack: head
 * @num_linea: num line
 * Return: 0
 */
void push(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;

	chek2(stack, num_linea);
	if (supp.token)
	{
		ey = malloc(sizeof(stack_t));
		if (ey == NULL)
		{
			fputs("Error: malloc failed\n", stderr);
			exit(EXIT_FAILURE);
		}
		ey->n = supp.numero, ey->next = NULL;
		ey->prev = NULL;
		if (*stack)
		{
			if (supp.flag == 1)
			{
				ey->next = *stack;
				(*stack)->prev = ey;
				*stack = ey;
			}
			else
			{
				while ((*stack)->next)
					*stack = (*stack)->next;
				(*stack)->next = ey, ey->prev = *stack;
				while ((*stack)->prev)
					*stack = (*stack)->prev;
			}
		}
		else
			*stack = ey;
	}
	else
	{
		free(supp.linea), fclose(supp.fil);
		dprintf(2, "L%u: usage: push integer\n", num_linea);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}
