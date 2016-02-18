#include "push_swap.h"

size_t 	rank(t_list *start, int value)
{
	size_t i;

	i = 1;
	while (start)
	{
		if (value > *(int*)start->content)
			i++;
		start = start->next;
	}
	return (i);
}

t_list		*get_valued(t_list *start, int value)
{
	while(start)
	{
		if (*(int*)start->content == value)
			return (start);	
		start = start->next;
	}
	return (start);	
}

t_list 		*get_ranker(t_list *start, size_t index)
{
	t_list *ptr;

	ptr = start;
	while (ptr && rank(start, (*(int*)ptr->content)) != index)
		ptr = ptr->next;
	return (ptr);
}

size_t 			get_length(t_list *start)
{
	size_t i;

	i = 0;
	while (start)
	{
		i++;
		start = start->next;
	}
	return (i);
}
//penser a la_len - get_sublength(c->la)
// sens : val_m > value =>     si val_m >  ->lb, si val_m <  ->la
size_t 			get_sublength(t_list *start, int value, int sens)
{
	int i;

	i = 0;
	while (start)
	{
		if ((value <  *(int*)start->content) ^ !sens)
			return (i);
		if (!start->next)
			return (++i);
		if ((*(int*)start->content < *(int*)start->next->content) ^ !sens)
		{
			start = start->next;
			i++;
		}
		else
			return (++i);
		
	}
	return (i);
}
