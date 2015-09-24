/*
** my_putchar.c for my_putchar in /home/aubess_t/work/oxo/lib/libmy
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Jan 25 02:31:16 2014 au
** Last update Sat Jan 25 03:07:04 2014 au
*/

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (1);
  return (0);
}
