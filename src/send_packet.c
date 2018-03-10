/*
** send_packet.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Feb  6 15:53:01 2017 Thomas BLENEAU
** Last update Wed Feb  8 14:05:07 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	my_power(int nb, int power)
{
  int	result;

  result = 1;
  while (power > 0)
    {
      result = result * nb;
      power = power - 1;
    }
  return (result);
}

int	send_packet(int pid, char packet)
{
  int	i;
  int	power;

  i = 2;
  packet = convert_packet(packet, 0);
  while (i >= 0)
    {
      usleep(10000);
      power = my_power(2, i);
      if (packet >= power)
	{
	  packet = packet - power;
	  if ((kill(pid, SIGUSR1)) == -1)
	    return (1);
	}
      else if (packet < power)
	{
	  if ((kill(pid, SIGUSR2)) == -1)
	    return (1);
	}
      i = i - 1;
    }
  return (0);
}

int	receive_packet()
{
  int	i;
  int	power;
  int	packet;

  i = 2;
  packet = 0;
  while (i >= 0)
    {
      pause();
      power = my_power(2, i);
      if (g_pid == SIGUSR1)
	packet = packet + power;
      i = i - 1;
    }
  return (packet);
}
