/*
** main.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 30 13:01:24 2017 Thomas BLENEAU
** Last update Wed Feb  8 20:11:53 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int			g_pid;

int			main(int ac, char **av)
{
  int			res;

  if (ac < 2 || ac > 3)
    return (84);
  else if (ac == 2 && my_strcmp(av[1], "-h") == 0)
    return (help_command());
  else if (check_params(ac, av))
    return (84);
  if (check_sigaction())
    return (84);
  if (ac == 2 && (my_strcmp(av[1], "-h") != 0))
    {
      if ((res = server_action(ac, av)))
	return (res);
    }
  else if (ac == 3)
    {
      if ((res = client_action(ac, av)))
	return (res);
    }
  return (0);
}
