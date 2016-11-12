/*
** proto.h for ftl in /home/hantael/rendu/C/ftl
**
** Made by MORARD Marine
** Login   <morard_m@etna-alternance.net>
**
** Started on  Mon Nov  7 15:02:53 2016 MORARD Marine
** Last update Sat Nov 12 12:54:55 2016 MORARD Marine
*/

#ifndef _PROTO_H_
# define _PROTO_H_

/*
** MY STRING
*/

void	my_putstr_color(const char *color, const char *str);
char	*my_strdup(const char *str);
int	my_strcmp(const char *s1, const char *s2);
void	my_putstr(const char *str);
void	my_putchar(const char c);

/*
** READLINE
*/

char	*readline(void);

/*
** AIR SHED
*/

t_ship  *create_ship();
int	add_weapon_to_ship(t_ship *ship);
int	add_navigation_tools_to_ship(t_ship *ship);
int	add_ftl_drive_to_ship(t_ship *ship);

/*
** CONTAINER
*/

int	add_container_to_ship(t_ship *ship);
void	add_freight_to_container(t_ship *ship, t_freight *freight);
void	del_freight_from_container(t_ship *ship, t_freight *freight);
void	get_bonus(t_ship *ship);

/*
** SYSTEM CONTROL
*/

void	ftl_drive_system_check(t_ship *ship);
void	navigation_tools_system_check(t_ship *ship);
void	weapon_system_check(t_ship *ship);
void	system_control(t_ship *ship);

/*
** SYSTEM REPAIR
*/

int	ftl_drive_system_repair(t_ship *ship);
int	navigation_tools_system_repair(t_ship *ship);
int	weapon_system_repair(t_ship *ship);
int	system_repair(t_ship *ship);

/*
** AFFICHAGE
*/

int	my_put_nbr(int nb);

/*
** GAME
*/

int	alea(int min, int max);
void	game(t_ship *ship);

/*
** ACTION
*/

void	ennemi_stat(t_ship *ship);
void	jump(t_ship *ship);
void	attack(t_ship *ship);
void	detect(t_ship *ship);
int	action(t_ship *ship);

/*
** CHECK
*/

int	ftl_drive_check(t_ship *ship);
int	navigation_tools_check(t_ship *ship);
int	weapon_drive_check(t_ship *ship);
int	check(t_ship *ship);
void	stat(t_ship *ship);

/*
** HELP
*/

void	help();
int	help_repair(t_ship *ship);

#endif /* !_PROTO_H_ */
