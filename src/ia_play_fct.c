/*
** ia_play_fct.c for ia_play_fct in /home/aubess_t/work/semestre2/allum1/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Sat Feb 15 14:20:36 2014 au
** Last update Sun Feb 16 00:42:36 2014 au
*/

#include "allum1.h"

/*
**
** | | | | ...   ==>   | x x x ...
**
*/
void	play_1(t_var *board, int *no_empty, int nb_no_empty)
{
  int	i = 0;

  board->total_allum -= (board->tab[no_empty[0]] - 1);
  board->tab[no_empty[0]] -= (board->tab[no_empty[0]] - 1);
}

/*
**   |                 |
** | | | ...   ==>   x x x ...
**
*/
void	play_2(t_var *board, int *no_empty, int result, int nb_no_empty)
{
  int	i = 0;

  if (result == 1)
    {
      board->total_allum -= board->tab[no_empty[1]];
      board->tab[no_empty[1]] = 0;
    }
  else if (result == 2)
    {
      board->total_allum -= board->tab[no_empty[0]];
      board->tab[no_empty[0]] = 0;
    }
}

/*
**   | |	        | |
** | | | | ...   =>   | | x x ...
**
*/
void	play_3(t_var *board, int *no_empty, int result, int nb_no_empty)
{
  int	i = 0;

  if (result == 1)
    {
      board->total_allum -= (board->tab[no_empty[1]] - 2);
      board->tab[no_empty[1]] = 2;
    }
  else if (result == 2)
    {
      board->total_allum -= (board->tab[no_empty[0]] - 2);
      board->tab[no_empty[0]] = 2;
    }
}

/*
**
**     | |                   | |
**   | |                   | |
** | | | | | ...   ==>   x x x x x ...
**
*/
void	play_4(t_var *board, int *no_empty, int result, int nb_no_empty)
{
  int	i = 0;

  if (result == 10)
    {
      board->total_allum -= board->tab[no_empty[2]];
      board->tab[no_empty[2]] = 0;
    }
  else if (result == 20)
    {
      board->total_allum -= board->tab[no_empty[1]];
      board->tab[no_empty[1]] = 0;
    }
  else if (result == 21)
    {
      board->total_allum -= board->tab[no_empty[0]];
      board->tab[no_empty[0]] = 0;
    }
}

void	play_5(t_var *board, int *no_empty, int nb_no_empty)
{
  int	i;

  i = 0;
  while (i < nb_no_empty && (board->tab[no_empty[i]] < 3))
    i++;      
  board->total_allum -= (board->tab[no_empty[i]] - 2);
  board->tab[no_empty[i]] = 2;
}

void	play_6(t_var *board, int *no_empty, int nb_no_empty)
{
  int	i = 0;

  board->total_allum -= 1;
  board->tab[no_empty[0]] -= 1;
}
