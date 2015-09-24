/*
** my_memset.c for my_memset in /home/aubess_t/work/minishell4
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Jan 25 03:21:24 2014 au
** Last update Sat Jan 25 03:21:48 2014 au
*/

void	my_memset(char *s, char c, int size)
{
  int   i;

  i = 0;
  while (i < size)
    s[i++] = c;
}
