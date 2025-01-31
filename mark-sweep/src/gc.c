// Core garbage collector implementation
#include "gc.h" 


void* get_stack_info() {  
    pthread_attr_t attr;  
    void* stackaddr;  
    size_t stacksize;  

    pthread_attr_init(&attr);  
    pthread_getattr_np(pthread_self(), &attr);  
    pthread_attr_getstack(&attr, &stackaddr, &stacksize);  
    pthread_attr_destroy(&attr);  
    
    return stackaddr; // Return the stack base address  
}  


void* gc_malloc(size_t memory_size){
    void* memory = malloc(memory_size);
    GcObject *new_object = (GcObject *)malloc(sizeof(GcObject));

    new_object->memory = memory;
    new_object->isMarked = false;
    new_object->next = NULL;

    if (!head) head = new_object;
    if (tail) tail->next = new_object;
    tail = new_object;

    return memory;
}

void gc_collect(){
    void* addressToStackBeginningPtr = &thePointerToTrackBeginningStackMemoryAddress;
    void* addressToStackEndPtr = 
}