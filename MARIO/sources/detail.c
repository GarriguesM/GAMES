/*
** detail.c for  in /home/garrig_b/KART/me
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sat Oct 25 03:52:49 2014 a
** Last update Sun Oct 26 22:10:00 2014 a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

void	tree()
{
  addstr(" #----------------#\n| #--------------# |\n");
  addstr("| |    ______    | |\n| |   / ____ `.  | |\n");
  addstr("| |   `~  __) |  | |\n| |   _  |__ T.  | |\n");
  addstr("| |  | \\____) |  | |\n| |   \\ _____./  | |\n");
  addstr("| |              | |\n| #--------------# |\n #----------------#\n");
  refresh();
  napms(1000);
  clear();
}

void	two()
{
  addstr(" #----------------#\n| #--------------# |\n");
  addstr("| |    _____     | |\n| |   / ___ `.   | |\n");
  addstr("| |  |_/___) |   | |\n| |   .'____.'   | |\n");
  addstr("| |  / /____     | |\n| |  |_______|   | |\n");
  addstr("| |              | |\n| #--------------# |\n");
  addstr(" #----------------#\n");
  refresh();
  napms(1000);
  clear();
}

void	my_one()
{
  addstr(" #----------------#\n");
  addstr("| #--------------# |\n");
  addstr("| |     __       | |\n");
  addstr("| |    /  |      | |\n");
  addstr("| |    `| |      | |\n");
  addstr("| |     | |      | |\n");
  addstr("| |    _| |_     | |\n");
  addstr("| |   |_____|    | |\n");
  addstr("| |              | |\n");
  addstr("| #--------------# |\n");
  addstr(" #----------------# \n");
  refresh();
  napms(1000);
  clear();
}

void		my_start()
{
  WINDOW	*one;
  int		x;
  int		y;

  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_BLACK, COLOR_YELLOW);
  init_pair(3, COLOR_WHITE, COLOR_RED);
  getmaxyx(stdscr, x, y);
  newwin(x, y, 2, 5);
  bkgd(COLOR_PAIR(1));
  tree();
  bkgd(COLOR_PAIR(2));
  two();
  bkgd(COLOR_PAIR(3));
  my_one();
  refresh();
  endwin();
}

int	my_end(int i)
{
  char	**end;
  int	max_x;
  int	max_y;

  if ((end = malloc(4 * sizeof(char *))) == NULL)
    return (-1);
  getmaxyx(stdscr, max_x, max_y);
  end[0] = "MARIO KART :";
  end[1] = "RETARD EDTION ";
  end[2] =  "©";
  end[3] = NULL;
  max_x /= 2;
  max_y /= 2;
  while (i != 3)
    {
      move(max_x--, max_y);
      insertln();
      addstr(end[i]);
      refresh();
      flash();
      sleep(3);
      i++;
    }
  endwin();
}
