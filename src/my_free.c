/*
** my_free.c for my_free in /home/aubess_t/work/semestre2/my_malloc/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Wed Feb 12 22:17:54 2014 au
** Last update Sun Feb 16 12:55:21 2014 au
*/

#include "my_malloc.h"
#include "my_malloc_globals.h"

t_elem		*match_elem(void *block)
{
  t_elem	*tmp;

  if (match)
    {
      tmp = *match;
      if ((((t_match*)tmp->payload)->block) == block)
      	return (tmp);
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	  if ((((t_match*)tmp->payload)->block) == block)
	    return (tmp);
	}
    }
  return (NULL);
}

void		my_free(void *block)
{
  t_elem	*elem_match;

  if (!(elem_match = match_elem(block)))
    exit(my_putstr("Match Failed.\n"));
  free(block);
  lm_remove_elem(&alloc, ((t_match*)elem_match->payload)->elem);
  lm_remove_elem(&match, elem_match);
  g_allocated--;
}
