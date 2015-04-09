/*
** aff.c for  in /home/garrig_b/KART/new
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Oct 26 11:41:43 2014 a
** Last update Sun Oct 26 21:20:09 2014 a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/mario.h"

void	my_analyse_char(int map, WINDOW *w)
{
  int	tmp;
  char	c;

  if (map == 2)
    waddstr(w, "%");
  if (map == 1)
    waddstr(w, "%");
  if (map == 0)
    waddstr(w, " ");
  if (map == 50)
    waddstr(w, "o");
  if (map == 51)
    waddstr(w, "A");
  if (map == 52)
    waddstr(w, "M");
  if (map < 0)
    {
      tmp = map;
      tmp *= -1;
      c = tmp;
      waddch(w, c | A_BOLD | A_UNDERLINE);
    }
}

void	wy_aff_map(int x, int y, WINDOW *w, int **map)
{
  int  	i;
  int  	a;

  i = 0;
  a = 0;
  while (i != x)
    {
      while (a != y)
        {
          my_analyse_char(map[i][a], w);
          a++;
        }
      waddstr(w, "\n");
      a = 0;
      i++;
    }
}

void            my_race()
{
  WINDOW	*score;
  WINDOW	*km;

  init_pair(2, COLOR_BLACK, COLOR_RED);
  init_pair(3, COLOR_WHITE, COLOR_BLUE);
  init_pair(4, COLOR_BLACK, COLOR_GREEN);
  km = subwin(stdscr, 3, 22, 4, 1);
  score = subwin(stdscr, 3, 22, 1, 1);
  bkgd(COLOR_PAIR(2));
  mvaddstr(0, 0, " [MARIO KART] RETARD EDITION ©");
  wbkgd(score, COLOR_PAIR(3));
  mvwprintw(score, 1, 1, "%s %d", "[SCORE]: ", g_compteur);
  wbkgd(km, COLOR_PAIR(4));
  mvwprintw(km, 1, 1, "%s%d%s", "[END OF RACE]: ", g_km, "KM");
  refresh();
  wrefresh(km);
  wrefresh(score);
}

void    init_all()
{

  srand(time(NULL));
  noecho();
  initscr();
  timeout(10000);
  cbreak();
  start_color();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
}
