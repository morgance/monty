#include "monty.h"

/**
 *add_dnodeint_end - add a note at the end of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *delim, *aux;

	if (head == NULL)
		return (NULL);
	delim = malloc(sizeof(stack_t));
	if (!delim)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	delim->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		delim->next = *head;
		delim->prev = NULL;
		*head = delim;
		return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	delim->next = aux->next;
	delim->prev = aux;
	aux->next = delim;
	return (aux->next);
}

/**
 *add_dnodeint - add a note at the begining of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *delim;

	if (head == NULL)
		return (NULL);
	delim = malloc(sizeof(stack_t));
	if (!delim)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	delim->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		delim->next = *head;
		delim->prev = NULL;
		*head = delim;
		return (*head);
	}
	(*head)->prev = delim;
	delim->next = (*head);
	delim->prev = NULL;
	*head = delim;
	return (*head);
}

/**
 * free_dlistint - frees the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_dlistint(stack_t *head)
{
	stack_t *delim;

	while ((delim = head) != NULL)
	{
		head = head->next;
		free(delim);
	}
}
