/*
** lc.c for lc in /home/aubess_t/work/semestre2/test
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Tue Feb  4 23:48:11 2014 au
** Last update Wed Feb 12 22:28:27 2014 au
*/

#include "lc.h"
#include <stdio.h>

t_elem		*my_create_elem(void *payload)
{
  static int	id = 0;
  t_elem	*new_element;

  if (!(new_element = (t_elem*)malloc(sizeof(t_elem))))
    return (NULL);
  new_element->next = NULL;
  new_element->prev = NULL;
  new_element->payload = payload;
  new_element->id = id++;
  return (new_element);
}

t_elem		*my_add_elem(t_elem ***list, void *payload)
{
  t_elem	*tmp;
  t_elem	*new_element;

  tmp = **list;
  if (!(new_element = my_create_elem(payload)))
    return (NULL);
  if (**list == NULL)
    **list = new_element;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_element;
      new_element->prev = tmp;
    }
  return (new_element);
}

t_elem	*my_get_last_elem(t_elem *list)
{
  while (list->next != NULL)
    list = list->next;
  return (list);
}

void	remove_in_list(t_elem *tmp, t_elem *elem)
{
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
      if (tmp == elem)
	{
	  free(tmp->payload);
	  tmp->next->prev = tmp->prev;
	  tmp->prev->next = tmp->next;
	  free(tmp);
	}
    }
}

void		my_remove_elem(t_elem ***list, t_elem *elem)
{
  t_elem	*tmp;

  tmp = **list;
  if (tmp == elem)
    {
      free(tmp->payload);
      tmp->next->prev == NULL;
      **list = tmp->next;
      free(tmp);
    }
  else if ((tmp = my_get_last_elem(tmp)) == elem)
    {
      free(tmp->payload);
      tmp->prev->next = NULL;
      free(tmp);
    }
  else
    remove_in_list(**list, elem);
}
