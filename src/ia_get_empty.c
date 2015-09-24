/*
** ia_get_empty.c for ia_get_empty in /home/aubess_t/work/semestre2/allum1/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Feb 15 23:12:34 2014 au
** Last update Sun Feb 16 12:46:47 2014 au
*/

#include "allum1.h"

int	count_not_empty_lines(t_var *board)
{
  int	i;
  int	meter;

  i = -1;
  meter = 0;
  while (++i < board->nb_line)
    if (board->tab[i])
      meter++;
  return (meter);
}

int	*get_filled_lines_id(t_var *board, int nb_no_empty)
{
  int	*no_empty;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (!(no_empty = my_malloc(sizeof(int) * nb_no_empty)))
    return (NULL);
  while (j < nb_no_empty && i < board->nb_line)
    {
      while (!(board->tab[i]))
	i++;
      no_empty[j++] = i++;
    }
  return (no_empty);
}
