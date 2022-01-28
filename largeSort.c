#include "pushSwap.h"
static void	sortB(s_tack **listB, s_tack **listA, t_data *info);
static void	beginRotation(s_tack **src, s_tack **dst, t_data *info, int currLen, char list);

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

static void	setGroupRange(t_data *info, int divideBy)
{
	int	i = -1;
	int	size = info->listLen;
	int	currSize = info->aLen - 1;
	//int var = currSize / (size / divideBy);
	while(++i < divideBy)
	{
		//printf("var is %i\n", var);
		if(currSize / (size / divideBy) >= i 
			&& currSize / (size / divideBy) < i + 1)
		{
			//printf("into the loop\n");
			info->maxRange = size - (i * (size / divideBy));
			info->minRange = info->maxRange - (size / divideBy);
		}
		//printf("maxRange is %i and minRange is %i and i is %i\n", info->maxRange, info->minRange, i);
	}
}

void	largeSort(s_tack **listA, s_tack **listB, t_data *info, int divideBy)
{
	s_tack	*current;
	int i;
	while(*listA != NULL)
	{
		current = *listA;
		setGroupRange(info, divideBy);
		i = 0;
		info->holdFront = 0;
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
		beginRotation(listA, listB, info, i,'A');
	}
	sortB(listB, listA, info);
}

//consider using max function inside loop instead of the ifstatement

static void	sortB(s_tack **listB, s_tack **listA, t_data *info)
{
	while(*listB != NULL)
	{
		s_tack *current;
		current = *listB;
		int	i = 0;
		int maxVal = current->value;
		while(current)
		{
			if(current->value >= maxVal)
			{
				maxVal = current->value;
				info->maxValPos = i;
			}
			i++;	
			current = current->next;
		}
		info->holdFront = info->maxValPos;
		info->holdBack = info->maxValPos;
		beginRotation(listB, listA, info, i, 'B');
	}
}

static void	beginRotation(s_tack **src, s_tack **dst, t_data *info, int currLen, char list)
{
	int	movesFrmBk = (info->holdBack - currLen) * -1;
	int	movesFrmFt = info->holdFront;
	
	if (movesFrmBk < movesFrmFt)
	{
		while(movesFrmBk > 0)
		{
			revRotate(src, list);
			movesFrmBk--;
		}
	}
	else if(movesFrmFt <= movesFrmBk)
	{
		while(movesFrmFt > 0)
		{
			rotate(src, list);
			movesFrmFt--;
		}		
	}
	if(movesFrmFt == 0 || movesFrmBk == 0)
	{	
		push(src, dst, info, list);
	}	
}
