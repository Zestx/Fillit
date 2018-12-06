/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:08:32 by qbackaer          #+#    #+#             */
/*   Updated: 2018/12/06 18:37:59 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		parse_input(int fd)
{
	
}

int		main(int argc, char **argv)
{
	int input_fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <source_file>");
		exit(EXIT_FAILURE);
	}
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd < 3)
	{
		ft_putstr("error: failed to open input file.");
		exit(EXIT_FAILURE);
	}
	return (0);
}
