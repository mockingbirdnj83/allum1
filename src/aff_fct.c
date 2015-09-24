/*
** aff_fct.c for aff_fct in /home/aubess_t/work/semestre2/allum1/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Thu Feb 13 19:14:09 2014 au
** Last update Sun Feb 16 02:51:50 2014 au
*/

#include "allum1.h"

void	aff_tab(int *tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    my_printf("%d\n", tab[i++]);
}

void	print_space_allum(t_var *board, int flag, int j)
{
  int	i;

  my_printf("\033[1;32m");
  if (flag == 1)
    {
      i = 0;
      while (i++ <= board->nb_space)
	my_printf(" ");
    }
  else if (flag == 2)
    {
      i = 1;
      while (i++ <= board->tab[j])
	my_printf("|");
    }
}

void	print_numbers(t_var *board, int j, int decay)
{ 
  my_printf("\n  %d)", j + 1);
  if (decay == 2)
    my_printf(" ");
  else if (decay == 3)
    my_printf("  ");
  my_printf(" [");
  if (!board->tab[j])
    my_printf("XX");
  else if (board->tab[j] > 0 && board->tab[j] < 10)
    my_printf("00");
  else if (board->tab[j] > 9 && board->tab[j] < 100)
    my_printf("0");
  if (!board->tab[j])
    my_printf("X]");
  else
    my_printf("%d]", board->tab[j]);
}

void	aff_board(t_var board, int flags)
{
  int	i;
  int	j;
  int	decay;

  j = -1;
  decay = 3;
  board.nb_space++;
  my_printf("\033[1;32m");
  while (j++ < board.nb_line - 1)
    {
      if (!board.tab[j])
	my_printf("\033[0;31m");
      if (j == 9)
	decay = 2;
      else if (j == 100)
	decay = 1;
      print_numbers(&board, j, decay);
      print_space_allum(&board, 1, j);
      print_space_allum(&board, 2, j);
      board.nb_space--;
      if (flags == 1)
	my_usleep(1);
    }
}

void	my_aff_winner(int player)
{
  int	i;
  
  my_printf("\n\n\n");
  i = 0;
  my_printf("\t");
  while (i++ < 68)
    my_printf("*");
  my_printf("\n\t*\t\t\t\t\t\t\t\t   *\n");
  my_printf("\t*\t\t\t   Player %d won !\t\t\t   *\n", player);
  my_printf("\t*\t\t\t\t\t\t\t\t   *\n");
  i = 0;
  my_printf("\t");
  while (i++ < 68)
    my_printf("*");
  my_printf("\n\n");  
}
