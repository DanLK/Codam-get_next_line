#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		reps = 30;
	char	*result;
	// char	*stash = NULL;
	// char	*r_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));

	int	fd = open("test_nwl.txt", O_RDONLY);
	result = "";
	while (reps > 0)
	{
		result = get_next_line_(fd);
		if (result)
		{
			printf("LINE: %s", result);
			// printf("\nterminated: %d\n\n", result[ft_strlen(result) - 1] == '\0');
		}
		else
			printf("\nNULL");
		reps--;
	}
	return (0);
}