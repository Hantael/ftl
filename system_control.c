/*
** system_control.c for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Wed Nov  9 10:58:23 2016 MORARD Marine
** Last update Wed Nov  9 18:45:53 2016 MORARD Marine
*/

#include "ftl.h"
#include "proto.h"

void	ftl_drive_system_check(t_ship *ship)
{
  my_putstr_color("cyan", "verification du reacteur en cours...\n");
  if (!my_strcmp(ship->ftl_drive->system_state, "online"))
    my_putstr_color("green", "reacteur OK!\n");
  else
    my_putstr_color("red", "reacteur hors service!\n");
}

void	navigation_tools_system_check(t_ship *ship)
{
  my_putstr_color("cyan", "verification du systeme de navigation en cours..");
  my_putstr_color("cyan", ".\n");
  if (!my_strcmp(ship->navigation_tools->system_state, "online"))
    my_putstr_color("green", "systeme de navigation OK!\n");
  else
    my_putstr_color("red", "systeme de navigation hors service!\n");
}

void	weapon_system_check(t_ship *ship)
{
  my_putstr_color("cyan", "verification du systeme d'armement en cours...\n");
  if (!my_strcmp(ship->weapon->system_state, "online"))
    my_putstr_color("green", "systeme d'armement OK!\n");
  else
    my_putstr_color("red", "systeme d'armement hors service!\n");
}

void	system_control(t_ship *ship)
{
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
}
