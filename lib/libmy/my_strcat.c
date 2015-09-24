/*
** my_strcat.c for my_strcat in /home/aubess_t/work/oxo/lib/libmy
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Jan 25 02:33:47 2014 au
** Last update Sat Jan 25 02:34:02 2014 au
*/

char    *my_strcat(char *dest, char *src)
{
  int   i;
  int   j;

  j = 0;
  i = my_strlen(dest);
  while (src[j])
    dest[i++] = src[j++];
  dest[i] = 0;
  return (dest);
}
