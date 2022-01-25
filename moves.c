#include "pushSwap.h"

//Swap Function
//This function just performs a standard swap, instead of moving the actual nodes just swapping their values.

void	swap(s_tack **list, char listName)
{
	int	nb = 0;
	if (*list != NULL && (*list)->next != NULL)
	{
		nb = (*list)->value;
		(*list)->value = (*list)->next->value;
		(*list)->next->value = nb;
	}
	if (listName == 'A')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	return ;
}

//Rotate function
//Makes temp variable point to head node of list.
//*List pointer then points to second node(making second node the new head);
//Temp(pointing at the original head) has its next set to NULL(essentially removing it from the list);
//Current now points to new head of list(previously the second node);
//while loop iterates through the list until it reaches the tail;
//Current(at this point the tail node) has its next field set to temp which was previously the head;
//The first node(head) is now attached at the bottom (becoming the new tail) and list has been rotated;

void	rotate(s_tack **list, char listName)
{
	s_tack	*current;
	s_tack	*temp;

	temp = *list;
	if(temp != NULL && temp->next != NULL)
	{
		*list = (*list)->next;
		temp->next = NULL;
		current = *list;
		while(current->next != NULL)
			current = current->next;
		current->next = temp;
	}
	if(listName == 'A')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
	return ;
}

//RevRotate Function
//Sets current pointer to point to head node of list(*list);
//While current next isnt NULL(iterating through list)
//Every iteration makes temp equal to current and current equal to the node following until list is finished;
//When current pointer reaches the tail(loop breaks) and the tail(current) has its next field set to *list...
//...*list pointing at the head, so now the tail(current) is at the top, with its next set to the prev head;
//temp(which was pointing at the second to last node, now has its next field set to NULL(making it the new tail);
//*list pointer now points to current(the new head);

void	revRotate(s_tack **list, char listName)
{
	s_tack	*current;
	s_tack	*temp;

	current = *list;
	if(*list != NULL && (*list)->next != NULL)
	{
		while(current->next != NULL)
		{
			temp = current;
			current = current->next;
		}
		current->next = *list;
		temp->next = NULL;
		*list = current;
	}
	if(listName == 'A')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
	return ;
}

//Push Function
//Sets temp pointer to point at head of source list;
//Sets Src pointer from head node to second node in the list;
//temp(pointing at head now) now has its next field set to the destination list.
//dst pointer now points at temp(previously head node of source list) making it new head of dst list;

void	push(s_tack **src, s_tack **dst, t_data *info , char listName)
{
	s_tack	*temp;
	
	temp = *src
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
	if(listName == 'A')
	{
		write(1, "pa\n", 1);
		info->aLen++;
		info->bLen--;
	}
	else
	{
		write(1, "pb\n", 1);
		info->aLen--;
		info->bLen++;
	}
	return ;
}
