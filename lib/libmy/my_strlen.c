/*
** my_strlen.c for my_strlen in /home/aubess_t/work/oxo/lib/libmy
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Jan 25 02:33:16 2014 au
** Last update Sat Jan 25 02:33:30 2014 au
*/

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
