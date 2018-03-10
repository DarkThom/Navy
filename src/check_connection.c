/*
** check_connection.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Feb  7 11:42:03 2017 Thomas BLENEAU
** Last update Thu Feb  9 11:42:09 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	check_connection(int ac, char **av)
{
  if (ac == 2)
    {
      display_pid();
      write(1, "waiting for enemy connexion...\n", 31);
      pause();
      write(1, "enemy connected\n\n", 17);
    }
  else if (ac == 3)
    {
      if ((kill(pid_handler(my_getnbr(av[1])), SIGUSR2)) == -1)
	return (1);
      display_pid();
      write(1, "successfully connected\n\n", 24);
    }
  return (0);
}

char	result_receive(char **tab_enemy)
{
  int	i;
  char	packet;

  i = 0;
  packet = 0;
  while (i < 1)
    {
      packet = receive_packet();
      packet = convert_packet(packet, 2);
      if (packet == '1')
	write(1, ": hit\n\n", 7);
      else
	write(1, ": missed\n\n", 10);
      i = i + 1;
    }
  return (packet);
}

char	*attack_receive()
{
  int	i;
  char	*str;
  char	packet;

  i = 0;
  packet = 0;
  if ((str = malloc(sizeof(char) * (PACKET_LEN + 1))) == NULL)
    return (NULL);
  write(1, "waiting for enemy's attack...\n", 30);
  while (i < 2)
    {
      packet = receive_packet();
      packet = convert_packet(packet, i + 1);
      str[i] = packet;
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}

int	attack_send(int pid, char *str)
{
  int	i;

  i = 0;
  while (i < 2)
    {
      send_packet(pid, str[i]);
      i = i + 1;
    }
  return (0);
}
