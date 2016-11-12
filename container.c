/*
** container.c for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Tue Nov  8 09:09:22 2016 MORARD Marine
** Last update Sat Nov 12 12:43:05 2016 MORARD Marine
*/

#include <stdlib.h>
#include "ftl.h"
#include "proto.h"

void		get_bonus(t_ship *ship)
{
  t_freight	*tmp;

  my_putstr_color("cyan", "Recuperation des materiaux utiles en cours...\n");
  if (!ship->container->nb_elem || (!(tmp = malloc(sizeof(t_freight)))))
    {
      my_putstr_color("red", "Vous n'avez pas de matériaux\n");
      return ;
    }
  while (ship->container->first)
    {
      if (!my_strcmp(ship->container->first->item, "attackbonus"))
	ship->weapon->damage += 5;
      else if (!my_strcmp(ship->container->first->item, "evadebonus"))
	ship->navigation_tools->evade += 3;
      else if (!my_strcmp(ship->container->first->item, "energy"))
	ship->ftl_drive->energy += 1;
      tmp = ship->container->first;
      ship->container->first = ship->container->first->next;
      free(tmp);
    }
  ship->container->nb_elem = 0;
  ship->container->first = NULL;
  ship->container->last = NULL;
  my_putstr_color("green", "Materiaux utiles recuperes\n");
}

void	del_freight_from_container(t_ship *ship, t_freight *freight)
{
  if (!freight->next && !freight->prev)
    {
      ship->container->first = NULL;
      ship->container->last = NULL;
      free(freight);
    }
  else if (!freight->next)
    {
      ship->container->last = freight->prev;
      freight->prev->next = NULL;
      free(freight);
    }
  else if (!freight->prev)
    {
      ship->container->first = freight->next;
      freight->next->prev = NULL;
      free(freight);
    }
  else
    {
      freight->prev->next = freight->next;
      freight->next->prev = freight->prev;
    }
  ship->container->nb_elem--;
}

void	add_freight_to_container(t_ship *ship, t_freight *freight)
{
  my_putstr("[DETECTION SYSTEM] : cargaison de ");
  my_putstr(freight->item);
  my_putstr(" detecte\n");
  if (!ship->container->first && !ship->container->last)
    {
      freight->next = NULL;
      freight->prev = NULL;
      ship->container->first = freight;
      ship->container->last = freight;
    }
  else
    {
      ship->container->last->next = freight;
      freight->prev = ship->container->last;
      ship->container->last = freight;
      freight->next = NULL;
    }
  ship->container->nb_elem++;
}

int		add_container_to_ship(t_ship *ship)
{
  t_container	*container;

  my_putstr_color("cyan", "ajout du container en cours...\n");
  if (!(container = malloc(sizeof(t_container))))
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque vous ");
      my_putstr_color("red", "avez pose le container\n");
      return (0);
    }
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  ship->container = container;
  my_putstr_color("green", "le container a ete ajoute avec succes!\n");
  return (1);
}
