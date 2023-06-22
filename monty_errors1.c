#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _push(stack_t **doubly, unsigned int line)
{
	int m, i;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", line);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (i = 0; vglo.arg[i] != '\0'; i++)
	{
		if (!isdigit(vglo.arg[i]) && vglo.arg[i] != '-')
		{
			dprintf(2, "L%u: ", line);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	m = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, m);
	else
		add_dnodeint_end(doubly, m);
}

/**
 * _pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @line: line numbers
 * Return: no return
 */
void _pall(stack_t **doubly, unsigned int line)
{
	stack_t *aux;
	(void)line;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->m);
		aux = aux->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @line: line number
 * Return: no return
 */
void _pint(stack_t **doubly, unsigned int line)
{
	(void)line;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", line);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->m);
}

/**
 * _pop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @line: line number
 * Return: no return
 */
void _pop(stack_t **doubly, unsigned int line)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * _swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @line: line number
 * Return: no return
 */
void _swap(stack_t **doubly, unsigned int line)
{
	int k = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
