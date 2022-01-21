#include "pushSwap.h"

bool	isNb(char *nb);
bool	isInt(char *nb);
bool	hasDup(char *nb, char **av, int i);

bool	errorChkr(char **av)
{
	int	i = 0;
	while (av[++i])
	{
		if(isNb(av[i]) == false || hasDup(av[i], av, i) == true || isInt(av[i]) == false)
			ft_printf("Error! Invalid arguments, either:\n Not a number\n Outside bounds of Integer\n Duplicate number");
			exit (1);
	}
	return (true);
}

bool	isNb(char *nb)
{
	int	i = -1;
	while(nb[++i])
	{
		if(nb[i] == '-')
			i++;
		if(!(nb[i] >= '0' && nb[i] <= '9'))
			return (false);
	}
	return (true);
}

bool	isInt(char *nb)
{
	long int	num = ft_atoi(nb);
	if(num < -2147483648 || num > 2147483648)
		return (false);
	return (true);
}

bool	hasDup(char *nb, char **av, int i)
{
	long int	num = atoi(nb);
	while (num[i + 1])
	{
		if(num == ft_atoi(av[i + 1]))
			return (true);
		i++;
	}
	return (false);
}
