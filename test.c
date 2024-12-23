#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		reps = 1;
	char	*result;

	int	fd = open("test.txt", O_RDONLY);
	result = "";
	while (result)
	{
		result = get_next_line(fd);
		if (result)
			printf("%s", result);
		else
			printf("NULL\n");
		reps--;
	}
	return (0);
}