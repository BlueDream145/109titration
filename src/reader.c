/*
** EPITECH PROJECT, 2018
** reader.c
** File description:
**
*/

#include "titration.h"

char *read_file(const char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	char *buff = malloc(sizeof(char) * 4096);
	int offset = 0;

	if (fd <= 0 || buff == NULL)
		return (NULL);
	while (read(fd, buff + offset, 1) > 0 && offset < 4095)
		offset += 1;
	buff[offset] = '\0';
	close(fd);
	return (buff);
}

char *get_line(char *str, int start)
{
	char *result;
	int i;
	int len = 0;

	for (i = start; i < my_strlen(str) && str[i] != '\n'; i++)
		len++;
	if (len == 0)
		return (NULL);
	result = malloc(sizeof(char) * (len + 2));
	if (result == NULL)
		return (NULL);
	for (i = start; str[i] && str[i] != '\n'; i++)
		result[i - start] = str[i];
	result[i - start] = '\0';
	return (result);
}