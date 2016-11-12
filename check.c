/*
** check.c for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Fri Nov 11 17:27:28 2016 MORARD Marine
** Last update Sat Nov 12 09:07:29 2016 MORARD Marine
*/

#include "ftl.h"
#include "proto.h"

int	ftl_drive_check(t_ship *ship)
{
  if (!my_strcmp(ship->ftl_drive->system_state, "online"))
    return (1);
  return (0);
}

int	navigation_tools_check(t_ship *ship)
{
  if (!my_strcmp(ship->navigation_tools->system_state, "online"))
    return (1);
  return (0);
}

int	weapon_drive_check(t_ship *ship)
{
  if (!my_strcmp(ship->weapon->system_state, "online"))
    return (1);
  return (0);
}

int	check(t_ship *ship)
{
  int	sum;

  sum = weapon_drive_check(ship) + navigation_tools_check(ship);
  return (sum + ftl_drive_check(ship));
}

void	stat(t_ship *ship)
{
  my_putstr("space_ship statement:");
  my_putstr_color("yellow", "\n |  hull : ");
  my_put_nbr(ship->hull);
  my_putstr_color("yellow", "\n | damage : ");
  my_put_nbr(ship->weapon->damage);
  my_putstr_color("yellow", "\n | energy : ");
  my_put_nbr(ship->ftl_drive->energy);
  my_putstr_color("yellow", "\n | sector : ");
  my_put_nbr(ship->navigation_tools->sector);
  my_putstr_color("yellow", "\n | evade : ");
  my_put_nbr(ship->navigation_tools->evade);
  my_putchar('\n');
}
