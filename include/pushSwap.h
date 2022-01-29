#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
#include <stdio.h>

typedef struct s_tack
{
	int				value;
	int				pos;
	int				index;
	struct s_tack	*next;
}					s_tack;

typedef struct	s_data
{
	int	listLen;
	int	aLen;
	int bLen;
	int	minRange;
	int	maxRange;
	int	minValPos;
	int	maxValPos;
	int	holdFront;
	int	holdBack;
}				t_data;

//errorChkr.c
bool	errorChkr(char **av);

//initData.c
void	initList(s_tack **listA, t_data *info, char **av);

//startSorting.c
void	startSorting(s_tack **listA, s_tack **listB, t_data *info); ///COME BACK TO THIS PASSED AS DOUBLE POINTER HERE BUT NOT FURTHER ALONG THE LINE!!///

//largeSort.c
void	largeSort(s_tack **listA, s_tack **listB, t_data *info, int divideBy);

//utils.c
bool	checkSort(s_tack *list, bool rev);
int	minVal(s_tack **list, t_data *info);
int	maxVal(s_tack **list, t_data *info);
int	atoi(const char *str);

//moves.c
void	swap(s_tack **list, char listName);
void	rotate(s_tack **list, char listName);
void	revRotate(s_tack **list, char listName);
void	push(s_tack **src, s_tack **dst, t_data *info, char listName);

#endif
