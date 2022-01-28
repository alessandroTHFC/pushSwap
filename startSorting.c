#include "pushSwap.h"

static void	sort3(s_tack **listA, t_data *info);
static void	smallSort(s_tack **listA, s_tack **listB, t_data *info);

void	startSorting(s_tack **listA, s_tack **listB, t_data *info)
{
	if(info->listLen == 2)
		swap(listA, 'A');
	else if(info->aLen == 3)
		sort3(listA, info);
	else if(info->listLen > 3 && info->listLen <= 10)
		smallSort(listA, listB, info);
	else if(info->listLen > 10)
		largeSort(listA, listB, info, 5);
	else
		largeSort(listA, listB, info, 11);
//	while(*listB)
//		push(listB, listA, info, 'B');
	return ; 
}

//sort3 function
//rudamentary sorting function that handles 3 digits

static void	sort3(s_tack **listA, t_data *info)
{
	while(!checkSort(*listA, false))
	{		
		//printf("inside sort3\n");
		if((*listA)->value == maxVal(listA, info))
			rotate(listA, 'A');
		else if((*listA)->next->value == minVal(listA, info) || checkSort(*listA, true) == true)
			swap(listA, 'A');
		else
			revRotate(listA, 'A');
	}
	return ;
}

//smallSort function
//this function operates will handle between 4 to 10 numbers.
//it operates by looking for the lowest number in the set. In this case the field minValPos inside the info struct
//is set when it runs the minVal function in the first if Statement.
//it uses this index position to figure out whether to rotate forwards or backwards depending on its location.
//this is why we divide the length of the list(listLen) by 2. If the list is 10, halfway is 5. If minValPos is..
// 8 it will reverse rotate as it can move the number to the head faster that way.
//If its position in the list was index val of 3 it would rotate normally.
//once it has lowest number at the head, it will push it into stack b.
//and then continue until list is do

static void	smallSort(s_tack **listA, s_tack **listB, t_data *info)
{
	int min;
	while(!checkSort(*listA, false) || info->aLen != info->listLen)
	{
		min = minVal(listA, info);
		//printf("inside smallsort j  is %i, min is %i\n", j, min);
		if(checkSort(*listA, false) && checkSort(*listB, true))
		{	
			push(listB, listA, info,'B');
		}	
		else if((*listA)->value == minVal(listA, info))
		{
			push(listA, listB, info, 'A');
		}
		else if(info->aLen == 3)
			sort3(listA, info);
		else if(info->minValPos <= (info->aLen / 2))
			rotate(listA, 'A');
		else
			revRotate(listA, 'A');
	}	
	return ;
}
