/*
** my_putnbr.c for my_putnbr in /home/aubess_t/work/oxo/lib/libmy
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Jan 25 02:35:23 2014 au
** Last update Sat Jan 25 02:35:42 2014 au
*/

int     my_putnbr(int nb)
{
  if (nb == -2147483648)
    if (my_putstr("-2147483648") == 1)
      return (1);
  if (nb < 0)
    {
      nb = -nb;
      if (my_putchar('-') == 1)
	return (1);
    }
  if (nb > 9)
    if (my_putnbr(nb / 10) == 1)
      return (1);
  if (my_putchar(nb % 10 + 48) == 1)
    return (1);
  return (0);
}
