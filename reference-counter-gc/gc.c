#include "gc.h"

// Allocate memory and initialize reference count
GCObject* gc_malloc(int value) {
    GCObject* obj = (GCObject*)malloc(sizeof(GCObject));
    if (!obj) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    obj->ref_count = 1; // New object starts with 1 reference
    obj->data = value;
    return obj;
}

// Increase reference count
void add_reference(GCObject* obj) {
    if (obj) {
        obj->ref_count++;
    }
}

// Decrease reference count and free memory if count reaches 0
void remove_reference(GCObject* obj) {
    if (obj) {
        obj->ref_count--;
        if (obj->ref_count == 0) {
            printf("Freeing memory for object with data: %d\n", obj->data);
            free(obj);
        }
    }
}
