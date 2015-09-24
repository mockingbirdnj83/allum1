/*
** init_fct.c for init_fct in /home/aubess_t/work/semestre2/allum1/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Thu Feb 13 19:17:12 2014 au
** Last update Sun Feb 16 22:28:09 2014 au
*/

#include "allum1.h"

int	calc_total_allum(t_var board)
{
  int	i;

  board.total_allum = 0;
  i = 0;
  while (i < board.nb_line)
    board.total_allum += board.tab[i++];
  return (board.total_allum);
}

int	create_tab(t_var *board)
{
  int	i;
  int	nb_allum;

  nb_allum = 1;
  if (!(board->tab = my_malloc(sizeof(int) * board->nb_line)))
    return (1);
  i = 0;
  while (i < board->nb_line)
    {
      board->tab[i++] = nb_allum;
      nb_allum += board->raison_allum;
    }
  return (0);
}

int	init_board(t_var *board, char *argv)
{
  if (argv)
    board->nb_line = my_atoi(argv);
  else
    board->nb_line = 2;
  board->raison_allum = 2;
  board->nb_allum_max = 1 + board->raison_allum * (board->nb_line - 1);
  board->nb_space = (board->nb_allum_max - 1) / 2;
  if (board->nb_line > 10)
    board->nb_space++;
  board->total_allum = 0;
  if (create_tab(board) != 0)
    return (1);
  return (0);
}

void	init_game(t_game *game)
{
  game->nb_player = 0;
  game->versus = 0;
  game->player = 0;
}
