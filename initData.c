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
