#include "push_swap.h"

void 	aff_state(t_controleur *c)
{
	ft_putendl("état des piles :");
	aff_pile(c->la);
	ft_putchar('\n');
	aff_pile(c->lb);
	ft_putstr("\nnb op :\t");
	ft_putnbr(c->nb_op);
	ft_putendl("\njournal:");
	ft_putendl(c->op_j);
}

void aff_pile(t_list *start)
{
  if (start)
  {
    if (start->next)
    {
      aff_pile(start->next);
      ft_putchar(' ');
    }
    ft_putnbr(*(int*)(start->content));
  }
}
