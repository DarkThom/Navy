/*
** client.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Sat Feb  4 10:17:37 2017 Thomas BLENEAU
** Last update Sun Feb 19 11:40:04 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int		client_action(int ac, char **av)
{
  t_game	game;
  int		boolean;

  if (check_connection(ac, av))
    return (0);
  game.pid = my_getnbr(av[1]);
  if (check_sigaction_receive())
    return (0);
  game.tab = create_tab_game(ac, av);
  game.tab_enemy = parsing_map();
  while ((boolean = 1) == 1)
    {
      display_game(game.tab, game.tab_enemy);
      attack_server_client(game.pid, game.tab, game.tab_enemy);
      if (((game.res = test_map(game.tab_enemy, game.tab)) == 0)
	  || (game.res = test_win(game.tab, game.tab_enemy)))
	break ;
      if (display_attack(game.pid, game.tab, game.tab_enemy))
	return (0);
      if (((game.res = test_map(game.tab_enemy, game.tab)) == 0)
	  || (game.res = test_win(game.tab, game.tab_enemy)))
	break ;
    }
  return (game.res);
}
