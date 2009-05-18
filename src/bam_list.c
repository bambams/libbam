/*
 * libbam is a software library/framework.
 * Copyright (C) 2009 Brandon McCaig
 *
 * This file is part of libbam.
 *
 * libbam is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * libbam is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libbam.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <bam/bam_list.h>

const bam_list *bam_list_back(const bam_list *list)
{
	BAM_TRACE("bam_list_back(list) {\n");

	assert(list);

	while(list->next != NULL)
		list = list->next;

	BAM_TRACE("} //bam_list_back(list)\n");

	return list;
}

bam_list *bam_list_create(void * const data)
{
	BAM_TRACE("bam_list_create(data) {\n");

	bam_list *list = (bam_list *)malloc(sizeof(bam_list));

	if(list == NULL)
		return NULL;

	list->data = data;
	list->next = NULL;

	BAM_TRACE("} //bam_list_create(data)\n");

	return list;
}

void bam_list_destroy(bam_list **list)
{
	BAM_TRACE("bam_list_destroy(list) {\n");

	bam_list *current = NULL;
	bam_list *next = NULL;

	assert(list);

	current = *list;

	while(current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*list = NULL;

	BAM_TRACE("} //bam_list_destroy(list)\n");
}

void bam_list_fprint(FILE * stream, const bam_list *list, void (*bam_list_fprint_data)(FILE *, void * const))
{
	BAM_TRACE("bam_list_fprint(stream, list, bam_list_fprint_data) {\n");

	assert(list);

	bam_list_fprint_data(stream, list->data);

	while((list = list->next) != NULL)
	{
		putc(',', stream);
		bam_list_fprint_data(stream, list->data);
	}

	BAM_TRACE("} //bam_list_fprint(stream, list, bam_list_fprint_data)\n");
}

void bam_list_fprintln(FILE * stream, const bam_list *list, void (*bam_list_fprint_data)(FILE *, void * const))
{
	BAM_TRACE("bam_list_fprintln(stream, list, bam_list_fprint_data) {\n");

	bam_list_fprint(stream, list, bam_list_fprint_data);
	putc('\n', stream);

	BAM_TRACE("} //bam_list_fprintln(stream, list, bam_list_fprint_data)\n");
}

const bam_list *bam_list_node(const bam_list *list, const int i)
{
	BAM_TRACE("bam_list_node(list, i) {\n");

	int j;

	if(list == NULL)
		return NULL;

	for(j=0; j<i; j++)
		if((list = list->next) == NULL)
			return NULL;

	BAM_TRACE("} //bam_list_node(list, i)\n");

	return list;
}

void *bam_list_pop_back(bam_list **list)
{
	BAM_TRACE("bam_list_pop_back(list) {\n");

	bam_list *current = NULL;
	void *data = NULL;
	bam_list *previous = NULL;

	assert(list);

	if((current = *list) == NULL)
		return NULL;

	while(current->next != NULL)
	{
		previous = current;
		current = current->next;
	}

	data = current->data;

	if(previous == NULL)
		*list = NULL;
	else
		previous->next = NULL;

	free(current);

	BAM_TRACE("} //bam_list_pop_back(list)\n");

	return data;
}

void *bam_list_pop_front(bam_list **list)
{
	BAM_TRACE("bam_list_pop_front(list) {\n");

	void *data = NULL;

	assert(list);

	if(*list == NULL)
		return NULL;

	data = (*list)->data;

	if((*list)->next != NULL)
		*list = (*list)->next;
	else
		*list = NULL;

	BAM_TRACE("} //bam_list_pop_front(list)\n");

	return data;
}

void *bam_list_pop_node(bam_list **list, const int i)
{
	BAM_TRACE("bam_list_pop_node(list) {\n");

	bam_list *current = NULL;
	void *data = NULL;
	int j;
	bam_list *previous = NULL;

	assert(list);
	assert(i >= 0);

	if((current = *list) == NULL)
		return NULL;

	for(j=0; j<i; j++)
	{
		if(current == NULL)
			return NULL;

		previous = current;
		current = current->next;
	}

	data = current->data;

	if(i == 0)
		*list = NULL;
	else
		previous->next = current->next;

	free(current);

	BAM_TRACE("} //bam_list_pop_node(list)\n");

	return data;
}

void bam_list_print(const bam_list *list, void (*bam_list_print_data)(void * const))
{
	BAM_TRACE("bam_list_print(list, bam_list_print_data) {\n");

	assert(list);

	bam_list_print_data(list->data);

	while((list = list->next) != NULL)
	{
		putc(',', stdout);
		bam_list_print_data(list->data);
	}

	BAM_TRACE("} //bam_list_print(list, bam_list_print_data)\n");
}

void bam_list_println(const bam_list *list, void (*bam_list_print_data)(void * const))
{
	BAM_TRACE("bam_list_println(list, bam_list_print_data) {\n");

	bam_list_print(list, bam_list_print_data);
	putc('\n', stdout);

	BAM_TRACE("} //bam_list_println(list, bam_list_print_data)\n");
}

int bam_list_push_back(bam_list *list, void * const data)
{
	BAM_TRACE("bam_list_push_back(list, data) {\n");

	bam_list *next = NULL;
	bam_list *node = NULL;

	assert(list);

	if((node = bam_list_create(data)) == NULL)
		return 0;

	while((next = list->next) != NULL)
		list = next;

	list->next = node;

	BAM_TRACE("} //bam_list_push_back(list, data)\n");

	return 1;
}

int bam_list_push_front(bam_list **list, void * const data)
{
	BAM_TRACE("bam_list_push_front(list, data) {\n");

	bam_list *node = NULL;

	assert(list);
	assert(*list);

	if((node = bam_list_create(data)) == NULL)
		return 0;

	node->next = *list;

	*list = node;

	BAM_TRACE("} //bam_list_push_front(list, data)\n");

	return 1;
}

int bam_list_push_node(bam_list **list, const int i, void * const data)
{
	BAM_TRACE("bam_list_push_node(list, data) {\n");

	int j;
	bam_list *current = NULL;
	bam_list *node = NULL;
	bam_list *previous = NULL;

	assert(list);
	assert(*list);
	assert(i >= 0);

	if((node = bam_list_create(data)) == NULL)
		return 0;

	current = *list;

	for(j=0; j<i; j++)
	{
		if(current == NULL)
			return 0;

		previous = current;
		current = current->next;
	}

	if(i == 0)
		*list = node;
	else
		previous->next = node;

	node->next = current;

	BAM_TRACE("} //bam_list_push_node(list, data)\n");

	return 1;
}

void bam_list_remove_back(bam_list **list)
{
	BAM_TRACE("bam_list_remove_back(list) {\n");

	bam_list *current = NULL;
	bam_list *previous = NULL;

	assert(list);

	if((current = *list) == NULL)
		return;

	while(current->next != NULL)
	{
		previous = current;
		current = current->next;
	}

	if(previous == NULL)
		*list = NULL;
	else
		previous->next = current->next;

	free(current);

	BAM_TRACE("} //bam_list_remove_back(list)\n");
}

void bam_list_remove_front(bam_list **list)
{
	BAM_TRACE("bam_list_remove_front(list) {\n");

	bam_list *current = NULL;

	assert(list);

	if((current = *list) == NULL)
		return;

	if(current->next == NULL)
		*list = NULL;
	else
		*list = current->next;

	free(current);

	BAM_TRACE("} //bam_list_remove_front(list)\n");
}

void bam_list_remove_node(bam_list **list, const int i)
{
	BAM_TRACE("bam_list_remove_node(list, i) {\n");

	int j;
	bam_list *current = NULL;
	bam_list *previous = NULL;

	assert(list);

	if((current = *list) == NULL)
		return;

	for(j=0; j<i; j++)
	{
		if(current == NULL)
			return;

		current = current->next;
	}

	if(i == 0)
		*list = current->next;
	else
		previous->next = current->next;

	free(current);

	BAM_TRACE("} //bam_list_remove_node(list, i)\n");
}

int bam_list_size(const bam_list *list)
{
	BAM_TRACE("bam_list_size(list) {\n");

	int i;

	if(list == NULL)
		return 0;

	for(i=0; list != NULL; i++)
		list = list->next;

	BAM_TRACE("} //bam_list_size(list)\n");

	return i;
}

