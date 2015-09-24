/*
** my_putchar.c for my_putchar in /home/aubess_t/rendu/PSU_2013_my_printf
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Tue Nov 12 08:29:39 2013 au
** Last update Sat Jan 25 02:27:20 2014 au
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}
