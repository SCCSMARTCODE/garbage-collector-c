// Header file for GC function prototypes
#pragma once

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <stdbool.h>
#include <pthread.h>  

extern pthread_mutex_t gc_mutex;


typedef struct GcObject{
    void* memory;
    bool isMarked;
    struct GcObject* next;
}GcObject;



void* get_stack_base();
void *gc_malloc(size_t size);
void gc_collect();
void *gc_thread_function(void *arg);