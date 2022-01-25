#include "pushSwap.h"

int	main(int argc, char	**av)
{
	s_tack	*listA;
	s_tack	*listB;
	t_data	*info;
	
	if(argc > 1)
	{
		if (errorChkr(av) == false)
		{
			initList(&listA, &info, av);
			while(checkSort(*listA) == false || info->aLen != info->listLen)
			{	
				startSorting(&listA, &listB, &info);

			}
		}
	}
	write(1, "list is sorted", 14);
	freeList(&listA);
	return (0);
}
