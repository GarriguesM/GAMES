/*
** main.c for  in /home/garrig_b/BLACKJACK
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sat Aug 16 21:27:28 2014 a
** Last update Wed Jan  7 14:27:42 2015 Melchior GARRIGUES
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

char	*name(char *str)
{
  char	*c;

  my_putstr(str);
  c = malloc ((SIZE) * sizeof (char));
  READ
    FAILED;
  if (c[0] == 'q' || c[0] == 'Q')
    exit(write(1, "\nGO HOME\n", 9));
  return (c);
}

void	brain(t_dude *dude)
{
  char	*player;

  my_putstr(dude->str);
  my_putstr("you have ");
  my_putnbr(dude->jetons);
  my_putstr(" jetons");
  my_putstr("\nhow many jetons you put on table :");
  dude->mise = my_getnbr(name(""));
}

int	final_decision(t_dude *dude, int dealer)
{
  if (dealer == 21 && dude->total != 21)
    {
      my_putstr("\nyou loose\n");
      return ( dude->jetons = dude->jetons - dude->mise);
    }
  if (dude->total > 21)
    {
      dude->jetons = dude->jetons - dude->mise;
      dude->total = 0;
      my_putstr("\nyou loose\n");
    }
  else  if (dealer > 21)
    return (looseur_dealer(dude));
  else  if (dealer < dude->total)
    {
      my_putstr("\nyou won\n");
      return (dude->jetons += (dude->mise * 2));
    }
  else if (dealer > dude->total)
    {
      my_putstr("\nyou loose\n");
      return (dude->jetons = dude->jetons - dude->mise);
    }
  return (dude->jetons);
}

int	game_is_started(t_dude *dude, int taille, int dealer)
{
  tputs(tgetstr("cl", NULL), 1, my_int);
  dealer = 0;
  my_interface(taille);
  brain(dude);
  dude->card =  which_card(RANDOM);
  dude->total = dude->card;
  dude->card =  which_card(RANDOM);
  dude->total += dude->card;
  my_putnbr(dude->total);
  dealer = dealer_card(taille, dude->mise, dealer);
  choice_casino();
  analyse_rep(name(""), dude);
  my_putstr("\ntotal: ");
  my_putnbr(dude->total);
  dealer += which_card_dealer(RANDOM);
  dealer = dealer_card(taille, dude->mise, dealer);
  if (dude->total == 21)
      dude->jetons += (dude->mise * 2);
  else
    if (final_decision(dude, dealer) < 0)
      return (-1);
  name("\nPRESS ENTER FOR NEXT PARTY OR Q FOR QUIT\n");
}

int			main()
{
  int			fd;
  struct winsize	*ws;
  t_dude		dude;
  char			term[1024];

  srand (time(NULL));

  tgetent(term, getenv("TERM"));

  if (ioctl(fd, TIOCGWINSZ, ws) < 0)
    exit(write(1, "FAILED\n", 6));
  dude.str = name("whats your name :");
  dude.jetons = 10;
  dude.card = 0;
  dude.total = 0;
  while (GAME_IS_STARTED)
    {
      if (game_is_started(&dude, ws->ws_col, 0) <= 0)
        get_out();
      check_card();
      write(1, "\n", 1);
    }
  return (0);
}
