/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/26 22:32:42 by dloustalot    #+#    #+#                 */
/*   Updated: 2024/12/28 20:19:57 by dloustalot    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void){
	int	fd = open("../test.txt", O_RDONLY);
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
	
	int	reps = 14;
	while (reps-- > 0)
	{
		printf("Line-%s", get_next_line(fd));
	}
	return (0);
}