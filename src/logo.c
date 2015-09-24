/*
** logo.c for logo in /home/aubess_t/rendu/Allum1/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Feb 16 01:25:02 2014 au
** Last update Sun Feb 16 21:50:31 2014 au
*/

#include "allum1.h"

void	usage(t_var *board, int halfs)
{
  int	i;

  i = 0;
  my_printf("\033[0;36m\t");
  while (i++ < 68)
    my_printf("*");
  my_printf("\n");
  my_printf("\t* > TIPS :\t\t\t\t\t\t\t   *\n");
  my_printf("\t*\t\t\t\t\t\t\t\t   *\n");
  my_printf("\t*\tMatchsticks left : %d", board->total_allum);
  my_printf("\t\t\t\t           *\n");
  my_printf("\t*\tHalf(s) played : %d", halfs);
  my_printf("\t\t\t                   *\n\t*\t\t\t\t\t\t\t\t   *\n\t");
  i = 0;
  while (i++ < 68)
    my_printf("*");
  my_printf("\n\n\n");
  my_printf("\033[0m");
}

void	logo(t_var *board, int halfs)
{
  my_printf("\033[5;36m");
  my_printf("\n\n\n\n\n\t\t");
  my_printf("##########################################################\n");
  my_printf("\t\t#      |     |      |     |      |  |       |        |   #\n");
  my_printf("\t\t#     | |    |      |     |      |  ||     ||       ||   #\n");
  my_printf("\t\t#    |   |   |      |     |      |  | |   | |      | |   #\n");
  my_printf("\t\t#    |   |   |      |     |      |  |  | |  |     |  |   #\n");
  my_printf("\t\t#   |||||||  |      |     |      |  |   |   |        |   #\n");
  my_printf("\t\t#   |     |  |      |      |    |   |       |        |   #\n");
  my_printf("\t\t#   |     |  |      |       |  |    |       |        |   #\n");
  my_printf("\t\t#   |     |  |||||  |||||    ||     |       |  _     |   #\n");
  my_printf("\t\t##########################################################");
  my_printf("\n\n\n\n\n");
  my_printf("\033[0m");
  usage(board, halfs);
}
