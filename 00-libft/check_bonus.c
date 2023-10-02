#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	del(void *s)
{
	free(s);
}

int	main (int argc, char **argv)
{
	(void)argc;
	t_list	*list1;
	t_list	*list2;
	t_list	*temp;

	list1 = ft_lstnew((char*)argv[1]);
	list2 = ft_lstnew((char*)argv[2]);
	temp = list1;
	printf("%s || %s\n", (char*)list1->content, (char*)list2->content);
	ft_lstadd_front(&list2, list1);
	while (temp != NULL)
	{
		printf("%s\n", (char*)temp->content);
		temp = temp->next;
	}
	int	size = ft_lstsize(list2);
	printf("size : %d\n", size);
	ft_lstclear(&list1, del);
	if (list2 == NULL)
		printf("OK");
}