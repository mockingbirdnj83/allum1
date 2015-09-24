/*
** list_manager.c for list_manager in /home/aubess_t/work/semestre2/my_malloc/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Thu Feb  6 23:59:15 2014 au
** Last update Fri Feb 28 11:56:33 2014 au
*/

#include "list_manager.h"

t_manager *g_list = NULL;

t_manager       *lm_create_list(char *name)
{
  static int	id = 0;
  t_manager	*new_element;

  if (!(new_element = (t_manager*)malloc(sizeof(t_manager))))
    return (NULL);
  new_element->next = NULL;
  new_element->prev = NULL;
  new_element->id = id++;
  new_element->payload.list = NULL;
  new_element->payload.name = name;
  return (new_element);
}

t_elem		**lm_add_list(char *name)
{
  t_manager	*tmp;
  t_manager	*new_element;

  tmp = g_list;
  if (!(new_element = lm_create_list(name)))
    return (NULL);
  if (g_list == NULL)
    g_list = new_element;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_element;
      new_element->prev = tmp;
    }
  return (t_elem**)(&(new_element->payload.list));
}

t_elem	*lm_add_elem(t_elem ***list, void *payload)
{
  return (my_add_elem(list, payload));
}

void	lm_remove_elem(t_elem ***list, t_elem *elem)
{
  my_remove_elem(list, elem);
}

void		my_print_list()
{
  t_manager	*tmp;
  t_elem	*tmp2;
  int		i = 0;
  
  my_printf("\n#######################################################\n##\n");
  my_printf("##\t\t LIST MANAGER - STATUS\n##\n##\n");
  if (g_list)
    {
      tmp = g_list; 
      do
	{
	  if (i != 0)
	    tmp = tmp->next;
	  i = 1;
	  if (tmp->payload.list)
	    {
	      tmp2 = tmp->payload.list;
	      my_printf("##  > Liste : [ %s ]\n##\n", tmp->payload.name);
	      while (tmp2->next != NULL)
		{
		  my_printf("##\t[ ELEM n.%d ] : %p\n", tmp2->id, tmp2); 
		  tmp2 = tmp2->next;
		}
	      my_printf("##\t[ ELEM n.%d ] : %p\n##\n##\n", tmp2->id, tmp2);
	    }
	} while (tmp->next != NULL);
    }
  my_printf("#######################################################\n");
}
