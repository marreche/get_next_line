/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marreche <marreche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:58:29 by marreche          #+#    #+#             */
/*   Updated: 2021/03/11 18:09:34 by marreche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"


int		main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	char *line;
	int fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
}
