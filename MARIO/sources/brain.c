/*
** brain.c for  in /home/garrig_b/KART/new/sources
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Oct 26 19:24:34 2014 a
** Last update Sun Oct 26 20:03:12 2014 a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

int             *my_putobstacle(int *map, int y)
{
  int	check[2];
  int	i;
  int	o;
  int	random;
  int	tmp;

  o = 0;
  i = 0;
  while (i != y)
    {
      if (map[i] == 1)
        check[o++] = i;
      i++;
    }
  random = check[1] - check[0];
  tmp = rand() % random;
  if (map[check[0] + tmp] != 1)
    map[check[0] + tmp] = -121;
  return (map);
}

int             my_modiff_map(int x, int y, int **map, WINDOW *window)
{
  if (g_random == 0)
    return ;
  if (g_random < 0)
    {
      map[0] = less_first_line(map[0], y);
      g_random++;
    }
  if (g_random > 0)
    {
      map[0] = plus_first_line(map[0], y);
      g_random--;
    }
  map[0] =  my_putobstacle(map[0], y);
  if (my_modiff_all_map(x, y, map, window) == -1)
    return (-1);
}
