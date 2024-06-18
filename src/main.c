/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "titration.h"

int main(int ac, char **as)
{
	struct request *req;
	int callback;

	if (ac != 2)
		return (FAIL);
	if (strcmp(as[1], "-h") == 0) {
		help();
		return (SUCCESS);
	}
	req = get_instance(as[1]);
	if (req == NULL || open(req->file_name, O_RDONLY) <= 0 ||
		serialize_instance(req) == 0)
		return (FAIL);
	callback = process(req);
	free_instance(req);
	return (callback);
}

void help(void)
{
	const char *header = "USAGE\n           ./109titration file\n\n";
	const char *usage = "DESCRIPTION\n           "
		"file a csv file containing 'vol;ph' lines";

	printf("%s%s", header, usage);
}