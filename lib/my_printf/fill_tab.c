/*
** my_printf.c for my_printf in /home/aubess_t/rendu/PSU_2013_my_printf
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Fri Nov  8 15:22:26 2013 au
** Last update Sun Feb 16 01:59:24 2014 au
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

pFct	*func_tab(pFct **tab)
{
  *tab = (pFct*)malloc(sizeof(pFct) * 17);
  (*tab)[0] = flag_d;
  (*tab)[1] = flag_d;
  (*tab)[2] = flag_s;
  (*tab)[3] = flag_S;
  (*tab)[4] = flag_c;
  (*tab)[5] = flag_p;
  (*tab)[6] = flag_x;
  (*tab)[7] = flag_X;
  (*tab)[8] = flag_o;
  (*tab)[9] = flag_b;
  (*tab)[10] = flag_m;
  (*tab)[11] = flag_u;
  (*tab)[12] = flag_n;
  (*tab)[13] = flag_percent;
  (*tab)[14] = flag_d;
  (*tab)[15] = flag_d;
  (*tab)[16] = flag_l;
}

void	fill_tab(t_tab *tab, char *flags_str)
{
  pFct	*fct_tab;

  func_tab(&fct_tab);
  while (*flags_str)
    {
      tab->flag = *flags_str;
      tab->fct = *fct_tab;
      flags_str = flags_str + 1;
      fct_tab = fct_tab + 1;
      tab = tab + 1;
    }
}
