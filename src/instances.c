/*
** EPITECH PROJECT, 2018
** instances.c
** File description:
**
*/

#include "titration.h"

struct request *get_instance(char *file_name)
{
	struct request *req = malloc(sizeof(struct request));

	if (req == NULL)
		return (NULL);
	req->file_name = my_strdup(file_name);
	req->file_content = read_file(file_name);
	if (req->file_content == NULL)
		return (NULL);
	req->current = 0;
	req->first = NULL;
	req->second = NULL;
	req->last = NULL;
	return (req);
}

int serialize_instance(struct request *req)
{
	char *line = get_line(req->file_content, 0);

	if (line == NULL || strlen(req->file_content) < 5 ||
		string_len(req->file_content, '\n') <= 1 ||
		(req->data = malloc(sizeof(struct entry*) *
		(string_len(req->file_content, '\n') + 1))) == NULL ||
		check_line(req, line) == 0)
		return (0);
	for (int i = my_strlen(line); i <= my_strlen(req->file_content);) {
		if (my_strlen(req->file_content) - i <= 2)
			break;
		line = get_line(req->file_content, i + 1);
		i += my_strlen(line) + 1;
		if (check_line(req, line) == 0)
			return (0);
	}
	return (1);
}

void free_instance(struct request *req)
{
	free(req->file_name);
	free(req->file_content);
	free(req->data);
	if (req->first != NULL)
		free(req->first);
	if (req->second != NULL)
		free(req->second);
	if (req->last != NULL)
		free(req->last);
	free(req);
}