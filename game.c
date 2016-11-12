/*
** game.c for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Thu Nov 10 17:15:28 2016 MORARD Marine
** Last update Sat Nov 12 11:53:13 2016 MORARD Marine
*/

#include <time.h>
#include <stdlib.h>
#include "ftl.h"
#include "proto.h"

int	alea(int min, int max)
{
  return (rand() % max + min);
}

void	dmg_sys(t_ship *ship)
{
  int	zone;

  if (!alea(1, 5))
    {
       if (!check(ship))
	return ;
      zone = alea(1, check(ship));
      if (!(zone))
	{
	  ship->ftl_drive->system_state = "ofline";
	  my_putstr_color("red", "reacteur hors service!\n");
	}
	if (zone == 2)
	  {
	    ship->navigation_tools->system_state = "ofline";
	    my_putstr_color("red", "systeme de navigation hors service!\n");
	  }
	else
	  {
	    ship->weapon->system_state = "ofline";
	    my_putstr_color("red", "systeme d'armement hors service!\n");
	  }
    }
}

void	atq_bot(t_ship *ship)
{
  if (ship->ennemi->pv > 0)
    {
      my_putstr_color("cyan", "[ENNEMY STATS] :\n");
      my_putstr(" | life : ");
      my_put_nbr(ship->ennemi->pv);
      my_putstr("\n | damage : ");
      my_put_nbr(ship->ennemi->dmg);
      if (alea(1, 100) < ship->navigation_tools->evade)
	my_putstr_color("green", "\nVous avez esquive le coups de votre ennemi\n");
      else
	{
	  my_putstr("\nVous avez prit un coup! Vos PV passent de ");
	  my_put_nbr(ship->hull);
	  my_putstr(" a ");
	  my_put_nbr(ship->hull -= ship->ennemi->dmg);
	  my_putchar('\n');
	  dmg_sys(ship);
	}
    }
}

void	game(t_ship *ship)
{
  srand(time(NULL));
  if (!(ship->ennemi = malloc(sizeof(t_ennemi))))
    return ;
  ship->ennemi->pv_max = 0;
  ship->ennemi->dmg_max = 0;
  ship->ennemi->pv = 0;
  ship->navigation_tools->sector = -1;
  ship->sector_detect = -1;
  jump(ship);
  while (ship->navigation_tools->sector <= 9)
    {
      atq_bot(ship);
      if (ship->hull <= 0 || ship->ftl_drive->energy <= 0)
	{
	  my_putstr_color("red", "\nVous avez perdu!\n");
	  return ;
	}
      action(ship);
    }
}
