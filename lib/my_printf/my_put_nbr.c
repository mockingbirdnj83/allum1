/*
** my_put_nbr.c for my_putnbr in /home/aubess_t/work/oxo/utils
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Jan 25 10:49:12 2014 au
** Last update Sat Jan 25 10:49:21 2014 au
*/

int	my_putnbr(int nb)
{
  int	output;

  output = 0;
  if (nb == -2147483648)
    {
      output = output + my_putstr("-2147483648");
      return (output);;
    }
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
      output = output + 1;
    }
  if (nb > 9)
    output = output + my_putnbr(nb / 10);
  output = output + my_putchar(nb % 10 + 48);
  return (output);
}
