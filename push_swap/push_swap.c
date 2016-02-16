/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/15 04:53:58 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void del_list(void* content, size_t content_size)
{
  free(content);
  if (content_size)
  content_size = 0;
}

void exit_error(t_list *origin, t_controleur *c)
{
  if (origin)
  {
    ft_lstdel(&origin, &del_list);
  }
  if (c)
  {
      ft_lstdel(&(c->la), &del_list);
      ft_lstdel(&(c->lb), &del_list);
      free(c->op_j);
      free(c);
  }
  exit(0);
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

t_list *get_entry(int ac, char **av)
{
   int i;
  unsigned int j;
  long int test;
  char    charset[] = "0123456789+-";
  t_list  *start;

  start = NULL;
  i = 0;
  while (++i < ac)
  {
      j = 0;
      while (j < ft_strlen(av[i]))
          if (!ft_strchr(charset, av[i][j++]))
            exit_error(start, NULL);
        test = ft_atoli(av[i]);
      if ((unsigned long int)test != (unsigned long int)(int)test)
        exit_error(start, NULL);
     ft_lstapp(&start, ft_lstnew(&test, sizeof(int)));
  }
  return(start);
}

int main(int ac, char **av)
{
  t_list  *origin;
  t_controleur *c;

  if (ac == 1)
    exit_error(NULL,NULL);
  else
  {
    origin = get_entry(ac,av);
    c = init_c(origin);
    aff_state(c);   
   
     if (ps_push(1, c))
      aff_state(c);
    if (ps_push(1, c))
      aff_state(c);
    ft_putendl("\ntest ok!\n");
    exit_error(origin, c);

    
  }
  return (0);
}
