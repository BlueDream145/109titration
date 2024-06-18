/*
** EPITECH PROJECT, 2018
** string.c
** File description:
**
*/

#include "titration.h"

int my_strlen(const char *src)
{
	int len;

	for (len = 0; src[len]; len++);
	return (len);
}

int string_len(char *src, char c)
{
	int len = 0;

	for (int i = 0; src[i]; i++)
		if (src[i] == c)
			len++;
	return (len);
}

char *my_strdup(const char *src)
{
	char *str;
	int len = my_strlen(src) + 1;

	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	str = strcpy(str, src);
	return (str);
}

char **my_str_to_word_array(const char *str, char separator)
{
	char **result = malloc(sizeof(char *) * my_strlen(str));
	char *content = malloc(sizeof(char) * (my_strlen(str) + 1));

	if (result == NULL || content == NULL || my_strlen(str) == 0)
		return (NULL);
	content[0] = '\0';
	split_string(str, separator, result, content);
	return (result);
}

void split_string(const char *str, char separator,
	char **result, char *content)
{
	int word_len = 0;
	int total_len = 0;

	for (int i = 0; i < my_strlen(str) + 1; i++) {
		if (str[i] != separator) {
			content[word_len] = str[i];
			word_len++;
			content[word_len] = '\0';
		} else if (my_strlen(content) > 0) {
			word_len = 0;
			result[total_len] = my_strdup(content);
			total_len++;
		}
	}
	if (my_strlen(content) > 0) {
		content[word_len] = '\0';
		result[total_len] = my_strdup(content);
		total_len++;
	}
	result[total_len] = '\0';
}