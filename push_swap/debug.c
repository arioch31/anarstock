#include "push_swap.h"

void 	aff_state(t_controleur *c)
{
  if (!c)
    ft_putendl("c vide");
  else
  {
   ft_putendl("\n============================");
	ft_putendl("état des piles :");
  ft_putendl("base===================sommet");
	aff_pile(c->la);
	ft_putchar('\n');
	aff_pile(c->lb);
  ft_putendl("\nbase===================sommet");
	ft_putendl("journal:");
	ft_putendl(c->op_j);
  ft_putstr("nb op :\t\t");
  ft_putnbr(c->nb_op);
  ft_putstr("\nlast op :\t");
  ft_putendl(c->last_op);
  ft_putstr("length totale :\t");
  ft_putnbr(c->length);
  ft_putstr("\nlength la :\t");
  ft_putnbr(c->la_len);
  ft_putstr("\nlength lb :\t");
  ft_putnbr(c->lb_len);
  ft_putstr("\nval mediane :\t");
  ft_putnbr(c->val_m);
  ft_putstr("\nphase :\t");
  ft_putnbr(c->phase);
  }
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

int pile_triee(t_list *p)
{
  if (!p)
    return (0);
  if (!p->next)
    return (1);
  if (*(int*)p->content < *(int*)p->next->content)
    return(pile_triee(p->next));
  return (0);
}

void del_list(void* content, size_t content_size)
{
   if (!content_size)
  free(content);
  if (content_size)
  content_size = 0;
}

void exit_error(t_list *origin, t_controleur *c)
{
  if (origin)
    ft_lstdel(&origin, &del_list);
  ft_putendl("erreur\n");
  destr_c(&c); 
  exit(0);
}
