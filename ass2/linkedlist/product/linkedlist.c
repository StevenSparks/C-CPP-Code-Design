/* SD exercise 1: simple linked list API */
/* Author : R. Frenken                   */
/* Version : 1.0			 */
#include "linkedlist.h"
#include <stdlib.h>

/***************************************************/
/* If *list == NULL, a new list should be created, */
/* otherwise prepend a new ITEM with value value   */
/* to the existing list                            */
/* Returns -1 if not enough memory, otherwise 0    */
/***************************************************/

int add_first(ITEM **list, int value)
{
	ITEM *new_item = malloc(sizeof(ITEM));
	if (new_item == NULL)
	{
		return -1;
	}

	new_item->value = value;
	new_item->next = NULL;

	if (*list == NULL)
	{
		*list = new_item;
	}
	else
	{
		new_item->next = *list;
		*list = new_item;
	}
	return 0;
}

/***************************************************/
/* If *list == NULL, a new list should be created, */
/* otherwise append a new ITEM with value value to */
/* the existing list                               */
/* Returns -1 if not enough memory, otherwise 0    */
/***************************************************/

int add_last(ITEM **list, int value)
{
	ITEM *new_item = malloc(sizeof(ITEM));
	if (new_item == NULL)
	{
		return -1;
	}

	new_item->value = value;
	new_item->next = NULL;

	if (*list == NULL)
	{
		*list = new_item;
	}
	else
	{
		ITEM * current = *list;
		while (current->next != NULL)
		{	
			current = current->next;
		}
		current->next = new_item;
	}

	return 0;
}

/****************************************************/
/* Insert a new item after current item c_item      */
/* Returns -1 if not enough memory, c_item == NULL, */
/* *list == NULL or c_item not found, otherwise 0   */
/****************************************************/
//list goes unused because the c_item param implies you already have a valid pointer from the list. 
int add_after(ITEM *list, ITEM *c_item, int value)
{
	if(list == NULL || c_item == NULL)
	{
		return -1;
	}

	ITEM * current = list;

	//OR statement in loop forced it to move until end of loop
	while(current != NULL)
	{	
		if(current == c_item)
		{
			ITEM *new_item = malloc(sizeof(ITEM));
			new_item->value = value;
	
			ITEM *temp = current->next;
			current->next = new_item;
			new_item->next = temp;
			return 0;
		}
		current = current->next;
	}

	return -2;
}

/***************************************************/
/* Remove first item of the list                   */
/* Returns -1 if list==NULL, otherwise 0           */
/***************************************************/

int rem_first(ITEM **list)
{
	if (*list == NULL)
	{
		return -1;
	}

	ITEM *current = *list;
	if (current->next != NULL)
	{
		*list = current->next;
	}

	free(current);

	return 0;
}

/***************************************************/
/* Remove last item of the list                    */
/* Returns -1 if list==NULL, otherwise 0           */
/***************************************************/

int rem_last(ITEM **list)
{
	if (*list == NULL)
	{
		return -1;
	}

	ITEM *current = *list;
	while (current->next != NULL)
	{
		current = current->next;
	}

	free(current);

	return 0;
}

/***************************************************/
/* Remove item after c_item of the list            */
/* Returns -1 list==NULL, c_item not found or      */
/* c_item is the last_element                      */
/***************************************************/

int rem_after(ITEM *list, ITEM *c_item)
{
	if(list == NULL || c_item == NULL)
	{
		return -1;
	}

	ITEM *current = list;
	while (current != NULL)
	{
		if (current == c_item)
		{
			if(current->next == NULL) {return -1;}

			ITEM *rem = current->next;
			current->next = rem->next;

			free(rem);
			rem = NULL;
			break;
		}
		current = current->next;
	}

	return 0;
}

/*********************************************************/
/* All dynamic memory allocated to the list is freed     */
/* Empty list should point to NULL                       */
/*********************************************************/

int clean(ITEM **list)
{
	if (list == NULL)
	{
		return -1;
	}

	ITEM *current = *list;
	while (current != NULL)
	{
		ITEM *previous = current;

		current = current->next;
		free(previous);
	}

	return 1;
}
