/*
** move.c for  in /home/garrig_b/KART/new
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Oct 26 11:52:43 2014 a
** Last update Sun Oct 26 15:38:06 2014 a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

int             where_is_car(int *map, int y)
{
  int           i;

  i = 0;
  while (i != y)
    {
      if (map[++i] == 50)
        return (i);
    }
}

int             **my_right(int x, int y, int **map)
{
  int           tmp;

  tmp = where_is_car(map[x - 1], y);
  map[x - 1][tmp] = 0;
  map[x - 1][tmp + 1] = 50;
  map[x - 1][tmp + 2] = 51;
  map[x - 1][tmp + 3] = 50;
  map[x - 2][tmp] = 0;
  map[x - 2][tmp + 1] = 50;
  map[x - 2][tmp + 2] = 52;
  map[x - 2][tmp + 3] = 50;
  return (map);
}

int             **my_left(int x, int y, int **map)
{
  int           tmp;
  int           tmp2;

  tmp = where_is_car(map[x - 1], y);
  tmp +=2;
  tmp2 = tmp;
  map[x - 1][tmp] = 0;
  map[x - 1][--tmp] = 50;
  map[x - 1][--tmp] = 51;
  map[x - 1][--tmp] = 50;
  tmp = tmp2;
  map[x - 2][tmp] = 0;
  map[x - 2][--tmp] = 50;
  map[x - 2][--tmp] = 52;
  map[x - 2][--tmp] = 50;
  return (map);
}

void	my_analyse(int touch, int x, int y, int **map)
{
  if (touch == KEY_LEFT)
    map = my_left(x, y, map);
  if (touch == KEY_RIGHT)
    map = my_right(x, y, map);
}
