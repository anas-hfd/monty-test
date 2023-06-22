#include "monty.h"

/**
 * my_swap - adds the top two elements
 * @head: head
 * @counter: numberof elemets
 * Return: void
*/

void my_swap(stack_t **head, unsigned int counter)
{
	stack_t *ele;
	int len = 0, aux;

	ele = *head;
	while (ele)
	{
		ele = ele->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ele = *head;
	aux = ele->n;
	ele->n = ele->next->n;
	ele->next->n = aux;
}
