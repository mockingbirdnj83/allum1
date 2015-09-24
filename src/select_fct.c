/*
** select_fct.c for select_fct in /home/aubess_t/work/semestre2/allum1/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Thu Feb 13 19:18:16 2014 au
** Last update Sun Feb 16 22:46:14 2014 au
*/

#include "allum1.h"

int	my_is_num(char *str)
{
  while (*str)
    {
      if (*str < 48 && *str > 57)
	return (1);
      str++;
    }
  return (0);
}

int	my_check_menu(char *str)
{
  if (*str == 'p')
    return (112);
  else if (*str == 'n')
    return (110);
  else
    return (1);
}

int	my_check_got(char *got)
{
  int	menu;
  
  if (my_is_num(got) != 0)
    {
      if (my_strlen(got) == 1)
	{
	  if ((menu = my_check_menu(got)) != 1)
	    return (menu);
	  else
	    return (1);
	}
      else
	return (1);
    }
  return (0);
}

int	my_get_entry()
{
  char	*got;
  int	i_got;
  int	check;

  got = get_next_line(0);
  
  if ((check = my_check_got(got)) == 1)
    i_got == -2;
  else if (check > 1)
    i_got == check;
  else
    i_got = my_atoi(got);
  my_free(got);
  return(i_got);
}

int	select_nb_player(t_game *game, t_var *board, int halfs)
{
  int	got;
  int	i;

  i = 0;
  my_printf("\033[H\033[2J");
  logo(board, halfs);
  my_printf("\033[1;32m\tMODE\n\n > 1. Solo\n > 2. Multiplayer\n\n");
  my_printf("\033[8m");
  if ((game->nb_player = my_get_entry()) == -1)
    return (1);
  my_printf("\033[0m");
  if (game->nb_player == 112)
    {
      my_printf("h");
      select_nb_player(game, board, halfs);
    }
  while ((game->nb_player != 1) && (game->nb_player != 2))
    {
      if (i++ > 100)
	exit(0);
      my_printf("\033[1;31mWrong match. Press 1 or 2. ");
      my_printf("\033[8m");
      game->nb_player = my_get_entry();
      my_printf("\033[0;m");
    }
}
