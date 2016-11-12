/*
** Ce fichier contient les fonctions de bases pour gérer des strings (les chaines de caractères).
**
** my_putchar vous permet d'afficher un caractère sour la sortie standard.
**
** my_strlen renvoie la taille d'une string.
**
** my_putstr vous permet d'afficher une string sur la sortie standard.
**
** my_strcmp vous permet de comparer deux strings si ces strings sont égales alors
** la fonction renvoie 0.
**
** my_strdup vous permet d'allouer dynamiquement une chaine de caractères et de copier la valeur de
** la chaine passé en paramètre et de renvoyer cette chaine.
**
** my_putstr_color vous permet d'afficher une string sur la sortie standard de la couleur souhaitée.
** les couleurs disponibles pour cette fonction sont rouge (red), vert (green), jaune (yellow),
** bleu (blue), violet (magenta), et bleu cyan (cyan), elle vous permet également d'effacer
** tout ce qui est actuellement affiché à l'écran (clear) avant d'afficher votre chaine de caractères.
*/
#include		<stdlib.h>
#include		<unistd.h>

const char		*reset_color = "\033[0m";

typedef			struct s_color	t_color;

struct			s_color
{
  char			*color;
  char			*unicode;
};

static const t_color	g_color[] =
  {
    {"clear", "\033[H\033[2J"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {NULL, NULL}
  };

void			my_putchar(const char c)
{
  write(1, &c, 1);
}

int			my_strlen(const char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void			my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}

int			my_strcmp(const char *s1, const char *s2)
{
  int			i;

  if (s1 == NULL || s2 == NULL)
    return (-2);
  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (1);
      else if (s1[i] < s2[i])
	return (-1);
      i++;
    }
  if (s2[i] != '\0')
    return (-1);
  return (0);
}

char			*my_strdup(const char *str)
{
  int			i;
  char			*copy;

  i = 0;
  copy = NULL;
  if ((copy = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      copy[i] = str[i];
      i++;
    }
  copy[i] = '\0';
  return (copy);
}

void			my_putstr_color(const char *color, const char *str)
{
  int			i;

  i = 0;
  while (g_color[i].color != NULL && (my_strcmp(g_color[i].color, color) != 0))
    i++;
  if (g_color[i].color == NULL)
    {
      my_putstr(str);
      return ;
    }
  my_putstr(g_color[i].unicode);
  my_putstr(str);
  my_putstr(reset_color);
}
