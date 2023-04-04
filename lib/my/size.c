/*
** EPITECH PROJECT, 2022
** size.c.c
** File description:
** give the size of one txt file.
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int size_file(char *path)
{
    int fd = open(path, O_RDONLY);
    char buff[3];
    int error = -1;
    int count = 0;

    if (fd == -1)
        return -1;
    while (error != 0) {
        error = read(fd, buff, 3);
        if (error == -1)
            return -1;
        count += error;
    }
    return count;
}
