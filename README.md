# Garbage Collector in C

A modular and efficient implementation of garbage collection techniques in C for dynamic memory management. This project serves as a foundational resource for understanding memory allocation, reclamation, and optimization in low-level programming environments.

---

## 📚 Overview

This repository implements a garbage collector for C programs, focusing on strategies like:
- **Mark-and-Sweep Algorithm:** Traverses the object graph to identify and reclaim unused memory.
- **Reference Counting:** Keeps track of object references to free unreferenced memory.
- **Custom Memory Allocator:** Manages memory blocks for efficient allocation and deallocation.

---

## ✨ Features

- **Memory Allocation Tracking**  
  Tracks all dynamically allocated memory blocks for easy management.
  
- **Garbage Collection Algorithms**  
  Includes multiple GC techniques like mark-and-sweep and reference counting.
  
- **Performance Analysis Tools**  
  Benchmarks and analyzes the memory overhead and collection efficiency.

- **Modular Design**  
  Easily extendable to support new collection strategies.

---

## 🛠️ Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/SCCSMARTCODE/garbage-collector-c.git
   ```

## 🚀 Usage

To include the garbage collector in your C project:
```c
#include "gc.h"

int main() {
    gc_init();

    void* ptr = gc_alloc(100); // Allocate 100 bytes of memory
    gc_collect();              // Trigger garbage collection

    gc_shutdown();
    return 0;
}
```

---

## 🧩 Code Structure

```
garbage-collector-c/
│
├── src/
│   ├── gc.c                     # Core garbage collector implementation
│   ├── memory_allocator.c       # Custom memory allocation logic
│   ├── mark_and_sweep.c         # Mark-and-sweep algorithm
│   ├── reference_counting.c     # Reference counting logic
│   ├── utils.c                  # Helper utilities for memory tracking
│   └── gc.h                     # Header file for garbage collector
│
├── tests/
│   ├── test_gc.c                # Unit tests for the garbage collector
│   └── test_memory_allocator.c  # Unit tests for memory allocation
│
├── docs/
│   └── algorithms.md            # Documentation for GC algorithms
│
├── benchmarks/
│   └── performance.c            # Scripts for benchmarking GC performance
│
├── Makefile                     # Build configuration
│
├── configs/
│   └── gc_config.h              # Configuration file for GC parameters
│
└── README.md
```

---

## 🔧 Key Components

1. **Memory Allocator**  
   - Allocates and tracks memory blocks with metadata.
   - Integrates with custom garbage collection algorithms.

2. **Mark-and-Sweep**  
   - Identifies unreachable objects using graph traversal.
   - Reclaims memory in a two-phase process (mark and sweep).

3. **Reference Counting**  
   - Tracks object references to identify and free unreferenced objects.

4. **Utility Functions**  
   - Provides memory inspection, logging, and debugging tools.

---

## 📊 Benchmarks

Includes performance tests to measure:
- Allocation and deallocation speed.
- Overhead caused by garbage collection.
- Memory usage efficiency.

---

## 📝 To-Do

- [ ] Add generational garbage collection.
- [ ] Improve thread safety for multi-threaded applications.
- [ ] Implement a compacting garbage collector.

---

## 🤝 Contributing

Contributions are welcome! Please open issues or submit pull requests with improvements, bug fixes, or feature additions.

---

## 🧑‍💻 Author

- **Your Name**  
  [SCCSMARTCODE](https://github.com/SCCSMARTCODE) | [LinkedIn](https://www.linkedin.com/in/emmanuelayobami/)

---

## 📜 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
