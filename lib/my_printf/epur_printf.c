/*
** epur_printf.c for epur_printf in /home/aubess_t/rendu/PSU_2013_my_printf
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Nov 16 15:23:58 2013 au
** Last update Sun Feb 16 02:01:11 2014 au
*/

#include <stdlib.h>

void	epur_sign()
{

}

void	epur_space(char *ptr2, char *dest)
{
  my_strcat(dest, " ");
  my_strcat(dest, ptr2);
}

int	get_pointer(char *ptr, char *ptr2, char *flags_str)
{
  while (*ptr)
    {
       while (*flags_str != '+' && *ptr != *flags_str)
	flags_str = flags_str + 1;
      if (*ptr == *flags_str)
	{
	  ptr2 = ptr;
	  break;
	}
      ptr = ptr + 1;
    }
   if (*ptr == 0)
      return (3);
}

/*
** 0 = Que des espaces
** 1 = +
** 2 = ni espace, ni + : autre caractere donc la chaine est traitee comme si il ny avait pas de pourcentage
** 3 = Pas de flag dans la chaine, traitee comme si il ny avait pas de pourcentage
*/
int	detect_sign(char *fmt, char *ptr2, char *flags_str)
{
  char *ptr;

  if (3 == get_pointer(fmt, ptr2, flags_str))
    {
      return (3);
          }
  else
    {
      ptr = fmt;
      while (*ptr != *ptr2)
	{
	  if (*ptr != ' ')
	    {
	      if(*ptr == '+')
		return (1);
	      else
		return (2);
	    }
	  ptr = ptr + 1;
	}
      if (*ptr == *ptr2)
	return(0);
    }
}

char	*epur_printf(char *fmt, char *flags_str)
{
  char	*dest;
  char	*ptr2;

  dest = malloc(sizeof(char) * my_strlen(fmt));
  while (*fmt)
    {
      if (*fmt == '%' && *(fmt + 1) != '%')
	{
	  my_strcat(dest, "%");
	  fmt = fmt + 1;
	  if (0 == detect_sign(fmt, ptr2, flags_str))
	    epur_space(ptr2, dest);
	  else if (1 == detect_sign(fmt, ptr2, flags_str))
	    epur_sign();
	  fmt = ptr2;
	}
      else
	my_strcat(dest, fmt);
      fmt = fmt + 1;
    }
  return (dest);
}
