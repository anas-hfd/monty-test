#include "monty.h"

/**
  *my_rotr- rotates the stack to the bottom
  *@head: head
  *@counter: unused
  *Return: void
 */

void my_rotr(stack_t **head, unsigned int counter)
{
	stack_t *cp;

	(void) counter;

	cp = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	while (cp->next)
	{
		cp = cp->next;
	}
	cp->next = *head;
	cp->prev->next = NULL;
	cp->prev = NULL;
	(*head)->prev = cp;
	(*head) = cp;
}
