#include "pushSwap.h"

//setGroupRange function
//This function divides the list into the given groups set out depending on how many arguments. In the main sorting
//function if the list is less than 101 the list will be broken down into 5 groups. This function defines those
//group sizes. The function uses 3 values to set a min and max group range. They are the number the list will be
// divided by(either 5 or 11), and two values from the info struct, being the original size of the list and ...
// the current size of the list as number as being pushed over to be, naturally the length of the list will decreas
//if we assume that the list is 50 in len, this function will break the list into groups of 10. As the size of 
//the list decreases, the group size will not change until it finishes its first 10. 0-10, 10-20, 20-30, 30-40, 
// 40-50. These numbers represent the indexs given to each value upon loading into the list. not to be confused
//with the values themselves. e.g. if the list was only numbers up to 50, number 50 would have the index of 49
//(because zero based) however its not the actual number itself. As this function is within the while loop, 
//of the large sort function, it will call upon every iteration as it changes from node to node. 

void	setGroupRange(t_data *info, int divideBy)
{
	int	i = -1;
	int	size = info->listLen;
	int	currSize = info->aLen;
	while(++i < divideBy)
	{
		if(currSize / (size / divideBy) >= i 
			&& currSize / (size / divideBy) < i + 1)
		{
			info->maxRange = size - (i * (size / divideBy));
			info->minRange = info->max - (size / divideBy);
		}
	}
}

void	largeSort(s_tack **listA, s_tack **listB, t_data *info, int divideBy)
{
	s_tack	*current;
	int i = 0;
	while(*listA != NULL)
	{
		current = *listA;
		setGroupRange(info, divideBy);
		while(current)
		{
			if(current->index >= info->minRange && current->index <= info->maxRange
					&& !info->holdFront)
				info->holdFront = i;
			if(current->index >= info->minRange && current->index <= info->maxRange)
				info->holdBack = i;
			i++;
			current = current->next;
		}
		rotateA(listA, listB, info)
	}
	beginRotation(listB, listA, info, 'A');
}

void	sortB(s_tack **listB, s_tack **listA, t_data *info)
{
	while(*listB)
	{
		s_tack *current;
		current = *listB;
		int	i = 0;
		int highVal = current->value
		while(current)
		{
			if(current->value > highVal)
				highVal = current->value;
				info->highValIdx = i;
			i++;
		}
		beginRotation(listB, listA, info, 'B');
	}
}

void	beginRotation(s_tack **src, s_tack **dst, t_data *info, char list)
{
	if(list = 'A')
	{	
		int	movesFrmBk = (info->holdBack - info->aLen) * -1;
		int movesFrmFt = info->holdFront;
	}
	if(list = 'B')
	{
		int	movesFrmBk = (info->highValPos - bLen) * -1;
		int	movesFrmFt = info->highValPos;
	}

	if (movesFrmBk < movesFrmFt)
	{
		while(movesFrmBk > 0)
		{
			revRotate(src, list);
			movesFrmBk--;
		}
	}
	else if(movesFrmFt < movesFrmBk)
	{
		while(movesFrmFront > 0)
		{
			rotate(src, list)
			movesFrmFrnt--;
		}		
	}
	if(movesFrmFt == 0 || movesFrmBk == 0)
		push(src, dst, list);
}
