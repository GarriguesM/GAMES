/*
** collision.c for  in /home/garrig_b/KART/new/sources
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Oct 26 19:16:23 2014 a
** Last update Sun Oct 26 21:53:02 2014 a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

int             my_clear(int *first, int y)
{
  int   i;

  i = 0;
  while (i != y)
    {
      if (first[i] < 0)
        first[i] = 0;
      if (first[i] == 2)
	first[i] = 0;
      i++;
    }
}

int	my_check_bonus(int *second, int *first, int  y)
{
  int	i;
  int	tmp;

  tmp = 0;
  i = 0;
  while (i != y)
    {
      if (first[i] == 50)
        tmp = i;
      i++;
    }
  tmp -= 1;
  if (first[tmp] != 51)
    {
      first[tmp] = 51;
      beep();
      g_compteur += 20;
    };
}

int	my_check_col(int *map, int y)
{
  int	i;
  int	check;

  i = 0;
  check = 0;
  while (i != y)
    {
      if (map[i] == 1)
        check++;
      i++;
    }
  return (check);
}

int	my_check_object(int *first, int y)
{
  int	check_f;

  check_f = my_seek_and_destroy(first, y, 50);
  if (first[check_f] == 2)
    return (-1);
}

int	my_collision(int *first, int *second, int y, WINDOW *window)
{
  if (my_check_col(first, y) != 2)
    {
      flash();
      return -1;
    }
  if (my_check_object(first, y) == -1)
    {
      flash();
      return -1;
    }
  my_check_bonus(second, first, y);
  my_clear(first, y);
}

