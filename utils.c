#include "pushSwap.h"

//utils file will include: minVal/maxVal functions && checkSort/chkRevSort functions
//REMEMEBER to add the info stuct into minval function calls!!<<<<<<<
//pointer syntax probably needs fixing too

bool	checkSort(s_tack *list)
{
	if(!list || !list->next)
		return(false);
	while(list && list->next)
	{
		if(list->value > list->next->value)
			return(false);
		list = list->next;
	}
	return(true);
}

bool	chkRevSort(s_tack *list)
{
	if(!list || !list->next)
		return(false);
	while(list && list->next)
	{
		if(list->value < list->next->value)
			return(false);
		list = list->next;		
	}
	return(true);
}

int	minVal(s_tack **list, t_data **info)
{
	s_tack	*temp = *list;
	int		minVal = temp->value;
	int		i = 0;
	while(temp->next)
	{
		temp = temp->next;
		if(temp->value < minVal)
		{	
			minVal = temp->value;
			(*info)->minValPos = i;
		}	
		i++;	
	}
	return(minVal);
}

int	maxVal(s_tack **list, t_data **info)
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
			(*info)->maxValPos = i;
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

