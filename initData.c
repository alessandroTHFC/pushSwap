#include "pushSwap.h"

static void	addNode(s_tack **listA, int value, int pos);
static void	setValIdx(s_tack **listA);

void	initList(s_tack **listA, t_data *info, char **av)
{
	int	i = 1;
	info->listLen= 0;
	while(av[i])
	{
		addNode(listA, atoi(av[i]), i);
		info->listLen++;
		i++;
	}
	setValIdx(listA);
}

static void	addNode(s_tack	**listA, int value, int pos)
{
	s_tack	*curr;
	s_tack	*newNode;
	newNode = (s_tack *)malloc(sizeof(s_tack));
	if (!newNode)
		return ;
	newNode->value = value;
	newNode->pos = pos;
	newNode->index = 1;
	newNode->next = NULL;
	curr = *listA;
	if(curr)
	{	
		while(curr->next)
			curr = curr->next;
		curr->next = newNode;
	}
	else
		*listA = newNode;
}

//setValIdx function
//this function gives each value an index number based on how high its value is.
//If the list had 50 values stored in it, the highest number of that list would have an index value of 49...
//..because index begins at zero.
//current pointer points to head node of the list
//next pointer points to the second node of the list.
//while current doesnt equal null, it enters the second loop. if current equals null then it makes current equal...
//...to the next value and sets next to the head so the it can start comparing current value to the numbers...
//...at the start of the list. 

static void	setValIdx(s_tack **listA)
{
	s_tack	*curr;
	s_tack 	*next;
	
	if(!(*listA))
		return ;
	curr = *listA;
	next = curr->next;
	while(curr)
	{
		while(next)
		{
			if(curr->value > next->value)
				curr->index++;
			next = next->next;
		}
		curr = curr->next;
		next = *listA;
	}
}	
