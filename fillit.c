/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:08:32 by qbackaer          #+#    #+#             */
/*   Updated: 2018/12/06 20:59:41 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft/libft.h"
#include <stdio.h>

// This function serves to check if the format of the input file is valid.
int		parse_file(int fd)
{
	char	*line;
	int		ret;
	int		count;

	count = 1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("COUNT: %d\n", count);
		printf("%s\n", line);
		if (ret < 0)
		{
			ft_putstr("error: failed to read file.\n");
			exit(EXIT_FAILURE);
		}
		/*if (count % 5 == 0)
		{
			ft_putstr("0000\n");
			if (*(line + count - 1) != '\n' || ft_strlen(line) != 1)
			{
				ft_putstr("error 1\n");
				return (-1);
			}
		}
		else if (ft_strlen(line) != 4)
		{
			ft_putnbr(ft_strlen(line));
			ft_putstr("error 2\n");
			return (-1);
		}*/
		count++;
		free(line);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int input_fd;
	int	ret;

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
	if ((ret = parse_file(input_fd)) < 0)
	{
		ft_putstr("error: wrong input file format.\n");
		exit(EXIT_FAILURE);
	}
	ft_putnbr(ret);
	return (0);
}
