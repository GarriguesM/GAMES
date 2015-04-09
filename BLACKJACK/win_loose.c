/*
** win_loose.c for  in /home/garrig_b/BLACKJACK
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Thu Aug 21 23:28:33 2014 a
** Last update Mon Aug 25 01:58:27 2014 a
*/

#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <termcap.h>
#include <ncurses/curses.h>
#include <term.h>
#include "blackjack.h"


int	my_int(int i)
{
  write(1, &i, 1);
}

void	get_out()
{
  my_putstr("\033[31;1m");
  my_putstr("GET OUT !!\n");
  my_putstr("\033[00m");
  exit(0);
}

int	looseur_dealer(t_dude *dude)
{
  my_putstr("\n dealer had lost");
  dude->jetons = (dude->jetons * 2);
  dude->total = 0;
  return (dude->jetons);
}

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

void	choice_casino()
{
  my_putstr("mise X2 = x\nquit    = q \n");
  my_putstr("fall    = f\nnothing = ENTER\n");
  my_putstr("card    = c\n");
}
