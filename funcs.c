#include "monty.h"

/**
* free_stack - frees a doubly linked list
* @head: head of the stack
* Return: void
*/

void free_stack(stack_t *head)
{
	stack_t *hlp;

	hlp = head;
	while (head)
	{
		hlp = head->next;
		free(head);
		head = hlp;
	}
}

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *node, *hlp;

	hlp = *head;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (hlp)
		hlp->prev = node;
	node->n = n;
	node->next = *head;
	node->prev = NULL;
	*head = node;
}

/**
 * addqueue - add node to the tail stack
 * @n: value
 * @head: head
 * Return: void
*/

void addqueue(stack_t **head, int n)
{
	stack_t *node, *hlp;

	hlp = *head;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error\n");
	}
	node->n = n;
	node->next = NULL;
	if (hlp)
	{
		while (hlp->next)
			hlp = hlp->next;
	}
	if (!hlp)
	{
		*head = node;
		node->prev = NULL;
	}
	else
	{
		hlp->next = node;
		node->prev = hlp;
	}
}

/**
* execute - executes the opcode
* @stack: linked list - stack
* @counter: counter
* @file: ptr to monty file
* @content: content
* Return: int
*/

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", my_push}, {"pall", my_pall}, {"pint", my_pint},
				{"pop", my_pop},
				{"swap", my_swap},
				{"add", my_add},
				{"nop", my_nop},
				{"sub", my_sub},
				{"div", my_div},
				{"mul", my_mul},
				{"mod", my_mod},
				{"pchar", my_pchar},
				{"pstr", my_pstr},
				{"rotl", my_rotl},
				{"rotr", my_rotr},
				{"queue", my_queue},
				{"stack", my_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].my(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
