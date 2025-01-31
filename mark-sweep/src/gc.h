// Header file for GC function prototypes
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>  


typedef struct GcObject{
    void* memory;
    bool isMarked;
    GcObject* next;
}GcObject;

GcObject* head = NULL;
GcObject* tail = NULL;

void* thePointerToTrackBeginningStackMemoryAddress = NULL;

void* get_stack_info();