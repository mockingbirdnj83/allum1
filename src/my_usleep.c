/*
** my_usleeps.c for my_usleeps in /home/aubess_t/work/oxo/utils
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Fri Jan 24 19:28:47 2014 au
** Last update Sun Feb 16 02:41:09 2014 au
*/

void	my_usleep(int coeff)
{
  int	i;
  long	stop = coeff * 35000000;

  i = 0;
  while (i < stop)
    i++;
}
