/*
** mario.h for  in /home/garrig_b/KART/new
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Oct 26 11:36:00 2014 a
** Last update Sun Oct 26 22:25:55 2014 a
*/

#ifndef _MARIO_H_
# define _MARIO_H_

#include <ncurses.h>
#include <stdlib.h>

extern int     g_km;
extern int     g_compteur;
extern int     g_time;
extern int     g_random;

int	my_end(int i);
void	tree();
void	two();
void    my_one();
void	my_start();
void	my_race();
void	init_all();
void	init_map(int x, int y, int **map);
void	init_map2(int x, int y, int **map);
int	where_is_car(int *map, int y);
int	**my_right(int x, int y, int **map);
int	**my_left(int x, int y, int **map);
int	*plus_first_line(int *map, int y);
int	*less_first_line(int *map, int y);
int	my_check_rand(int random, int **map, int y);
int	my_check_map2(int *map, int y);
int	my_check_map(int *map, int y);
void	my_analyse(int touch, int x, int y, int **map);
int	my_mario(int x, int y, int **map);
void	wy_aff_map(int x, int y, WINDOW *w, int **map);
int	my_mario(int x, int y, int **map);
void	wy_aff_map(int x, int y, WINDOW *w, int **map);
void	my_analyse_char(int map, WINDOW *w);
int	my_collision(int *first, int *second, int y, WINDOW *window);
int	my_check_bonus(int *second, int *first, int  y);
int	my_clear(int *first, int y);
int	my_check_col(int *map, int y);
int	my_modiff_map(int x, int y, int **map, WINDOW *window);
int	*my_putobstacle(int *map, int y);
int	my_modiff_all_map(int x, int y, int **map, WINDOW *window);
int	*my_swap_map(int *old, int *new, int y);
int	*my_putobstacle2(int *old, int *new, int y);
int	my_put_object(int x, int y, int **map);
int	my_seek_and_destroy(int *map, int y, int seek);
int	*my_putobject(int *old, int *new, int y);
int	my_check_bug(int  *first, int *second, int y);


#endif /* MARIO_H_ */
