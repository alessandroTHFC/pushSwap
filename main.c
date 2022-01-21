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
			initData(&listA, &info, av);
			while(checkSort(*listA) == false && listB == NULL)
			{	
				startSorting(&listA, &listB, &info);

			}
		}
	}
	ft_printf("list is sorted");
	freeList(&listA);
	return (0);
}
