/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:08:32 by qbackaer          #+#    #+#             */
/*   Updated: 2018/12/07 20:03:53 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		parse_file(int fd)
{
    char	buffer[5];
    char    nl[1];
    int		ret;
    int		i;
    int     j;
    int     k;

    ret = 1;
    k = 0;
    while (ret && k < 26)
    {
        i = 0;
        while (i < 4 && (ret = read(fd, buffer, 5)) == 5)
        {
            if (ret < 0)
                return (-1);
            j = 0;
            while(j < 4)
            {
                if (buffer[j] != '.' && buffer[j] != '#')
                    return (-1);
                j++;
            }
            if(buffer[4] != '\n')
                return (-1);
            i++;
        }
        if (!ret)
            break;
        if ((ret = read(fd, nl, 1)) != 1 || nl[0] != '\n')
            return (-1);
        k++;
    }
    if (k > 25)
        return (-1);
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
