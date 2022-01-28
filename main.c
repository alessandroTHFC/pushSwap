#include "pushSwap.h"

static void freeList(s_tack **list);
static void	*ft_memset(void *s, int c, size_t len);

int	main(int argc, char	**av)
{
	s_tack	*listA;
	s_tack	*listB;
	t_data	info;
	
	if(argc > 1)
	{
		ft_memset(&info, 0, sizeof(t_data));
		if (errorChkr(av))
		{
			initList(&listA, &info, av);
			info.aLen = info.listLen;	
			startSorting(&listA, &listB, &info);
		}
	}
	write(1, "list is sortedi\n", 15);
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

static void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (len--)
		*str++ = (unsigned char)c;
	return (s);
}
