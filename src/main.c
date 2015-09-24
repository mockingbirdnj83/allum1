/*
** main.c for main in /home/aubess_t/work/semestre2/allum1/src
**
** Made by au
** Login   <aubess_t@epitech.net>
**
** Started on  Thu Feb 13 00:39:33 2014 au
** Last update Fri Feb 28 16:31:42 2014 au
*/

#include "allum1.h"

void	play_human(t_game *game, t_var *board)
{
  int	line;
  int	nb;

  my_printf("\n\n\n\t\033[4;32mPlayer %d's turn :\n", game->player + 1);
  my_printf("\n\033[0m\033[1;32m Which line ?");
  line = my_get_entry();
  while (line > board->nb_line)
    {
      my_printf("\033[1;31m Wrong match. Press 1 or 2.\033[0m");
      my_printf("\n Which line ?");
      line = my_get_entry();
    }
  my_printf("\n How many ?");
  nb = my_get_entry();
  while (nb > board->tab[line - 1])
    {
      my_printf("\033[1;31m Wrong match. Press 1 or 2.\033[0m");
      my_printf("\n How many ?");
      nb = my_get_entry();
    }
  board->total_allum -= nb;
  board->tab[line - 1] -= nb;
  my_printf("\033[0m");
}

void	play_computer(t_game *game, t_var *board)
{
  my_printf("\n\n\n\t\033[4;32mComputer's turn.\n\n\n\n\n");
  my_printf("\033[0m");
  my_usleep(5);
  check_nb_lines(board);
}

void	versus(t_game *game, t_var *board, int halfs)
{
  int	meter;

  meter = 0;
  while (board->total_allum)
    {
      my_printf("\033[H\033[2J");
      logo(board, halfs);
      if (0 == meter++)
	aff_board(*board, 1);
      else
	aff_board(*board, 2);
      if (game->player == 0)
	play_human(game, board);
      else
	{
	  if (game->nb_player == 1)
	    play_computer(game, board);
	  else
	    play_human(game, board);
	}
      game->player = 1 - game->player;
    }
  my_printf("\033[H\033[2J");
  logo(board, halfs);
  aff_board(*board, 2);
}

int	ask_replay(int replay)
{
  my_printf("\n\n\033[1;36mDo you want to replay ? ");
  my_printf(" Press 1 (Yes) or 2 (No).\n\033[8m");
  replay = my_get_entry();
  my_printf("\033[0m");
  return (replay);
}

int		main(int argc, char **argv)
{
  t_var		board;
  t_game	game;
  int		replay;
  int		halfs;

  replay = 1;
  halfs = 0;
  my_malloc_init();
  while (replay == 1)
    {
      init_game(&game);
      if (argv[1])
	init_board(&board, argv[1]);
      else
	init_board(&board, NULL);
      my_printf("\033[H\033[2J");
      logo(&board, halfs);
      select_nb_player(&game, &board, halfs);
      board.total_allum = calc_total_allum(board);
      versus(&game, &board, halfs);
      my_aff_winner(game.player + 1);
      replay = ask_replay(replay);
      halfs++;
    }
  my_free(board.tab);
}
