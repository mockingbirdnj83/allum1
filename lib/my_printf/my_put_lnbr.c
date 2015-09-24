/*
** my_put_lnbr.c for my_put_lnbr in /home/aubess_t/rendu/PSU_2013_my_printf
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Nov 17 23:40:05 2013 au
** Last update Sat Jan 25 10:52:30 2014 au
*/


int	my_put_lnbr(long nb)
{
  int	output;

  output = 0;
  if (nb == -2147483648)
    {
      output = output + my_putstr("-2147483648");
      return;
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
