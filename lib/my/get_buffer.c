/*
** EPITECH PROJECT, 2023
** Get Buffer
** File description:
** get_buffer
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <aio.h>
#include <stdlib.h>
#include <unistd.h>

int size_file(char *path);

char *get_buffer(char *path)
{
    int fd = open(path, O_RDONLY);
    char *buffer;
    int size = size_file(path);

    if (size == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        return (NULL);
    read(fd, buffer, size);
    if (size <= 0)
        return (NULL);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}
