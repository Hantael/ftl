/*
** help.c for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Sat Nov 12 09:13:59 2016 MORARD Marine
** Last update Sat Nov 12 12:39:37 2016 MORARD Marine
*/

#include "ftl.h"
#include "proto.h"

void	help()
{
  my_putstr_color("cyan", "Commandes system disponible :\n");
  my_putstr("attack\ndetect\njump\ngetbonus\ncontrolsystem\nrepairsystem\n");
  my_putstr("stat\nhelp\n");
}

int	help_repair(t_ship *ship)
{
  (void)ship;
  my_putstr_color("cyan", "Commandes de réparations disponible :\n");
  my_putstr("ftl_drive\nnavigation_tools\nweapon\nhelp\n");
  return (1);
}
