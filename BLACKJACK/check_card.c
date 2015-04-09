/*
** check_card.c for  in /home/garrig_b/BLACKJACK
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Mon Aug 25 02:42:16 2014 a
** Last update Mon Aug 25 02:56:31 2014 a
*/

#include "blackjack.h"


void	my_replace()
{
  int i;

  i  = 0;
  while (i != 52)
    {
      card[i] = second_card[i];
      i++;
    }
}

void	check_card()
{
  int	check;
  int	i;

  check = 0;
  i  = 0;
  while (i != 52)
    {
      if (card[i] < 0)
	check++;
      i++;
    }
  if (check > 42)
    my_replace();
}
