/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:08:32 by qbackaer          #+#    #+#             */
/*   Updated: 2018/12/10 19:59:23 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		check_adjacent(int crd[4][2])
{
	int i;
	int j;
	int match;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		match = 0;
		while (j < 4)
		{
			if (j != i)
			{
				if ((crd[i][0] == crd[j][0] && (crd[i][1] == crd[j][1] + 1 || crd[i][1] == crd[j][1] - 1)) 
						|| ((crd[i][1] == crd[j][1]) && (crd[i][0] == crd[j][0] + 1 || crd[i][0] == crd[j][0] - 1)))
					match = 1; 
			}
			j++;
		}
		if (match == 0)	
			return (-1);
		i++;
	}
	return (1);
}

int		check_tetra(char buffer[4][5])
{
	int i;
	int j;
	int count;
	int coord[4][2];

	i = 0;
	count = 0;
	printf("\n--\n--\n");
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (buffer[i][j] == '#')
			{
				coord[count][0] = i;
				coord[count][1] = j;
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 4  || check_adjacent(coord) < 0)
		return (-1);
	return (1);
}

int		parse_tetra(int fd, int *ret, char buffer[4][5])
{
	char	nl[1];
	int		i;
	int		j;

	i = 0;
	while (i < 4 && (*ret = read(fd, buffer[i], 5)) == 5)
	{
		j = 0;
		while (j < 4)
		{
			if (buffer[i][j] != '.' && buffer[i][j] != '#')
				return (-1);
			j++;
		}
		if (buffer[i][4] != '\n')
			return (-1);
		i++;
	}
	if (!(*ret))
		return (0);
	if (*ret < 0 || (*ret = read(fd, nl, 1)) != 1 || nl[0] != '\n')
		return (-1);
	if (check_tetra(buffer) < 0)
		return (-1);
	return (1);
}

int		parse_file(int fd, char buffer[26][4][5])
{
	int		ret;
	int		k;

	k = 0;
	while ((ret = parse_tetra(fd, &ret, buffer[k])) > 0 && k < 27)
		k++;
	if (!k || k > 25 || ret < 0)
		return (-1);
	return (k);
}

int		main(int argc, char **argv)
{
	int		input_fd;
	int		ret;
	char	buffer[26][4][5];

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <source_file>\n");
		exit(EXIT_FAILURE);
	}
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd < 3)
	{
		ft_putstr("error: failed to open input file.\n");
		exit(EXIT_FAILURE);
	}
	if ((ret = parse_file(input_fd, buffer)) < 0)
	{
		ft_putstr("error: wrong input file format.\n");
		exit(EXIT_FAILURE);
	}
	printf("\nRET: %d\n", ret);
	return (0);
}
