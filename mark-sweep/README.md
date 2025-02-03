
# Mark-Sweep Garbage Collector in C

## Overview

This project implements a **Mark-Sweep Garbage Collector** for C programs. The collector is designed to work with **undirected graphs** of allocated memory and uses a background thread to periodically reclaim unused memory. The garbage collection mechanism scans the stack to mark reachable objects and then sweeps through the allocated objects to free those that are not referenced.

## Features

- **Mark-and-Sweep Algorithm:**  
  Implements the classical mark-and-sweep garbage collection strategy:
  - **Mark:** Traverse the stack to identify all reachable memory blocks.
  - **Sweep:** Iterate over the allocated objects and free any that are unmarked.

- **Threaded Garbage Collection:**  
  A dedicated GC thread runs every 2 seconds to perform garbage collection without blocking the main execution.

- **Memory Tracking:**  
  Each allocated block is wrapped in a `GcObject` that contains:
  - A pointer to the allocated memory.
  - A marker flag (`isMarked`) to indicate whether the object is in use.
  - A pointer to the next object in the tracking list.

- **Safe Stack Scanning:**  
  The collector retrieves the stack base using `pthread_getattr_np` and a local variable is used to capture the current stack pointer. This helps ensure that the scanning range is correct.

## Project Structure

```
├── Makefile
├── README.md
├── build
│   ├── gc.o
│   └── main.o
├── gc_program
├── src
│   ├── gc.c
│   ├── gc.h
│   └── main.c
└── tests
    └── test_gc.c
```

## How It Works

1. **Allocation (`gc_malloc`):**
   - Memory is allocated via `gc_malloc()`, which registers the allocated memory in the GC tracking list.
   - Each allocation logs the memory address for debugging.

2. **Garbage Collection (`gc_collect`):**
   - The collector determines the stack boundaries using a local variable (for the stack top) and `pthread_getattr_np` (for the stack base).
   - It scans the stack region, marking any tracked objects that are referenced.
   - After marking, it sweeps through the tracked objects and frees any that are unmarked.
   - Detailed log messages show the allocation and freeing of memory.

3. **Threaded Execution:**
   - A dedicated thread repeatedly calls `gc_collect()` every 2 seconds, ensuring that garbage collection runs concurrently with the main program.

## How to Build and Run

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/SCCSMARTCODE/garbage-collector-c.git
   cd garbage-collector-c/mark-sweep
   ```

2. **Compile the Project:**
   Use `gcc` (or another C compiler) to compile the source files. For example:
   ```bash
   make
   ```

3. **Run the Program:**
   ```bash
   ./gc_program
   ```

## Sample Output

```
🔵 Allocating memory...
[GC] Allocated memory at 0x55fa566d77d0
[GC] Allocated memory at 0x55fa566d7810
[MAIN] num1 = 42, num2 = 99

[GC] Running garbage collection...
[GC] Freeing memory at 0x55fa566d77d0
[GC] Freeing memory at 0x55fa566d7810

🟡 Unreferencing num1 and num2...

[GC] Running garbage collection...

[GC] Running garbage collection...

🟢 Allocating more memory...
[GC] Allocated memory at 0x55fa566d7850
[MAIN] num3 = 77

[GC] Running garbage collection...
[GC] Freeing memory at 0x55fa566d7850

[GC] Running garbage collection...
[GC] Running garbage collection...
```

## Code Overview

### GC Thread (main.c)
The main program spawns a thread that continuously calls `gc_collect()` every 2 seconds:
```c
void *gc_thread_function(void *arg) {
    (void)(arg);
    while (1) {
        sleep(2); // Run GC every 2 seconds
        pthread_mutex_lock(&gc_mutex);
        gc_collect();
        pthread_mutex_unlock(&gc_mutex);
    }
    return NULL;
}
```
The main function allocates and then later unreferences memory, showing how the GC frees unreferenced objects.

### Garbage Collector (gc.c)
Key functions in the GC:
- `gc_malloc()`: Allocates memory and registers it.
- `gc_collect()`: Scans the stack for references, marks live objects, and sweeps unused ones.
- `get_stack_base()`: Retrieves the stack base using `pthread_getattr_np`.

## Future Enhancements

- **Support for Multi-threaded Applications:** Improve synchronization across multiple threads.
- **Optimized Stack Scanning:** Refine stack boundary detection for different platforms.
- **Extended Memory Profiling:** Provide detailed statistics on allocations and collections.
- **Integration with Debuggers:** Allow interactive debugging and step-by-step tracing of GC cycles.

## License

This project is released under the MIT License.

## Author

Developed by SCCSMARTCODE as part of a learning project on implementing custom garbage collectors in C.
