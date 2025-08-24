#include "../includes/cube3d.h"

void	free_str(char **str, int count)
{
	int	a;

	a = 0;
	if (!count)
	{
		while (str[count])
			count++;
	}
	while (a < count)
	{
		if (str[a])
			free(str[a]);
		a++;
	}
	if (str)
		free(str);
}

void	my_free(char *str)
{
	if (str)
		free(str);
}