#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}