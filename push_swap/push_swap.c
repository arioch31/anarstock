/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/20 18:53:37 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
      if (get_valued(start, test))
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
  size_t        cpt;

  if (ac < 3)
    exit_error(NULL,NULL);
  else
  {
    origin = get_entry(ac,av);
    c = init_c(origin);
    ft_putendl("initalisation OK!");
    ft_putnbr(solver(c));

    ft_putendl("solver v1 OK!");
    d = init_c(origin);
    ft_putnbr(solverv2(d));
    ft_putendl("solver v2 OK!");
    if (c->nb_op < d->nb_op)
    {
        aff_state(c);
        ft_putendl("solver v1 Opti!");
    }
    else
    {    
      aff_state(d);
      ft_putendl("solver v2 Opti!");
    }
    ft_putstr("results :\nv1\t");
    ft_putnbr(c->nb_op);
    ft_putstr("\nv2\t");
    ft_putnbr(d->nb_op);
    


    ft_putendl("\n++++++++++++++++------++++++++++++++++++");
//   if (c->nb_op < 50){
   while ((c = monobrute(init_c(origin), c->nb_op)))
      {
              ft_putnbr(c->nb_op);
              ft_putendl(c->op_j);
        cpt = c->nb_op;
      }
        ft_putendl("test");      
      if ((d = brute(init_c(origin), cpt)))
      {
        ft_putnbr(d->nb_op);
        ft_putendl(d->op_j);
      }
      else
       ft_putendl("echec brute");

    }
//    else
//      ft_putendl("echec monobrute");
  //}
  
  
  return (0);
}
