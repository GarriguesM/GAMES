/*
** test.c for  in /home/garrig_b/BLACKJACK
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Mon Aug 18 01:07:31 2014 a
** Last update Thu Aug 21 02:41:49 2014 a
*/

#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>
#include <ncurses/curses.h>
#include <term.h>


int main()
{
  char buf[1024];
  char buf2[30];
  char *ap = buf2;
  char *clearstr,
    *gotostr,
    *standstr,
    *stendstr, 
    *souligned;



  
  tgetent(buf, getenv("TERM"));
  souligned = tgetstr("us", &ap);
  clearstr = tgetstr("cl", &ap);
  gotostr = tgetstr("cm", &ap);
  standstr = tgetstr("so", &ap);
  stendstr = tgetstr("se", &ap);

  fputs(clearstr, stdout);


  fputs(tgoto(gotostr, 0, 5),      stdout);

  fputs( souligned, stdout);
  printf("Hello, ");
  fputs(standstr, stdout);

  printf("world");
  fputs(stendstr, stdout);
  putchar('!');
}
