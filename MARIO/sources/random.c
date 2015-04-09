/*
** random.c for  in /home/garrig_b/KART/new/sources
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Oct 26 14:10:18 2014 a
** Last update Sun Oct 26 22:08:35 2014 a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

int		*plus_first_line(int *map, int y)
{
  int		check[2];
  int		o;
  int		i;

  o = 0;
  i = 0;
  while (i != y)
    {
      if (map[i] == 1)
        check[o++] = i;
      i++;
    }
  map[check[0]] = 0;
  map[--check[0]] = 1;
  map[check[1]] = 0;
  map[++check[1]] = 1;
  return (map);
}

int		*less_first_line(int *map, int y)
{
  int		check[2];
  int		o;
  int		i;

  o = 0;
  i = 0;
  while (i != y)
    {
      if (map[i] == 1)
        check[o++] = i;
      i++;
    }
  map[check[0]] = 0;
  map[++check[0]] = 1;
  map[check[1]] = 0;
  map[--check[1]] = 1;
  return (map);
}

int		my_check_map2(int *map, int y)
{
  int		i;

  i = 0;
  while (i != y)
    {
      if (map[i] == 1)
        return (i);
      i++;
    }
}

int		my_check_map(int *map, int y)
{
  int           i;
  int           check[2];
  int           o;
  int           tmp;

  i = 0;
  o = 0;
  while (i != y)
    {
      if (map[i] == 1)
        check[o++] = i;
      i++;
    }
  tmp = check[1] - check[0];
  return (tmp);
}

int		my_check_rand(int random, int **map, int y)
{
  int		modif;

  modif = 1;
  if (g_compteur % 2 == 1)
    modif == -1;
  if (my_check_map(map[0], y) < 5)
    modif = 1;
  if (my_check_map(map[0], y) > 15)
    modif = -1;
  if (my_check_wall(map[0], random, y) == -1)
    modif = -1;
  random *= modif;
  return (random);
}
