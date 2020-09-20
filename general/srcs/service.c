#include "filler.h"

t_fill	*error_f(char *errortext, int init)
{
	static t_fill	*fill;

	if (init)
	{
		fill = new_fill();
		return (fill);
	}
	else
	{
		free_fill(fill);
		ft_error_t(errortext);
	}
	return (NULL);
}