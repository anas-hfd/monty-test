#include "monty.h"

/**
 * my_mod - modulos successive elements
 * @head: head
 * @counter:elements
 * Return: void
*/

void my_mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ele = *head;
	if (ele->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = ele->next->n % ele->n;
	ele->next->n = aux;
	*head = ele->next;
	free(ele);
}
