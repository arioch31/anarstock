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

void exit_error(void)
{
  ft_putendl("Erreur\n");
  exit(0);
}

t_list  *crea_pile(int nb, int *tab)
{
  int i;
  t_list  *start;
  t_list  *elem;

  start = NULL;
  i = 0;
  while (i < nb)
  {
    elem = ft_lstnew(&tab[i], sizeof(int));
    ft_lstapp(&start, elem);
    i++;
  }
  return (start);
}

void aff_pile(t_list *start)
{
  while (start)
  {
    ft_putnbr(*(int*)(start->content));
    ft_putchar(' ');
    start = start->next;
  }
  ft_putchar('\n');
}

int *get_numbers(int ac, char **av)
{
  int i;
  int j;
  int cpt;
  int *tab;
  long int test;

  i = 1;
  tab = malloc(sizeof(int) * (ac - 1));
  while (i < ac)
  {
      j = 0;
      while (j < ft_strlen(av[i]))
          if (!ft_isdigit(av[i][j++]))
            exit_error();
      test = ft_atoli(av[i]);
      if (test != (long int)(int)test)
        exit_error();
      cpt = 0;
      while (cpt < i - 1)
          if (tab[cpt++] == (int)test)
            exit_error();
      tab[i++ - 1] = (int)test;
  }
  return (tab);
}

void print_tab(int *tab, size_t size)
{
  size_t  i;

  i = 0;
  while (i < size)
    ft_putendl(ft_itoa(tab[i++]));
}

int main(int ac, char **av)
{
  int *tab;
  t_list  *liste_a;
  t_list *liste_b;

  liste_b = NULL;
  if (ac == 1)
    exit_error();
  else
  {
    tab = get_numbers(ac, av);
    print_tab(tab, (size_t)ac - 1);
    liste_a = crea_pile(ac - 1, tab);
    aff_pile(liste_a);
    rot_pile(&liste_a);
    aff_pile(liste_a);
    revrot_pile(&liste_a);
    aff_pile(liste_a);
    swap_pile(&liste_a);
    aff_pile(liste_a);
    push_piler(&liste_a, &liste_b);
    aff_pile(liste_a);
    aff_pile(liste_b);
    push_piler(&liste_b, &liste_a);
    aff_pile(liste_a);
    aff_pile(liste_b);
  }
  return (0);
}
