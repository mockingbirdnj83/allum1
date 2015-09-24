/*
** ia.c for ia_fct in /home/aubess_t/work/semestre2/allum1/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Fri Feb 14 01:22:14 2014 au
** Last update Sun Feb 16 12:45:20 2014 au
*/

#include "allum1.h"

void	check_2_lines(t_var *board, int *no_empty, int nb_no_empty)
{
  int	res1;
  int	res2;

  res1 = one_of_two_is_one(board, no_empty);
  res2 = one_of_two_is_two(board, no_empty);
  if (res1  == 1 || res1 == 2)
    play_2(board, no_empty, res1);
  else if (res2 == 1 || res2  == 2)
    play_3(board, no_empty, res2);
  else
    play_6(board, no_empty);
}

void	check_3_lines(t_var *board, int *no_empty, int nb_no_empty)
{
  int	res;

  res = two_of_three_is_two(board, no_empty, nb_no_empty);
  if (res != 0)
    play_4(board, no_empty, res);
  else
    play_6(board, no_empty, nb_no_empty);
}

void	check_else(t_var *board, int *no_empty, int nb_no_empty)
{
  int	res;

  res = one_of_all_is_three(board, no_empty, nb_no_empty);
  if (res != -1)
    play_5(board, no_empty, nb_no_empty);
  else
    play_6(board, no_empty);
}

int	check_nb_lines(t_var *board)
{
  int	nb_no_empty;
  int	res;
  int	*no_empty;

  nb_no_empty = count_not_empty_lines(board);
  no_empty = get_filled_lines_id(board, nb_no_empty);
  if (board->total_allum == 1)
    play_6(board, no_empty);
  else if (nb_no_empty == 1)
    play_1(board, no_empty, nb_no_empty);
  else if (nb_no_empty == 2)
    check_2_lines(board, no_empty, nb_no_empty);
  else if (nb_no_empty == 3)
    check_3_lines(board, no_empty, nb_no_empty);
  else
    check_else(board, no_empty, nb_no_empty);
  my_free(no_empty);
}
