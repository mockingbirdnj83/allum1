/*
** lc.h for lc in /home/aubess_t/work/semestre2/test
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Wed Feb  5 00:12:25 2014 au
** Last update Mon Feb 10 23:41:19 2014 au
*/


#include <stdlib.h>

#ifndef LC_H_
#define LC_H_

typedef struct	s_elem
{
  struct s_elem	*prev;
  struct s_elem	*next;
  void		*payload;
  int		id;
}		t_elem;

t_elem	*my_create_elem(void *payload);
t_elem	*my_add_elem(t_elem ***list, void *payload);

#endif
