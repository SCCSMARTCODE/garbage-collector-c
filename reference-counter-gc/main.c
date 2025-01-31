#include "gc.h"

int main() {
    // Allocate two objects
    GCObject* obj1 = gc_malloc(100);
    GCObject* obj2 = gc_malloc(200);

    // Increase reference count for obj1
    add_reference(obj1);

    // Decrease references
    remove_reference(obj1); // Still has 1 reference, not freed
    remove_reference(obj1); // Now ref_count = 0, should be freed
    remove_reference(obj2); // Should be freed immediately

    return 0;
}
