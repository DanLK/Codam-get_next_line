#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*stash = "I already have some text";
	char	*r_buff = (char *)malloc(BUFFER_SIZE * sizeof(char));
	int		reps = 1;

	if (!r_buff)
		printf("%s\n", "Error allocating memory for the buffer");
	else
	{
		int	fd = open("test.txt", O_RDONLY);
		while (reps > 0)
		{
			printf("%s", get_next_line(fd));
			reps--;
		}
	}
	return (0);
}