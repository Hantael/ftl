/*
** air_shed.c for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Mon Nov  7 13:00:46 2016 MORARD Marine
** Last update Sat Nov 12 12:42:40 2016 MORARD Marine
*/

#include <stdlib.h>
#include "ftl.h"
#include "proto.h"

int		add_weapon_to_ship(t_ship *ship)
{
  t_weapon	*tmp_weapon;

  tmp_weapon = NULL;
  my_putstr_color("cyan", "ajout des armes en cours...\n");
  if (!(tmp_weapon = malloc(sizeof(t_weapon))))
    {
      my_putstr_color("red", "votre vaisseau a explose quand vous");
      my_putstr_color("red", " avez tente d'ajouter les armes\n");
      return (0);
    }
  tmp_weapon->damage = 10;
  if (!(tmp_weapon->system_state = my_strdup("online")))
    {
      my_putstr_color("red", "votre vaisseau a explose quand vous");
      my_putstr_color("red", " avez tente d'ajouter les armes\n");
      return (0);
    }
  my_putstr_color("green", "les armes on ete ajoutes avec succes!\n");
  ship->weapon = tmp_weapon;
  return (1);
}

int		add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive	*drive;

  my_putstr_color("cyan", "ajout du reacteur en cours...\n");
  if (!(drive = malloc(sizeof(t_ftl_drive))))
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque vous");
      my_putstr_color("red", " avez pose le reacteur\n");
      return (0);
    }
  drive->energy = 10;
  if (!(drive->system_state = my_strdup("online")))
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque vous");
      my_putstr_color("red", " avez pose le reacteur\n");
      return (0);
    }
  ship->ftl_drive = drive;
  my_putstr_color("green", "le reacteur a ete ajoute avec succes!\n");
  return (1);
}

int			add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools	*nav;

  my_putstr_color("cyan", "ajout des outils de navigations...\n");
  if (!(nav = malloc(sizeof(t_navigation_tools))))
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque");
      my_putstr_color("red", " vous avez pose les outils de navigations\n");
      return (0);
    }
  nav->sector = 0;
  nav->evade = 25;
  if (!(nav->system_state = my_strdup("online")))
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque");
      my_putstr_color("red", " vous avez pose les outils de navigations\n");
      return (0);
    }
  ship->navigation_tools = nav;
  my_putstr_color("green", "les outils de navigations ont ete ajoutes");
  my_putstr_color("green", " avec succes!\n");
  return (1);
}

t_ship		*create_ship()
{
  t_ship	*ship;

  my_putstr_color("cyan", "construction du vaisseau en cours...\n");
  if (!(ship = malloc(sizeof(t_ship))))
    {
      my_putstr_color("red", "le vaisseau n'a pas pu etre construit");
      my_putstr_color("red", " par manque de materiaux\n");
      return (NULL);
    }
  my_putstr_color("green", "amelioration du vaisseau termine!\n");
  ship->hull = 50;
  ship->weapon = NULL;
  if (!add_weapon_to_ship(ship))
    return (0);
  ship->ftl_drive = NULL;
  if (!add_ftl_drive_to_ship(ship))
    return (0);
  if (!add_navigation_tools_to_ship(ship))
    return (0);
  if (!add_container_to_ship(ship))
    return (0);
  my_putchar('\n');
  return (ship);
}
