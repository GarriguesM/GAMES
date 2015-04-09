/*
** object.c for  in /home/garrig_b/KART/new/includes
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Oct 26 21:26:56 2014 a
** Last update Sun Oct 26 21:56:02 2014 a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

int		*my_putobject(int *old, int *new, int y)
{
  int           i;
  int           o;

  o = 0;
  i = 0;
  while (i != y)
    {
      if (old[i] == 2)
        {
          old[i] = 0;
          o = i;
        }
      i++;
    }
  if ( o == 0)
    return (new);
  new[o] = 2;
  return (new);
}

int	my_seek_and_destroy(int *map, int y, int seek)
{
  int	i;

  i = 0;
  while (i != y)
    {
      if (map[i] == seek)
        return (i + 1);
      i++;
    }
}

int	my_put_object(int x, int y, int **map)
{
  int	i;

  i = my_seek_and_destroy(map[x - 2], y, 50);
  map[0][i] = 2;
}
