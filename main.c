/*
** main.c for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Wed Nov  9 18:10:57 2016 MORARD Marine
** Last update Sat Nov 12 11:28:21 2016 MORARD Marine
*/

#include <stdlib.h>
#include "ftl.h"
#include "proto.h"

void	hello()
{
  my_putstr_color("clear", "\n");
  my_putstr("███╗   ███╗██╗   ██╗     ███████╗████████╗██╗\n");
  my_putstr("████╗ ████║╚██╗ ██╔╝     ██╔════╝╚══██╔══╝██║\n");
  my_putstr("██╔████╔██║ ╚████╔╝      █████╗     ██║   ██║\n");
  my_putstr("██║╚██╔╝██║  ╚██╔╝       ██╔══╝     ██║   ██║\n");
  my_putstr("██║ ╚═╝ ██║   ██║███████╗██║        ██║   ███████╗\n");
  my_putstr("╚═╝     ╚═╝   ╚═╝╚══════╝╚═╝        ╚═╝   ╚══════╝\n\n");
  my_putstr("███╗   ███╗ ██████╗ ██████╗  █████╗ ██████╗ ██████╗         ██");
  my_putstr("█╗   ███╗\n████╗ ████║██╔═══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗");
  my_putstr("        ████╗ ████║\n██╔████╔██║██║   ██║██████╔╝███████║██████╔");
  my_putstr("╝██║  ██║        ██╔████╔██║\n██║╚██╔╝██║██║   ██║██╔══██╗██╔══█");
  my_putstr("█║██╔══██╗██║  ██║        ██║╚██╔╝██║\n██║ ╚═╝ ██║╚██████╔╝██║  ");
  my_putstr("██║██║  ██║██║  ██║██████╔╝███████╗██║ ╚═╝ ██║\n╚═╝     ╚═╝ ╚═══");
  my_putstr("══╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝╚═╝     ╚═╝\n\n");
  my_putstr_color("red", "Vous pouvez à tout moment utiliser la commander ");
  my_putstr_color("red", "\"help\" pour connaitre la liste des commandes");
  my_putstr_color("red", " disponible.\n(Cependant vous ");
  my_putstr_color("red", "devez savoir que ca vous coutera une action :° )\n");
  my_putchar('\n');
}

int	main()
{
  t_ship	*ship;

  hello();
  if (!(ship = create_ship()))
    return (0);
  game(ship);
  return (0);
}
