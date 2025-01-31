#ifndef GC_H
#define GC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct GCObject {
    int ref_count;
    int data;
} GCObject;


// Function prototypes
GCObject* gc_malloc(int value);
void add_reference(GCObject* obj);
void remove_reference(GCObject* obj);

#endif
