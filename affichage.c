/*
** affichage.c for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Thu Nov 10 17:24:39 2016 MORARD Marine
** Last update Fri Nov 11 16:03:58 2016 MORARD Marine
*/

#include "ftl.h"
#include "proto.h"

int	divisor(int nb)
{
  int	div;

  div = 1;
  while (nb >= 10)
    {
      nb = nb / 10;
      div = div * 10;
    }
  return (div);
}

int	my_put_nbr(int nb)
{
  int	div;

  if (nb < -2147483647 || nb > 2147483647)
    {
      if (nb >= 0)
	my_putstr("2147483648");
      else
	my_putstr("-2147483648");
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  div = divisor(nb);
  while (div >= 1)
    {
      my_putchar((nb / div % 10) + 48);
      div = div / 10;
    }
  return (1);
}
