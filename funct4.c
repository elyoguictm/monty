#include "monty.h"

/**
 * pstr - pstri function
 * @stack: head
 * @num_linea: num line
 * Return: No
 */
void pstr(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey;

	ey = *stack;
	if (num_linea)
		while (ey && ey->n != 0 && ey->n > 0 && ey->n < 128)
		{
			printf("%c", ey->n);
			ey = ey->next;
		}
	printf("\n");
}

/**
 * rotl - rotl function
 * @stack: head
 * @num_linea: num line
 * Return: No
 */

void rotl(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey, *ey2;

	if (*stack && (*stack)->next)
	{
		ey = *stack;
		ey2 = ey;
		*stack = ey->next;
		(*stack)->prev = NULL;
		if (num_linea)
			while (ey2->next)
			{
				ey2 = ey2->next;
			}
		ey2->next = ey;
		ey->prev = ey2;
		ey->next = NULL;
	}
}


/**
 * rotr - rotr function
 * @stack: head
 * @num_linea: num line
 * Return: No
 */

void rotr(stack_t **stack, unsigned int num_linea)
{
	stack_t *ey2;

	if (*stack && (*stack)->next)
	{
		ey2 = *stack;
		if (num_linea)
			while (ey2->next)
			{
				ey2 = ey2->next;
			}
		ey2->next = *stack;
		ey2->prev->next = NULL;
		ey2->prev = NULL;
		*stack = ey2;
	}
}

/**
 * queue - queue function
 * @stack: head
 * @num_linea: num line
 * Return: No
 */

void queue(stack_t **stack, unsigned int num_linea)
{
	if (stack || num_linea)
		supp.flag = 0;
}

/**
 * stack - stack function
 * @stack: head
 * @num_linea: num line
 * Return: No
 */

void stack(stack_t **stack, unsigned int num_linea)
{
	if (stack || num_linea)
		supp.flag = 1;
}
