/*
** card.c for  in /home/garrig_b/BLACKJACK
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Thu Aug 21 03:58:10 2014 a
** Last update Tue Aug 26 13:21:13 2014 a
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

int             my_carreau()
{
  write(1, "\n", 1);
  my_putstr("     _____\n");
  my_putstr("    |  ^  |\n");
  my_putstr("    | / \\ |\n");
  my_putstr("    | \\ / |\n");
  my_putstr("    |  .  |\n");
  my_putstr("    |_____|\n");
  write(1, "\n", 1);
}

int             my_pique()
{
  write(1, "\n", 1);
  my_putstr("     _____\n");
  my_putstr("    | _ _ |\n");
  my_putstr("    |( v )|\n");
  my_putstr("    | \\ / |\n");
  my_putstr("    |  .  |\n");
  my_putstr("    |_____|\n");
  write(1, "\n", 1);
}

int             my_coeur()
{
  write(1, "\n", 1);
  my_putstr("     _____\n");
  my_putstr("    |  .  |\n");
  my_putstr("    | /.\\ |\n");
  my_putstr("    |(_._)|\n");
  my_putstr("    |  |  |\n");
  my_putstr("    |_____|\n");
  write(1, "\n", 1);
}

int             my_trefle()
{
  write(1, "\n", 1);
  my_putstr("      _____\n");
  my_putstr("     |  _  |\n");
  my_putstr("     | ( ) |\n");
  my_putstr("     |(_'_)|\n");
  my_putstr("     |  |  |\n");
  my_putstr("     |_____|\n");
  write(1, "\n", 1);
}

int	which_card(int random)
{
  int	tmp;
  char  *c;

  c = malloc ((SIZE) * sizeof (char));
  if (card[random] != -1)
    {
      my_card(random);
      tmp = card[random];
      my_analyse(tmp);
      card[random] = -1;
      if (tmp == 1)
	{
	  my_putstr(" do you want a 11, y or n :");
	  READ
	    FAILED;
	  if (c[0] == 'y')
	    return (11);
	}
      return (tmp);
    }
  if (card[random] == -1)
    which_card(RANDOM);
}
