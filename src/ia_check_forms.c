/*
** ia_check_forms.c for ia_check_forms in /home/aubess_t/work/semestre2/allum1/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Feb 15 14:23:06 2014 au
** Last update Sat Feb 15 22:52:18 2014 au
*/

#include "allum1.h"

int	one_of_two_is_one(t_var *board, int *no_empty)
{
  if (board->tab[no_empty[0]] == 1)
    return (1);
  else if (board->tab[no_empty[1]] == 1)
    return (2);
  else
    return (0);
}

int	one_of_two_is_two(t_var *board, int *no_empty)
{
  if (board->tab[no_empty[0]] == 2 && board->tab[no_empty[1]] != 2)
    return (1);
  else if (board->tab[no_empty[1]] == 2 && board->tab[no_empty[0]] != 2)
    return (2);
  else
    return (0);
}

int	two_of_three_is_two(t_var *board, int *no_empty, int nb_no_empty)
{
  int	meter;
  int	i;
  int	result;

  meter = 0;
  i = -1;
  while (++i < nb_no_empty)
    if (board->tab[no_empty[i]] == 2)
      {
	if (meter == 0)
	  result += i;
	else
	  result += (i * 10);
	meter++;
      }
  if (meter == 2)
    return (result);
  else
    return (0);
}

int	one_of_all_is_three(t_var *board, int *no_empty, int nb_no_empty)
{
  int	i;

  i = -1;
  while (++i < nb_no_empty)
    if (board->tab[no_empty[i]] >= 3)
      return (i);
  return (-1);
}
