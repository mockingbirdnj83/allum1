/*
** my_printf.c for my_printf in /home/aubess_t/rendu/PSU_2013_my_printf
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Fri Nov  8 15:22:26 2013 au
** Last update Sun Feb 16 01:55:48 2014 au
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	check_match(char *chr, t_tab *tab, int output, va_list ap)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while ((*chr != tab->flag) && i < 18)
    {
      tab += 1;
      i++;
    }
  if (i == 18)
    my_putstr("?.?");
  else
    output = tab->fct(ap, output, chr);
  return (output);
}

void	run(char *fmt, t_tab *tab, va_list ap)
{
  char	*ptr;
  int	output;

  ptr = fmt;
  output = 0;
  while (*ptr)
    {
      if (*ptr == '%')
	{
	  ptr++;
	  output = check_match(ptr, tab, output, ap);
	}
      else
	output += my_putchar(*ptr);
      ptr++;
    }
}
