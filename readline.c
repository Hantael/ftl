/*
** Cette fonction permet de récuper une ligne
** de moins de 50 caractères sur l'entrée standard.
** La fonction ne prend pas de paramètre et renvoit une chaîne
** allouée (pensez a free()).
*/
#include	<stdlib.h>
#include	<unistd.h>

char		*readline(void)
{
  ssize_t	ret;
  char		*buff;

  if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  free(buff);
  return (NULL);
}
