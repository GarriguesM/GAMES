/*
** blackjack.h for  in /home/garrig_b/BLACKJACK
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sat Aug 16 21:28:43 2014 a
** Last update Tue Sep 30 14:00:26 2014 a
*/

#ifndef _BJ_
#define _BJ_
#include <unistd.h>
#include <stdlib.h>
#include <termcap.h>
#include <ncurses/curses.h>
#include <term.h>
#include <termios.h>

#define CLEAR "cl"
#define SIZE 70
#define READ if (read(1, c, SIZE) < 1)
#define FAILED exit(write(1, "READ FAILED", 11))
#define GAME_IS_STARTED 1
#define RANDOM rand() % 52

extern int card[];

extern int second_card[];

typedef struct s_dude
{
  int		jetons;
  int		card;
  int		total;
  int           mise;
  char		*str;
}               t_dude;

int		my_int(int i);
int		game_is_started(t_dude *dude, int taille, int dealer);
void		brain(t_dude *dude);
char		*name(char *str);
int		which_card(int random);
int		my_trefle();
int		my_coeur();
int		my_pique();
int		my_carreau();
int		which_card_dealer(int random);
void		size_win(int taille);
int		analyse_rep(char *str, t_dude *dude);
int		dealer_card(int taille, int on_table, int dealer);
int		my_putstr(char *str);
int		my_putnbr(int nb);
int		my_strlen(char *str);
int		my_getnbr(char *str);
void		my_great_card(int random, int valet, int queen, int king);
void		my_analyse(int random);
void		my_card(int  card);
int		my_interface(int largeur);
int		looseur_dealer(t_dude *dude);
void		choice_casino();

#endif /* _BJ_ */
