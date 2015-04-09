/*
** init.c for  in /home/garrig_b/KART/new
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Oct 26 11:49:01 2014 a
** Last update Sun Oct 26 11:52:09 2014 a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

void            init_map2(int x, int y, int **map)
{
  int           wall2;
  int           wall;
  int           tmp;
  int           i;
  int           a;

  i = 0;
  a = 0;
  tmp = ((y/2)/2);
  wall = y - tmp;
  wall2 = tmp;
  while (i != x)
    {
      map[i][wall] = 1;
      map[i][wall2] = 1;
      i++;
    }
}

void            init_map(int x, int y, int **map)
{
  int           i;
  int           a;
  int           tmp;

  tmp = y;
  i = 0;
  a = 0;
  while (i != x)
    {
      while (a != y)
        map[i][a++] = 0;
      a = 0;
      i++;
    }
  if (tmp % 2 != 0)
    ++tmp;
  tmp /=2;
  map[x-1][tmp] = 51;
  map[x-1][tmp + 1] = 50;
  map[x-1][tmp - 1] = 50;
  map[x - 2][tmp] = 52;
  map[x - 2][tmp - 1] = 50;
  map[x - 2][tmp + 1] = 50;
  init_map2(x, y, map);
}

