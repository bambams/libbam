#ifndef BAM_LIST_H
	#define BAM_LIST_H

	#include <assert.h>
	#include <bam_trace.h>
	#include <stdio.h>
	#include <stdlib.h>

struct __bam_list;
typedef struct __bam_list bam_list;

struct __bam_list
{
	void *data;
	bam_list *next;
};

const bam_list *bam_list_back(const bam_list *);
bam_list *bam_list_create(void * const);
void bam_list_destroy(bam_list **);
void bam_list_fprint(FILE *, const bam_list *, void (*bam_list_fprint_data)(FILE *, void * const));
void bam_list_fprintln(FILE *, const bam_list *, void (*bam_list_fprint_data)(FILE *, void * const));
const bam_list *bam_list_node(const bam_list *, const int i);
void *bam_list_pop_back(bam_list **);
void *bam_list_pop_front(bam_list **);
void *bam_list_pop_node(bam_list **, const int);
void bam_list_print(const bam_list *, void (*bam_list_print_data)(void * const));
void bam_list_println(const bam_list *, void (*bam_list_print_data)(void * const));
int bam_list_push_back(bam_list *, void * const);
int bam_list_push_front(bam_list **, void * const);
int bam_list_push_node(bam_list **, const int, void * const);
void bam_list_remove_back(bam_list **);
void bam_list_remove_front(bam_list **);
void bam_list_remove_node(bam_list **, const int);
int bam_list_size(const bam_list *);

#endif

