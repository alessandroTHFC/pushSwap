#include "pushSwap.h"

static bool	isNb(char *nb);
static bool	isInt(char *nb);
static bool	hasDup(char *nb, char **av, int i);

//errorChkr function
//main error checking function, if statement that if conditions of 3 error handling functions arent met will...
//..return an error statement and exit the program. Otherwise sends true back to the main..

bool	errorChkr(char **av)
{
	int	i = 0;
	while (av[++i])
	{
		if(isNb(av[i]) == false || hasDup(av[i], av, i) == true || isInt(av[i]) == false)
			write(1,"Error! Invalid arguments, either:\n Not a number\n Outside bounds of Integer\n Duplicate number", 93);
			exit (1);
	}
	return (true);
}

//isNB function
//checks that character in argument vector is actually a number and not a letter or other type character;

static bool	isNb(char *nb)
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

//isInt function
//checks that number is within the bounds of an integer;

static bool	isInt(char *nb)
{
	long int	num = ft_atoi(nb);
	if(num < -2147483648 || num > 2147483648)
		return (false);
	return (true);
}

//hasDup Function
//sets num variable equal to integer of number needing to be checked;
//then uses argument vector i + 1 to check against the next numbers in the list until no more arguments;

static bool	hasDup(char *nb, char **av, int i)
{
	long int	num = atoi(nb);
	while (av[i + 1])
	{
		if(num == ft_atoi(av[i + 1]))
			return (true);
		i++;
	}
	return (false);
}
