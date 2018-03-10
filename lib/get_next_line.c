/*
** get_next_line.c for  in /home/BLENEA_T/Projects/CPE/CPE_2016_getnextline
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 09 16:35:18 2017 Thomas BLENEAU
** Last update Sun Feb  5 09:36:54 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

static char	*get_buffer_data(char *str, char *buffer,
				 int count, int boolean)
{
  int		i;
  int		j;

  i = 0;
  if (boolean == 0)
    {
      j = 0;
      while (buffer[j] != '\0' && j < count)
	str[i++] = buffer[j++];
      str[i] = '\0';
      return (str);
    }
  while (buffer[i] != '\0' && i < count)
    {
      str[i] = buffer[i];
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}

int		my_strlen(const char *str)
{
  int		var;

  var = -1;
  while (str && str[++var]);
  return (var);
}

static char	*get_strdup(char *str, char *buffer, int j, int *i)
{
  char          *buff_alloc;
  int           count;

  count = 0;
  if (str != NULL)
    count = my_strlen(str);
  if ((buff_alloc = malloc(sizeof(char) * (count + j + 1))) == NULL)
    return (NULL);
  if (str == NULL)
    get_buffer_data(buff_alloc, "", count, 0);
  else
    get_buffer_data(buff_alloc, str, count, 1);
  buff_alloc[j + count] = '\0';
  get_buffer_data((buff_alloc + count), (buffer + *i), j, 1);
  if (str != NULL)
    free(str);
  *i = *i + (j + 1);
  return (buff_alloc);
}

char		*get_next_line(const int fd)
{
  t_get_line	line;
  static char	buffer[READ_SIZE];
  static int	reader = 0;
  static int	i;

  line.j = 0;
  line.str = NULL;
  while ((line.boolean = 0) == 0)
    {
      if (reader <= i)
	{
	  i = 0;
	  if (READ_SIZE <= 0 || (reader == -1))
	    return (NULL);
	  else if ((reader = read(fd, buffer, READ_SIZE)) == 0)
	    return (line.str);
	  line.j = 0;
	}
      if (buffer[i + line.j] == '\n')
	return (line.str = get_strdup(line.str, buffer, line.j, &i));
      if (i + line.j == reader - 1)
	line.str = get_strdup(line.str, buffer, line.j + 1, &i);
      line.j = line.j + 1;
    }
  return (line.str);
}
