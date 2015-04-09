/*
** random2.c for  in /home/garrig_b/KART/new/sources
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Oct 26 21:40:47 2014 a
** Last update Sun Oct 26 21:47:36 2014 a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

int	my_check_wall(int *map, int y, int random)
{
  int	check;
  int	i;

  i = y;
  while (i != 0)
    {
      if (map[i] == 1)
	check = i;
      i--;
    }
  if (check - random < 0)
    return (-1);
  return (0);
}
