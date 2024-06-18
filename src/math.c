/*
** EPITECH PROJECT, 2018
** math.c
** File description:
**
*/

#include "titration.h"

int equivalent_point(struct entry **src, int len)
{
	int result = src[0]->key;
	int max = -2147483648;

	for (int i = 0; i < len; i++)
		if (src[i]->value > max) {
			result = src[i]->key;
			max = src[i]->value;
		}
	return (result);
}

double equivalent_precise(struct entry **src, int len)
{
	for (int i = 0; i != len; i++)
		if (src[i]->value * src[i + 1]->value < 0)
			return (src[i]->key);
	return (0);
}