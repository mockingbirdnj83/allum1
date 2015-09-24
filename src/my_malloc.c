/*
** my_malloc.c for my_malloc in /home/aubess_t/work/semestre2/my_malloc/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Jan 26 12:36:11 2014 au
** Last update Sun Feb 16 12:55:11 2014 au
*/

#include "my_malloc.h"
#include "my_malloc_globals.h"

int	g_allocated = 0;
t_elem	**alloc;
t_elem	**match;

void	my_malloc_init()
{
  alloc = lm_add_list("Alloc");
  match = lm_add_list("Match");
}

void	fill_payload(t_payload *payload, char *block, const int size, char *name)
{
  payload->adress = block;
  payload->size = size;
  if (name)
    payload->name = name;
  else
    payload->name = NULL;
}

void	fill_match(t_match *match, char *block, t_elem *elem)
{
  match->block = block;
  match->elem = elem;
}

void	print_nb_alloc()
{
  my_printf("*\n *\n  *\n ***\n\n");
  my_printf(" >  %d Alloc(s) left.\n\n", g_allocated);
  if (g_allocated < 1)
    my_printf(" ***          GG.\n");
  else
    my_printf(" ***\n");
  my_printf("  *\n *\n*\n");
}

void		*my_malloc(const int size, ...)
{
  void		*block;
  t_payload	*payload_alloc;
  t_match	*payload_match;
  t_elem	*elem;
  va_list	ap;

  va_start(ap, size);
  if (!(block = malloc(size)))
    return (NULL);
  payload_alloc = (t_payload*)malloc(sizeof(t_payload));
  fill_payload(payload_alloc, block, size, va_arg(ap, void*));
  if (!(elem = lm_add_elem(&alloc, payload_alloc)))
    return (NULL);
  payload_match = (t_match*)malloc(sizeof(t_match));
  fill_match(payload_match, block, elem);
  if (!lm_add_elem(&match, payload_match))
    return (NULL);
  va_end(ap);
  g_allocated++;
  return (block);
}
