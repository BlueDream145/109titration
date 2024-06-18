/*
** EPITECH PROJECT, 2018
** engine.c
** File description:
**
*/

#include "titration.h"

int process(struct request *req)
{
	int len = 0;
	int index = 0;

	if (req == NULL || first_derivative(req) == 0 ||
		second_derivative(req) == 0)
		return (FAIL);
	for (index = 0; req->second[index]->key !=
		equivalent_point(req->first, req->current - 2); index++);
	len = (req->second[index + 1]->key -
		req->second[index - 1]->key) * 10 + 1;
	if (last_derivative(req, len, index) == 0)
		return (FAIL);
	return (SUCCESS);
}

int first_derivative(struct request *req)
{
	if ((req->first = malloc(sizeof(struct entry*)
		* req->current)) == NULL)
		return (0);
	for (int i = 0; i < req->current - 2; i++) {
		if ((req->first[i] = malloc(sizeof(struct entry))) == NULL)
			return (0);
		req->first[i]->key = req->data[i + 1]->key;
		req->first[i]->value = (req->data[(i + 1) + 1]->value -
			req->data[(i + 1) - 1]->value) /
			(req->data[(i + 1) + 1]->key -
			req->data[(i + 1) - 1]->key);
	}
	display_first_derivative(req);
	display_equivalent_point(equivalent_point(req->first,
		req->current - 2));
	return (1);
}

int second_derivative(struct request *req)
{
	if ((req->second = malloc(sizeof(struct entry*) *
		req->current)) == NULL)
		return (0);
	for (int i = 0; i < req->current - 4; i++) {
		if ((req->second[i] = malloc(sizeof(struct entry))) == NULL)
			return (0);
		req->second[i]->key = req->first[i + 1]->key;
		req->second[i]->value = (req->first[(i + 1) + 1]->value -
			req->first[(i + 1) - 1]->value) /
			(req->first[(i + 1) + 1]->key -
			req->first[(i + 1) - 1]->key);
	}
	display_second_derivative(req);
	return (1);
}

int last_derivative(struct request *req, int len, int index)
{
	double key_base = req->second[index - 1]->key;
	double sup = (req->second[index]->value -
		req->second[index - 1]->value) /
		((req->second[index]->key -
		req->second[index - 1]->key) * 10);
	double sup2 = (req->second[index + 1]->value -
		req->second[index]->value) /
		((req->second[index + 1]->key -
		req->second[index]->key) * 10);
	double base;
	int pos = 1;

	if ((req->last = malloc(sizeof(struct entry*) * len)) == NULL)
		return (0);
	for (int i = 0; i != len; i++) {
		if ((req->last[i] = malloc(sizeof(struct entry))) == NULL)
			return (0);
		req->last[i]->key = key_base;
		key_base += 0.1;
	}
	req->last[0]->value = req->second[index - 1]->value;
	for (base = req->last[0]->key; base < req->second[index]->key - 0.1;
		base += 0.1) {
		req->last[pos]->value = req->last[pos - 1]->value + sup;
		pos++;
	}
	for (; base < req->second[index + 1]->key - 0.1; base += 0.1) {
		req->last[pos]->value = req->last[pos - 1]->value + sup2;
		pos++;
	}
	display_second_estimated_derivative(req, len);
	display_equivalent_precise(equivalent_precise(req->last, len));
	return (1);
}