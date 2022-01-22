#include "pushSwap.h"

void	initData(s_tack *listA, t_data *info, char **av)
{
	int	i = 1;
	*listA = (s_tack *)malloc(sizeof(s_tack));
	if(!listA)
		return (NULL);
	(*listA)->value = ft_atoi(av[i]);
	(*listA)->pos = 0;
	(*listA)->index = 0;
	(*listA)->next = NULL;
	info->listLen = 1;
	while(av[++i])
	{
		addNode(listA, ft_atoi(av[i], i - 1);
		info->listLen++;
	}
	setValIdx(listA);
}

void	newNode(s_tack	**listA, int value, int pos);
{
	s_tack	*curr;
	s_tack	*newNode;

	newNode = (s_tack *)malloc(sizeof(s_tack));
	if (!newNode)
		return (NULL);
	newNode->value = value;
	newNode->pos = pos;
	newNode->index = 0;
	newNode->next = NULL;
	curr = listA;
	while(curr->next)
		curr = curr->next;
	curr->next = newNode;
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

void	setValIdx(s_tack **listA)
{
	s_tack	*curr;
	s_tack 	*next;
	
	if(!(*listA))
		return (NULL);
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
		next = *list;
	}
}
