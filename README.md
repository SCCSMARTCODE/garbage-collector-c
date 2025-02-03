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


---

## 🧩 Code Structure

```
garbage-collector-c/
├── LICENSE
├── README.md
├── mark-sweep
│   ├── Makefile
│   ├── README.md
│   ├── build
│   │   ├── gc.o
│   │   └── main.o
│   ├── gc_program
│   ├── src
│   │   ├── gc.c
│   │   ├── gc.h
│   │   └── main.c
│   └── tests
│       └── test_gc.c
└── reference-counter-gc
    ├── Makefile
    ├── README.md
    ├── gc.c
    ├── gc.h
    ├── gc_program
    └── main.c
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
