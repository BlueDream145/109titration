/*
** EPITECH PROJECT, 2018
** check.c
** File description:
**
*/

#include "titration.h"

int check_line(struct request *req, char *line)
{
	char **src;

	if (string_len(line, ';') != 1 ||
		(src = my_str_to_word_array(line, ';')) == NULL)
		return (0);
	if (!src[0] || !src[1] ||
		(check_nbr(src[0]) == 0) || (check_nbr(src[1]) == 0))
		return (0);
	if ((req->data[req->current] = malloc(sizeof(struct entry))) == NULL)
		return (0);
	req->data[req->current]->key = atof(src[0]);
	req->data[req->current]->value = atof(src[1]);
	req->current++;
	free(src);
	return (1);
}

int check_nbr(char *str)
{
	for (int i = 0; i < my_strlen(str); i++)
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.' &&
			str[i] != '-')
			return (0);
	return (1);
}