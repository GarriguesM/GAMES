/*
** fonct.c for  in /home/garrig_b/BLACKJACK
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Aug 17 16:23:11 2014 a
** Last update Mon Aug 18 00:46:10 2014 a
*/

int     my_putstr(char *str)
{
  return (write(1, str, my_strlen(str)));
}

int     my_putnbr(int nb)
{
  int   o;

  o  = nb % 10 + 48;
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  write(1, &o, 1);
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while(str[i])
    i++;
  return (i);
}

int     my_getnbr(char *str)
{
  int   i;
  int   multi_str;
  int   somme;


  somme = 0;
  i = 0;
  multi_str = 1;
  while (str[i] >= '0' && str[i] <= '9')
    {
      multi_str = multi_str * 10;
      i = i + 1;
    }
  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      somme = somme + (str[i] - 48) * multi_str;
      multi_str = multi_str / 10;
      i = i + 1;
    }
  somme = somme /10;
}
