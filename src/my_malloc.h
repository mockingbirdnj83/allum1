/*
** my_malloc.h for my_malloc in /home/aubess_t/work/semestre2/test
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Jan 26 21:11:08 2014 au
** Last update Sun Feb 16 00:48:57 2014 au
*/

#include <stdarg.h>
#include "../lib/list_manager/list_manager.h"

typedef struct	t_payload
{
  void		*adress;
  unsigned int	size;
  char		*name;
  
}		t_payload;

typedef struct	s_match
{
  t_elem		*elem;
  void			*block;
}			t_match;

void	*my_malloc(int size, ...);
void	my_free(void *block);
