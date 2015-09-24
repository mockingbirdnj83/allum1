/*
** get_next_line.c for get_next_line in /home/aubess_t/Desktop
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Nov 24 22:15:55 2013 au
** Last update Sun Feb 16 23:03:04 2014 au
*/

#include "allum1.h"
#include "get_next_line.h"

static char	*my_strncpy(char *dest, char *src, int nb)
{
  int		i;

  i = 0;
  while (*src != '\0' && nb > 0)
    {
      dest[i] = src[i];
      nb = nb - 1;
      i = i + 1;
    }
  if (i == 0 || nb == 0)
    dest[i] = '\0';
  return (dest);
}

static char	*add_to_line(char *line, int i, char *buff, int *begin)
{
  char		*new_elem;
  int		old_len;

  if (line != 0)
    old_len = my_strlen(line);
  else
    old_len = 0;
  if (!(new_elem = my_malloc((old_len + i + 1) * sizeof(*new_elem))))
    return (NULL);
  if (line != 0)
    my_strncpy(new_elem, line, old_len);
  else
    my_strncpy(new_elem, "", old_len);
  my_strncpy(new_elem + old_len, buff + *begin, i);
  new_elem[old_len + i] = 0;
  if (line)
    free(line);
  *begin = *begin + (i + 1);
  return (new_elem);
}

char		*get_next_line(const int fd)
{
  static char	buff[MEM_SIZE];
  static int	k = 0;
  static int	begin = 0;
  int		i;
  char		*line;

  line = 0;
  i = 0;
  while (-1)
    {
      if (begin >= k)
	{
	  begin = 0;
	  if (!(k = read(fd, buff, MEM_SIZE)))
	    my_printf("\033[31mGet Next Line failed.. Please try again.\n\033[0m");
	  if (k == -1)
	    return (NULL);
	  i = 0;
	}
      if (buff[begin + i] == '\n')
	return (line = add_to_line(line, i, buff, &begin));
      if (begin + i == k - 1)
	line = add_to_line(line, i + 1, buff, &begin);
      i++;
    }
}
