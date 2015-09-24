/*
** my_atoi.c for my_atoi in /home/aubess_t/rendu/PSU_2013_my_printf
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Nov 17 23:31:52 2013 au
** Last update Sun Nov 17 23:32:02 2013 au
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
      str = str + 1;
    }
  return (i);
}
