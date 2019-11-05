
#include "libft.h"

void ft_free_double_array(void **line, int size)
{
	int i;

	i = 0;
	while (i <size)
	{
		free(line[i]);
		i++;
	}
	free(line);
}