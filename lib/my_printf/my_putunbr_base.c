/*
** my_putunbr_base.c for my_putunbr_base.c in /home/aubess_t/rendu/PSU_2013_my_printf
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Nov 17 23:40:58 2013 au
** Last update Sun Feb 16 01:56:46 2014 au
*/


#include "my.h"

typedef unsigned int uint;

int	my_putunbr_base(uint nb, char *base)
{
  uint	result;
  uint	diviseur;
  int   size_base;
  int	output;

  output = 0;
  size_base = my_strlen(base);
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
