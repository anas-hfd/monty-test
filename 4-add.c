#include "monty.h"
/**
 * my_add - adds the top two elements of the stack.
 * @head: head
 * @counter: number of elements
 * Return: void
*/

void my_add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ele = *head;
	aux = ele->n + ele->next->n;
	ele->next->n = aux;
	*head = ele->next;
	free(ele);
}
