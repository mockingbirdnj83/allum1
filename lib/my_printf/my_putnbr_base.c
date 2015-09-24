/*
** my_putnbr_base.c for my_putnbr_base in /home/aubess_t/rendu/PSU_2013_my_printf
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Nov 17 23:41:23 2013 au
** Last update Sun Nov 17 23:41:24 2013 au
*/


#include "my.h"

int	my_putnbr_base(int nb, char *base)
{
  int   result;
  int   diviseur;
  int   size_base;
  int	output;

  output = 0;
  size_base = my_strlen(base);
  if (nb < 0)
    {
      output = output + my_putchar('-');
      nb = -nb;
    }
  diviseur = 1;
  while ((nb / diviseur) >= size_base)
    diviseur = diviseur * size_base;
  while (diviseur > 0)
    {
      result = (nb /diviseur) % size_base;
      output = output + my_putchar(base[result]);
      diviseur = diviseur / size_base;
    }
  return (output);
}
