#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_tack
{
	int				value;
	int				pos;
	int				index;
	struct s_tack	*next
}					s_tack;

typedef struct	s_data
{
	int	listLen;
	int	aLen;
	int bLen;
	int	minRange;
	int	maxRange;
	int	minValPos;
	int	highValPos
	int	holdFront;
	int	holdBack;
}				t_data;
