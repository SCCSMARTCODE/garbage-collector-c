// Core garbage collector implementation
#include "gc.h" 

GcObject *head = NULL;
GcObject *tail = NULL;
pthread_mutex_t gc_mutex = PTHREAD_MUTEX_INITIALIZER;


void* get_stack_base() {
    void* stack_base = NULL;
    
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_getattr_np(pthread_self(), &attr);
    size_t stack_size;
    pthread_attr_getstack(&attr, &stack_base, &stack_size);
    pthread_attr_destroy(&attr);

    return (void*)((char*)stack_base + stack_size); // Ensure this is correct!
}


void find_object_by_address(void *ptr) {
    
    GcObject* current_obj = head;
    while (current_obj) {
        if (ptr == current_obj->memory) {
            current_obj->isMarked = true;
            return;
        }
        current_obj = current_obj->next;
    }
}

void sweep_memory() {
    GcObject* current_mem_obj = head;
    GcObject* prev = NULL;

    if (!current_mem_obj) return;

    while (current_mem_obj) {
        if (!current_mem_obj->isMarked) {
            printf("[GC] Freeing memory at %p\n", current_mem_obj->memory);  // 🛑 Log freed memory

            if (current_mem_obj == head) {
                head = current_mem_obj->next;
            } else if (current_mem_obj == tail) {
                tail = prev;
                prev->next = NULL;
            } else {
                prev->next = current_mem_obj->next;
            }

            free(current_mem_obj->memory);
            free(current_mem_obj);
        } else {
            current_mem_obj->isMarked = false;  // Reset for next GC cycle
        }

        prev = current_mem_obj;
        current_mem_obj = current_mem_obj->next;
    }
}

void* gc_malloc(size_t memory_size) {
    void* memory = malloc(memory_size);
    GcObject *new_object = (GcObject *)malloc(sizeof(GcObject));

    new_object->memory = memory;
    new_object->isMarked = false;
    new_object->next = NULL;

    if (!head) head = new_object;
    if (tail) tail->next = new_object;
    tail = new_object;

    printf("[GC] Allocated memory at %p\n", memory);  // 🟢 Log allocation

    return memory;
}

void gc_collect(){
    printf("\n[GC] Running garbage collection...\n");
    int thePointerToTrackBeginningStackMemoryAddress;

    
    void* addressToStackBeginningPtr = &thePointerToTrackBeginningStackMemoryAddress;
    void* addressToStackEndPtr = get_stack_base();
   
    // Marking process
   for (void **ptr = (void **)addressToStackBeginningPtr; ptr > (void **)addressToStackEndPtr; ptr--) {
        if (ptr == NULL || *ptr == NULL) continue; // Skip invalid pointers
        find_object_by_address(*ptr);
    }

    // Sweeping process
    sweep_memory();

}



