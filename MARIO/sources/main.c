/*
** main.c for  in /home/garrig_b/KART/new
**
** Made by a
** Login   <garrig_b@epitech.net>
**
** Started on  Sat Oct 25 16:51:25 2014 a
** Last update Thu Apr  9 13:29:01 2015 melchior garrigues
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

int	g_km = 100;
int	g_compteur;
int	g_time = 10;
int	g_random;

int		*my_putobstacle2(int *old, int *new, int y)
{
  int		tmp;
  int		i;
  int		valeur;

  valeur = 0;
  i = 0;
  while (i != y)
    {
      if (old[i] < 0)
	{
	  valeur = old[i];
	  old[i] = 0;
	  tmp = i;
	}
      i++;
    }
  if (valeur == 0)
    return (new);
  valeur++;
  new[tmp] = valeur;
  return (new);
}

int		*my_swap_map(int *old, int *new, int y)
{
  int		check[2];
  int		i;
  int		o;

  o = 0;
  i = 0;
  while (i != y)
    {
      if (old[i] == 1)
	check[o++] = i;
      i++;
    }
  i = 0;
  while (i != y)
    {
      if (new[i] == 1)
	new[i] = 0;
      i++;
    }
  new[check[0]] = 1;
  new[check[1]] = 1;
  new = my_putobject(old, new, y);
  new = my_putobstacle2(old, new, y);
  return (new);
}

int		my_modiff_all_map(int x, int y, int **map, WINDOW *window)
{
  int		i;
  int		touch;

  i = 1;
  init_pair(1, COLOR_BLACK, COLOR_YELLOW);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  while (i != x)
    {
      touch = getch();
      my_analyse(touch, x, y, map);
      my_swap_map(map[i -1], map[i], y);
      napms(120);
      wclear(window);
     
      wy_aff_map(x, y, window, map);
      wbkgd(window, COLOR_PAIR(1));
      box(window, '#', '#');
      wrefresh(window);
      refresh();
      if (my_collision(map[x -1], map[x - 2], y, window) == -1)
	return (-1);
      i++;
    }
  if (my_check_bug(map[x - 1], map[x - 2], y) == -1)
    return (-1);
}

int		my_mario(int x, int y, int **map)
{
  WINDOW	*window;
  int		max_x;
  int		max_y;

  getmaxyx(stdscr, max_x, max_y);
  max_x -= x;
  max_y /= 2;
  max_y -= (y / 2);
  if ((window =  subwin(stdscr, x + 2, y + 2, max_x -2, max_y)) == NULL)
    return (-1);
  init_map(x, y, map);
  while (g_km-- != 0)
    {	my_put_object(x, y, map);
      if (g_time == 5)
        g_random = (my_check_rand(rand() % 5, map, y));
      if (g_time == 0)
	g_time = 10;
      if (g_time >= 5)
	if (my_modiff_map(x, y, map, window) == -1)
	  return (-1);
      my_race();
      g_compteur += 1;
      g_time--;
    }
}

int	main(int ac, char **av)
{
  int	**map;
  int	i;
  int	x;
  int	y;

  if (ac == 3)
    {
      x = my_getnbr(av[1]);
      y =  my_getnbr(av[2]);
      i  = 0;
      if  ((map = malloc(sizeof(int**) * x)) == NULL)
	return (-1);
      while (i != x)
	if ((map[i++] = malloc(sizeof(int**) * y)) == NULL)
	  return (-1);
      init_all();
      my_start();
    if (my_mario(x, y, map) == -1)
      return (my_end(0));
    }
  else
    return (write(2, "./bin x y\n", 10));
}
