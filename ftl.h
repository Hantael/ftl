/*
** ftl.h for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Mon Nov  7 12:56:04 2016 MORARD Marine
** Last update Sat Nov 12 11:04:09 2016 MORARD Marine
*/

#ifndef _FTL_H_
# define _FTL_H_

typedef	struct		s_weapon
{
  char			*system_state;
  int			damage;
}			t_weapon;

typedef	struct		s_ftl_drive
{
  char			*system_state;
  int			energy;
}			t_ftl_drive;

typedef	struct		s_navigation_tools
{
  char			*system_state;
  int			sector;
  int			evade;
}			t_navigation_tools;

typedef	struct		s_freight
{
  char			*item;
  struct s_freight	*next;
  struct s_freight	*prev;
}			t_freight;

typedef	struct		s_container
{
  t_freight		*first;
  t_freight		*last;
  int			nb_elem;
}			t_container;

typedef	struct		s_ennemi
{
  int			pv;
  int			dmg;
  int			pv_max;
  int			dmg_max;
}			t_ennemi;

typedef	struct		s_ship
{
  int			hull;
  t_weapon		*weapon;
  t_ftl_drive		*ftl_drive;
  t_navigation_tools	*navigation_tools;
  t_container		*container;
  t_ennemi		*ennemi;
  int			sector_detect;
}			t_ship;

typedef	struct		s_repair_command
{
  char			*str;
  int			(*ptr)(t_ship *ship);
}			t_repair_command;

typedef struct		s_action
{
  char			*str;
  void			(*ptr)(t_ship *ship);
}			t_action;

#endif	/* !_FTL_H_ */
