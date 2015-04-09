/*
** dealer.c for  in /home/garrig_b/BLACKJACK
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Thu Aug 21 21:14:15 2014 a
** Last update Mon Aug 25 01:49:57 2014 a
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

int	which_card_dealer(int random)
{
  int	tmp;

  tmp = 0;
  if (card[random] != -1)
    {
      tmp = card[random];
      card[random] = -1;
      return (tmp);
    }
  if (card[random] == -1)
    which_card_dealer(RANDOM);
}

void	size_win(int taille)
{
  int i;

  i = 0;
  while (i != taille)
    {
      write(1, "-", 1);
      i++;
    }
}

int	analyse_rep(char *str, t_dude *dude)
{

  if (str[0] == 'x')
    {
      dude->mise = (dude->mise * 2);
      dude->card = which_card(RANDOM);
      dude->total += dude->card;
    }
  if (str[0] == 'q')
    exit(0);
  if (str[0] == 'f')
    return (1);
  if (str[0] == 'c')
    {
      dude->card = which_card(RANDOM);
      dude->total += dude->card;
    }
}

int	dealer_card(int taille, int on_table, int dealer)
{
  int	i;

  i = 0;
  write(1, "\n\n", 2);
  size_win(taille);
  while (i != (taille / 2) - 20)
    {
      write(1, " ", 1);
      i++;
    }
  my_putstr("DEALER GOT : ");
  dealer += (which_card_dealer(RANDOM));
  my_putnbr(dealer);
  my_putstr("  ON TABLE : ");
  my_putnbr(on_table);
  write(1, "\n", 1);
  size_win(taille);
  return (dealer);
}
