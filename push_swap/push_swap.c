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
  t_controleur *d;

  if (ac == 1)
    exit_error(NULL,NULL);
  else
  {
    origin = get_entry(ac,av);
    c = init_c(origin);
    d = copie_c(c);

    ps_swap(1, c); 
    ps_revrot(1, c);  
    ft_putstr("\n test: \t");
    ft_putnbr(0);
    ft_putnbr(solver(d));
    
    
    ft_putendl("\n=======================================");
    aff_state(d);
    d = brute(d,500);

    aff_state(d);
  }
  return (0);
}
