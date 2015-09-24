/*
** my_putstr.c for my_putstr in /home/aubess_t/work/oxo/lib/libmy
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Jan 25 02:32:13 2014 au
** Last update Sat Jan 25 02:32:51 2014 au
*/

#include <unistd.h>

int     my_putstr(char *str)
{
  while (*str)
    if (write(1, &(*(str++)), 1) == -1)
      return (1);
  return (0);
}
