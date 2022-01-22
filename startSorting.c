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

//sort3 function
//rudamentary sorting function that handles 3 digits

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

///<<<<issue will arrise if you think it will run sort3 when it gets down to 3 numbers, cant enter that function
//because listlen will never decrease to allow it. either add length function inside here or put a aLen and bLen
//field into the info struct so if aLen is 3 then run the sor3 function. would need to ++ and -- everytime 
// there is a push occuring. if pa then aLen-- and bLen++

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

