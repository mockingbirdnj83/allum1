/*
** allum1.h for allum1 in /home/aubess_t/work/semestre2/allum1/src
** 
** Made by au
** Login   <aubess_t@epitech.net>
** 
** Started on  Thu Feb 13 19:16:09 2014 au
** Last update Sun Feb 16 03:05:58 2014 au
*/

#include "my_malloc.h"
#include "get_next_line.h"

#define GREEN		\033[1;32m
#define CYAN		\033[0;36m
#define CYAN_BRIGHT	\033[1;36m
#define WHITE		\033[0m
#define RED		\033[1;31m
#define GREY		\033[1;37m
#define HIDDEN		\033[8m

typedef struct	s_var
{
  int	nb_line;
  int	*tab;
  int	raison_allum;
  int	nb_allum_max;
  int	nb_space;
  int	total_allum;
}		t_var;

typedef struct s_game
{
  int	nb_player;
  int	versus;
  int	player;
  int	*mul;
}		t_game;

int *get_filled_lines_id(t_var *board, int nb_no_empty);
