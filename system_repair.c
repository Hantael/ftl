/*
** system_repair.c for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Wed Nov  9 12:29:53 2016 MORARD Marine
** Last update Sat Nov 12 12:32:08 2016 MORARD Marine
*/

#include <stdlib.h>
#include "ftl.h"
#include "proto.h"

static const t_repair_command	g_repair[] =
  {
    {"ftl_drive", ftl_drive_system_repair},
    {"navigation_tools", navigation_tools_system_repair},
    {"weapon", weapon_system_repair},
    {"help", help_repair},
    {NULL, NULL}
  };

int	ftl_drive_system_repair(t_ship *ship)
{
  free(ship->ftl_drive->system_state);
  my_putstr_color("cyan", "reparation du reacteur en cours...\n");
  if (!(ship->ftl_drive->system_state = my_strdup("online")))
    {
      my_putstr_color("red", "les reparations du reacteur ont echoue\n");
      return (0);
    }
  my_putstr_color("green", "reparation termine! systeme reacteur OK!\n");
  return (1);
}

int	navigation_tools_system_repair(t_ship *ship)
{
  free(ship->navigation_tools->system_state);
  my_putstr_color("cyan", "reparation du systeme de navigation en cours...\n");
  if (!(ship->navigation_tools->system_state = my_strdup("online")))
    {
      my_putstr_color("red", "les reparations des outils de navigations ont");
      my_putstr_color("red", "echoue\n");
      return (0);
    }
  my_putstr_color("green", "reparation termine! systeme de navigation OK!\n");
  return (1);
}

int	weapon_system_repair(t_ship *ship)
{
  free(ship->weapon->system_state);
  my_putstr_color("cyan", "reparation du systeme d'armement en cours...\n");
  if (!(ship->weapon->system_state = my_strdup("online")))
    {
      my_putstr_color("red", "les reparations du systeme d'armement ont ");
      my_putstr_color("red", "echoue\n");
      return (0);
    }
  my_putstr_color("green", "reparation termine! systeme d'armement OK!\n");
  return (1);
}

int	system_repair(t_ship *ship)
{
  char	*cmd;
  int	i;

  i = 0;
  my_putstr_color("cyan", "repair_system~>");
  if (!(cmd = readline()))
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : le lecteur de ");
      my_putstr_color("cyan", "commande est bloque\n");
      return (0);
    }
  while (g_repair[i].str)
    {
      if (!my_strcmp(g_repair[i].str, cmd))
	{
	  g_repair[i].ptr(ship);
	  return (1);
	}
      i++;
    }
  my_putstr_color("red", "[SYSTEM FAILURE] : commande inconnue\n");
  return (0);
}
