/*
** EPITECH PROJECT, 2018
** display.c
** File description:
**
*/

#include "titration.h"

void display_first_derivative(struct request *req)
{
	printf("Derivative:\n");
	for (int i = 0; i < req->current - 2; i++)
		printf("volume: %g ml -> %.2f\n",
			req->first[i]->key, req->first[i]->value);
	printf("\n");
}

void display_second_derivative(struct request *req)
{
	printf("Second derivative:\n");
	for (int i = 0; i < req->current - 4; i++)
		printf("volume: %g ml -> %.2f\n",
			req->second[i]->key, req->second[i]->value);
	printf("\n");
}

void display_second_estimated_derivative(struct request *req, int len)
{
	printf("Second derivative estimated:\n");
	for (int i = 0; i < len; i++)
		printf("volume: %g ml -> %.2f\n",
			req->last[i]->key, req->last[i]->value);
	printf("\n");
}

void display_equivalent_point(int val)
{
	printf("Equivalent point at %d ml\n", val);
	printf("\n");
}

void display_equivalent_precise(double val)
{
	printf("Equivalent point at %g ml\n", val);
}