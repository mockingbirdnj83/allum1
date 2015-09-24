/*
** my_atoi.c for my_atoi in /home/aubess_t/work/oxo/lib/libmy
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Jan 25 02:34:20 2014 au
** Last update Sat Jan 25 02:34:54 2014 au
*/

int     my_atoi(char *str)
{
  int	i;

  i = 0;
  while (*str)
    {
      if (*str >= '0' && *str <= '9')
        {
          i *= 10;
          i += *str - '0';
        }
      else
        return (i);
      str++;
    }
  return (i);
}
