/*
** bug.c for  in /home/garrig_b/KART/new/sources
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Oct 26 22:15:42 2014 a
** Last update Sun Oct 26 22:24:24 2014 a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

int	my_check_bug(int  *first, int *second, int y)
{
  int	i;
  int	check;

  i = 0;
  check = 0;
  while (i != y)
    {
      if (first[i] > 50)
	check++;
      i++;
    }
  i = 0;
  while (i != y)
    {
      if (second[i] > 50)
	check++;
      i++;
    }
  if (check < 1)
    return (-1);
}
