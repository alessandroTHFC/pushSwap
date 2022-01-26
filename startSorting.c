#include "pushSwap.h"

static void	sort3(s_tack **listA, t_data *info);
static void	smallSort(s_tack **listA, s_tack **listB, t_data *info);

void	startSorting(s_tack **listA, s_tack **listB, t_data *info)
{
	if(info->listLen == 2)
		swap(listA, 'A');
	if(info->listLen == 3)
		sort3(listA, info);
	if(info->listLen <= 10)
		smallSort(listA, listB, info);
	if(info->listLen <= 101)
		largeSort(listA, listB, info, 5);
	else
		largeSort(listA, listB, info, 11);
	return ; 
}

//sort3 function
//rudamentary sorting function that handles 3 digits

static void	sort3(s_tack **listA, t_data *info)
{
	if((*listA)->value == maxVal(listA, info))
		rotate(listA, 'A');
	else if((*listA)->next->value == minVal(listA, info) || chkRevSort(*listA) == true)
		swap(listA, 'A');
	else
		revRotate(listA, 'A');
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
	if((*listA)->value == minVal(listA, info))
		push(listA, listB, info,'B');
	if(info->minValPos <= (info->listLen / 2))
		rotate(listA, 'A');
	else
		revRotate(listA, 'A');
	if(checkSort(*listA) && chkRevSort(*listB))
		push(listB, listA, info , 'A');
	return ;
}
