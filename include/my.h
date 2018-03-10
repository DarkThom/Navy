/*
** my.h for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 30 14:04:13 2017 Thomas BLENEAU
** Last update Thu Feb  9 11:36:48 2017 Thomas BLENEAU
*/

#ifndef MY_H_
# define MY_H_

/*
** Prototypes de fonctions de libmy
*/

char	*convert_base(char *, char *, char *);
char	*my_revstr(char *);
char	*my_strdup(char *);
int	check_params(int, char **);
int	check_same_boat(char **);
int	free_str(char *);
int	free_tab_function(char **);
int	isnum_alpha(char);
int	my_strcmp(const char *, const char *);
int	my_strlen(const char *);
int	my_str_isnum(char *);
int	my_atoi(char);
int	my_tablen(const char *);
int	my_getnbr_base(char *, char *);
int	my_getnbr(char *);
void	free_tab(char **, char **);
void	my_put_nbr(int);
void	my_swap(char *, char *);
void	display(char **);

#endif /* !MY_H_ */
