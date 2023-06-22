#include "monty.h"

/**
 * my_pchar - prints the char at the top of the stack
 * @head: head
 * @counter: elements
 * Return: void
*/

void my_pchar(stack_t **head, unsigned int counter)
{
	stack_t *ele;

	ele = *head;
	if (!ele)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (ele->n > 127 || ele->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ele->n);
}
