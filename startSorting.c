#include "pushSwap.h"

void	startSorting(s_tack **listA, s_tack **listB, t_data **info)
{
	if((*info)->listLen == 2)
		swap(listA, 'A');
	if((*info)->listLen == 3)
		sort3(listA);
	if((*info)->listLen <= 10)
		smallSort(listA, listB, info)
	if((*info)->listLen <= 101)
		largeSort(listA, listB, info, 5);
	else
		largeSort(listA, listB, info, 11);
	return ; 

}

void	sort3(s_tack **listA)
{
	if((*listA)->value == maxVal(listA))
		rotate(listA, 'A');
	else if((*listA)->next->value == minVal(listA) || chkRevSort(*listA) == true)
		swap(listA, 'A');
	else
		revRotate(listA, 'A');
	return ;
}

void	smallSort(s_tack **listA, s_tack **listB, t_data *info)
{
	if((*listA)->value == minVal(listA))
		push(listA, listB, 'A');
	if((*info)->minValPos <= ((*info)->listLen / 2))
		rotate(listA, 'A');
	else
		revRotate(listA, 'A');
	if(checkSort(*listA) && chkRevSort(*listB))
		push(listB, listA, 'B');
	return ;
}

