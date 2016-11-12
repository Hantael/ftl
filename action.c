/*
** action.c for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Fri Nov 11 12:47:41 2016 MORARD Marine
** Last update Sat Nov 12 12:41:59 2016 MORARD Marine
*/

#include <stdlib.h>
#include "ftl.h"
#include "proto.h"

static const t_action g_action[] =
  {
    {"attack", attack},
    {"detect", detect},
    {"jump", jump},
    {"getbonus", get_bonus},
    {"stat", stat},
    {"controlsystem", system_control},
    {"help", help},
    {"detect", detect},
    {NULL, NULL}
  };

void	ennemi_stat(t_ship *ship)
{
  if (ship->ennemi->pv_max == 0)
    {
      ship->ennemi->pv_max = 20;
      ship->ennemi->dmg_max = 10;
    }
  else
    {
      ship->ennemi->pv_max += ship->ennemi->pv_max / 2;
      ship->ennemi->dmg_max += ship->ennemi->dmg_max / 2;
    }
  ship->ennemi->pv = ship->ennemi->pv_max;
  ship->ennemi->dmg = ship->ennemi->dmg_max;
}

void	jump(t_ship *ship)
{
  if (ship->ennemi->pv)
    my_putstr_color("red", "Ennemi a priximite, vous ne pouvez pas jump.\n");
  else if (!ship->ftl_drive->energy)
    my_putstr_color("red", "Vous n'avez pas assez d'energie.\n");
  else if (my_strcmp(ship->navigation_tools->system_state, "online"))
    my_putstr_color("red", "Systeme de navigation HS.\n");
  else
    {
      ship->navigation_tools->sector++;
      if (ship->navigation_tools->sector >= 10)
	{
	  my_putstr_color("green", "Vous avez gagné!\n");
	  return ;
	}
      my_putstr("Vous entrez dans le secteur : ");
      my_put_nbr(ship->navigation_tools->sector);
      if (alea(1, 10) <= 2)
	{
	  my_putstr_color("red", "\nVous rencontrez un ennemi!\n");
	  ennemi_stat(ship);
	}
      else
	my_putstr("\nLa voie est libre!\n");
    }
}

void	attack(t_ship *ship)
{
  if (ship->ennemi->pv <= 0)
    my_putstr_color("red", "[SYSTEM FAILURE] : pas d'ennemis à proximité");
  else if (!my_strcmp(ship->weapon->system_state, "online"))
    {
      if (ship->weapon->damage >= ship->ennemi->pv)
	{
	  ship->ennemi->pv = 0;
	  my_putstr_color("green", "Votre ennemi est mort");
	}
      else
	ship->ennemi->pv -= ship->weapon->damage;
      if ((alea(0, 9) % 2) == 0)
	{
	  my_putstr("\nVous perdez 1 d'energie, il ne vous en reste plus que ");
	  my_put_nbr(ship->ftl_drive->energy-- - 1);
	}
    }
  else
    my_putstr_color("red", "Vos armes sont endommagees");
  my_putchar('\n');
}

void		detect(t_ship *ship)
{
  t_freight	*freight;
  int		ran;
  int		i;

  i = 0;
  if (ship->sector_detect == ship->navigation_tools->sector)
    {
      my_putstr_color("red", "[NAVIGATION SYSTEM]: detect déjà effectué\n");
      return ;
    }
  ship->sector_detect = ship->navigation_tools->sector;
  while (i++ != 10)
    {
      if (!(freight = malloc(sizeof(t_freight))))
	return ;
      if (((ran = alea(1, 100)) == 0) || alea(1, 10) > 2)
	freight->item = "fret";
      else if (ran <= 33)
	freight->item = "energy";
      else if (ran <= 66)
	freight->item = "attackbonus";
      else
	freight->item = "evadebonus";
      add_freight_to_container(ship, freight);
    }
}

int	action(t_ship *ship)
{
  char	*act;
  int	i;

  i = 0;
  my_putstr_color("cyan", "\n$>");
  if (!(act = readline()))
    {
      my_putstr_color("red", "[ACTION FAILURE] : commande bloquee\n");
      return (0);
    }
  while (g_action[i].str)
    {
      if (!my_strcmp(act, "repairsystem") || !my_strcmp(g_action[i].str, act))
	{
	  if (!my_strcmp(act, "repairsystem"))
	    system_repair(ship);
	  else
	    g_action[i].ptr(ship);
	  return (1);
	}
      i++;
    }
  my_putstr_color("red", "[ACTION FAILURE] : commande inconnue\n");
  return (0);
}
