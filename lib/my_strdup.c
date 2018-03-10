/*
** my_strdup.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Sun Feb  5 11:52:16 2017 Thomas BLENEAU
** Last update Sun Feb  5 13:56:39 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

char	*my_strdup(char *str)
{
  int	i;
  int	j;
  char	*string;

  i = -1;
  j = 0;
  if (str == NULL)
    return (NULL);
  if ((string = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str && str[++i] != '\0')
    string[j++] = str[i];
  string[j] = '\0';
  return (string);
}
