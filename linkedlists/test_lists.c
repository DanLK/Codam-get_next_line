/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_lists.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/26 22:32:42 by dloustalot    #+#    #+#                 */
/*   Updated: 2024/12/31 11:53:13 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void){
	int	fd = open("../test.txt", O_RDONLY);
	// int	fd2 = open("../test_nwl.txt", O_RDONLY);
	// t_list	**stash;
	// t_list	*node = NULL;
	// char	*line;
	
	// stash = &node;
	// // printf("%d\n", find_char(*stash, '\n'));
	// // ft_lstadd_back(stash, ft_lstnew("hola"));
	// // ft_lstadd_back(stash, ft_lstnew("num 2"));
	// // ft_lstadd_back(stash, ft_lstnew("tres"));
	
	// read_to_list(fd, stash);
	// printf("Line: %s\n", get_line(*stash));
	// set_list(stash);
	// // printf("%d\n", node == NULL);
	// // printf("Number: %d\n", find_char(*stash, '\n'));
	// while(node)
	// {
	// 	printf("Node: %s\n",node->content);
	// 	printf("\n");
	// 	node = node->next;
	// }
	
	// int	reps = 15;
	char	*result;
	result = get_next_line(fd);

	while (result)
	{
		if (result)
			printf("Line-%s", result);
		else
			printf("\nNULL");
		result = get_next_line(fd);
	}
	// int	len;
	// t_list	*node;

	// node = ft_lstnew("s will bring aboard.");
	// len = find_char(node, '\n');
	// printf("Len%d\n", len);
	return (0);
}