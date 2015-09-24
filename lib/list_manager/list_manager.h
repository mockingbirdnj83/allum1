/*
** list_manager.h for list_manager in /home/aubess_t/work/semestre2/my_malloc
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Fri Feb  7 00:24:04 2014 au
** Last update Wed Feb 12 22:27:56 2014 au
*/

#include <stdlib.h>
#include "lc.h"

#ifndef LIST_MANAGER_H_
#define LIST_MANAGER_H_

typedef struct	s_payload_lm
{
  t_elem	*list;
  char		*name;
}		t_payload_lm;

typedef struct		s_manager
{
  struct s_manager	*prev;
  struct s_manager	*next;
  int			id;
  t_payload_lm		payload;
}			t_manager;

t_elem **lm_add_list(char *name);
t_elem *lm_add_elem(t_elem ***list, void *payload);
void my_print_list();
void print_Manager();
#endif
