#include "pushSwap.h"

static void freeList(s_tack **list);

int	main(int argc, char	**av)
{
	s_tack	*listA;
	s_tack	*listB;
	t_data	*info;
	
	if(argc > 1)
	{
		printf("hellooo\n");
		if (errorChkr(av) == false)
		{
			printf("HELOOO\n");
			initList(&listA, &info, av);
			printf("wazzaaaaaa\n");
			while(checkSort(listA) == false || info->aLen != info->listLen)
			{
				printf("YOOOO\n");	
				startSorting(&listA, &listB, &info);

			}
		}
	}
	write(1, "list is sorted", 14);
	freeList(&listA);
	return (0);
}

static void	freeList(s_tack **list)
{
	s_tack	*current;

	while(*list)
	{
		current = (*list)->next;
		free(*list);
		(*list) = current;
	}
}
