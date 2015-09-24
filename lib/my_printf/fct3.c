/*
** fct3.c for fct3 in /home/aubess_t/rendu/PSU_2013_my_printf
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Nov 17 23:01:44 2013 au
** Last update Sun Nov 17 23:06:48 2013 au
*/

#include <stdarg.h>
#include "my.h"

int	flag_m(va_list list, int output, char *ptr)
{
  output = output + my_putstr("Success");
  return (output);
}

int	flag_n(va_list list, int output, char *ptr)
{
  int	*n;

  n = va_arg(list, int *);
  *n = output;
  return (0);
}

int	flag_percent(va_list list, int output, char *ptr)
{
  output = output + my_putchar('%');
  return (output);
}

int	flag_l(va_list list, int output, char *ptr)
{
  if (*(ptr + 1) == 'd' || *(ptr + 1) == 'i' || *(ptr + 1) == 'u')
    output = output + flag_ld(list, output, ptr);
  else if (*(ptr + 1) == 'x')
    output = output + flag_lx(list, output, ptr); 
  else if (*(ptr + 1) == 'X')
    output = output + flag_lX(list, output, ptr);
  else if (*(ptr + 1) == 'o')
    output = output + flag_lo(list, output, ptr);
  return (output);
}
