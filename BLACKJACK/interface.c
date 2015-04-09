/*
** interface.c for  in /home/garrig_b/BLACKJACK
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Thu Aug 21 01:58:35 2014 a
** Last update Fri Aug 22 00:35:55 2014 a
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

void		my_great_card(int random, int valet, int queen, int king)
{
  if (random == valet)
    write(1, "J", 1);
  if (random == queen)
    write(1, "Q,", 1);
  if (random == king)
    write(1, "K", 1);
}

void		my_analyse(int random)
{
  my_putstr(" this is a ");
  if (random >= 0 && random <= 9)
    my_putnbr(random);
  if (random >= 10 && random <= 12)
    my_great_card(random, 10, 11, 12);
  if (random >= 13 && random <= 22)
    my_putnbr(random);
  if (random >= 23 &&  random <= 25)
    my_great_card(random, 23, 24, 25);
  if (random >= 26 && random <= 35)
    my_putnbr(random);
  if (random >= 36 && random <= 38)
    my_great_card(random, 36, 37, 38);
  if (random >= 39 && random <= 48)
    my_putnbr(random);
  if (random >= 49  && random <= 51)
    my_great_card(random, 49, 50, 51);
  write(1, "\n", 1);
}

void		my_card(int  card)
{
  if (card >= 0 && card <= 12)
    my_carreau();
  if (card >= 13 && card <= 25)
    my_pique();
  if (card >= 26 && card <= 38)
    my_coeur();
  if (card >= 39 && card <= 51)
    my_trefle();
}

int		my_interface(int largeur)
{
  int		i;

  i = 0;
  size_win(largeur);
  while (i != (largeur/2) - 6)
    {
      write(1, " ",  1);
      i++;
    }
  write(1, "CASINO", 6);
  write(1, "\n", 1);
  i = 0;
  while (i != largeur)
    {
      write(1, "-", 1);
      i++;
    }
  write(1, "\n", 1);
  return (3);
}
