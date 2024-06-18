/*
** EPITECH PROJECT, 2017
** file.h
** File description:
**
*/

#ifndef TITRATION_
	#define TITRATION_

	#include <signal.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <string.h>

	#define SUCCESS (0)
	#define FAIL (84)

struct request {
	struct entry **data;
	struct entry **first;
	struct entry **second;
	struct entry **last;
	char *file_name;
	char *file_content;
	int current;
};

struct entry {
	double key;
	double value;
};

// check.c
int check_line(struct request *req, char *line);
int check_nbr(char *str);

// display.c
void display_first_derivative(struct request *req);
void display_second_derivative(struct request *req);
void display_second_estimated_derivative(struct request *req, int len);
void display_equivalent_point(int val);
void display_equivalent_precise(double val);

// engine.c
int process(struct request *req);
int first_derivative(struct request *req);
int second_derivative(struct request *req);
int last_derivative(struct request *req, int len, int index);

// instances.c
struct request *get_instance(char *file_name);
int serialize_instance(struct request *req);
void free_instance(struct request *req);

// main.c
void help(void);

// math.c
int equivalent_point(struct entry **src, int len);
double equivalent_precise(struct entry **src, int len);

// reader.c
char *read_file(const char *file_name);
char *get_line(char *str, int start);

// string.c
int my_strlen(const char *src);
int string_len(char *src, char c);
char *my_strdup(const char *src);
char **my_str_to_word_array(const char *str, char separator);
void split_string(const char *str, char separator,
	char **result, char *content);

#endif /* TITRATION */