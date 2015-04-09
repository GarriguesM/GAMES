/*
** tools.c for  in /home/garrig_b/KART/me
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Fri Oct 24 20:50:54 2014 a
** Last update Sun Oct 26 20:03:35 2014 a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

void	my_aff_line(int *map, int y)
{
  int	i;

  i = 0;

  while (i != y)
    {
      my_putnbr(map[i++]);
    }
  write(1, "\n", 1);
}

void	my_aff_map(int x, int y, int **map)
{
  int           i;
  int           a;

  i = 0;
  a = 0;
  while (i != x)
    {
      while (a != y)
	  my_putnbr(map[i][a++]);
      write(1, "\n", 1);
      a = 0;
      i++;
    }
}

int	my_putnbr(int nb)
{
  int	o;

  if (nb < 0)
    {
      write(1, "-", 1);
      nb  *= -1;
    }
  o = nb % 10 + 48;
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  write(1, &o, 1);
}

int	my_getnbr(char *str)
{
  int	i;
  int	multi_str;
  int	somme;

  somme = 0;
  i = 0;
  multi_str = 1;
  while (str[i] >= '0' && str[i] <= '9')
    {
      multi_str = multi_str * 10;
      i = i + 1;
    }
  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      somme = somme + (str[i] - 48) * multi_str;
      multi_str = multi_str / 10;
      i = i + 1;
    }
  return (somme = somme /10);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
