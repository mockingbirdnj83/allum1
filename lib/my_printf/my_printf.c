/*
** my_printf.c for my_printf in /home/aubess_t/rendu/PSU_2013_my_printf
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Fri Nov  8 15:22:26 2013 au
** Last update Sun Feb 16 01:58:05 2014 au
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int		my_printf(char *fmt, ...)
{
  va_list	ap;
  char		*ptr;
  t_tab		*tab;
  char		*flags_str;

  va_start(ap, fmt);
  ptr = fmt;
  flags_str = "disScpxXobmun%+ l";
  tab = malloc(sizeof(t_tab) * 17);
  fill_tab(tab, flags_str);
  run(fmt, tab, ap);
  va_end(ap);
}
