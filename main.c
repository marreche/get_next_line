/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marreche <marreche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:23:45 by marreche          #+#    #+#             */
/*   Updated: 2021/05/21 11:20:07 by marreche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char *argv[])
{   
    if (argc != 2)
    {
        fprintf(stderr, "Error: Enter a single text file name.\n");
        exit(EXIT_FAILURE);
    }

    char *line;
    int fd;

    fd = open(argv[1], O_RDONLY);
    while(get_next_line(fd, &line))
    {
            printf("%s\n", line);
            free(line);
    }
    free(line);
    printf("%s\n", line);
}
	/* get_next_line(fd, &line);
    printf("%s\n", line);

	get_next_line(fd, &line);
    printf("%s\n", line);

	get_next_line(fd, &line);
    printf("%s\n", line);

	get_next_line(fd, &line);
    printf("%s\n", line);

	get_next_line(fd, &line);
    printf("%s\n", line);

	get_next_line(fd, &line);
    printf("%s\n", line);

	return (0);
}
*/

