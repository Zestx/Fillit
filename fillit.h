/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:55:51 by qbackaer          #+#    #+#             */
/*   Updated: 2018/12/11 15:30:12 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

//fillit.c
int		parse_file(int fd, char buffer[26][4][5]);
int		parse_tetra(int fd, int *ret, char buffer[4][5]);
int		check_adjacent(int crd[4][2]);
int		check_tetra(char buffer[4][5]);
//helpers.c
int		compare_coords(int crd[4][2], int i, int j);

#endif
