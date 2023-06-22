#include "monty.h"

/**
 * my_pstr - prints the string starting at the top of the stack
 * @head: head
 * @counter: unused
 * Return: void
*/

void my_pstr(stack_t **head, unsigned int counter)
{
	stack_t *ele;
	(void)counter;

	ele = *head;
	while (ele)
	{
		if (ele->n > 127 || ele->n <= 0)
		{
			break;
		}
		printf("%c", ele->n);
		ele = ele->next;
	}
	printf("\n");
}
