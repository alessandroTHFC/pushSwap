#include "pushSwap.h"

///checkSort function;
///this function is vital for the operation of the sort;
///it iteratates through the linked list checking if the list is sorted in ascending order, and;
///whether or not the bool rev is true will look for checking if sorter in descending order;

bool	checkSort(s_tack *list, bool rev)
{
	if(!list || !list->next)
		return(true);
	while (list->next)
	{
		if (!rev && list->value > list->next->value)
			return (false);
		if (rev && list->value < list->next->value)
			return (false);
		list = list->next;
	}
	return (true);
}

///minVal function
///Returns the minimum value in the list and also assigns values list position to the variable
///minValPos in the info struct;

int	minVal(s_tack **list, t_data *info)
{
	s_tack	*temp = *list;
	int		minVal = temp->value;
	int		i = 1;
	while(temp->next)
	{
		temp = temp->next;
		if(temp->value < minVal)
		{	
			minVal = temp->value;
			info->minValPos = i;
		}	
		i++;	
	}
	return(minVal);
}

int	maxVal(s_tack **list, t_data *info)
{
	s_tack	*temp = *list;
	int	maxVal = temp->value;
	int	i = 0;
	while(temp->next)
	{
		temp = temp->next;
		if(temp->value > maxVal)
		{
			maxVal = temp->value;
			info->maxValPos = i;
		}
		i++;
	}
	return(maxVal);
}

static int	isspace(int c)
{
	return (c == '\f' || c == '\r' || c == '\n'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	atoi(const char *str)
{
	int	value;
	int	posneg;

	value = 0;
	posneg = 1;
	while (isspace(*str))
		str++;
	if (*str == '-')
		posneg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		value = (value * 10) + (*str - '0');
		str++;
	}
	return (value * posneg);
}

