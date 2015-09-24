/*
** my_strlen.c for my_strlen in /home/aubess_t/rendu/PSU_2013_my_printf
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Fri Jan 24 19:02:41 2014 au
** Last update Fri Jan 24 19:03:00 2014 au
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
