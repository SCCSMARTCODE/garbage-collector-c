

### **2️⃣ README for the Reference Counting Model**
This README focuses only on **Reference Counting** and clarifies that it is **not truly automated**.

#### 📄 **`README.md` (Reference Counting GC)**
# 🧮 Reference Counting Garbage Collector (C)

This is a **Reference Counting Garbage Collector** implemented in C.  
However, this is **not a fully automated GC**—it's just a **memory manager** to track references manually.

---

## ❌ Why This is NOT a True Garbage Collector
- **No Automatic Collection** – You must manually call `add_reference()` and `remove_reference()`.
- **Fails for Cyclic References** – It cannot detect objects that reference each other.
- **Not a Complete Solution** – It's just a **project manager** to track memory accountability.

---

## 🔍 How It Works
1. Each object has a **reference count** that tracks how many variables point to it.
2. If the reference count **drops to zero**, the object is **freed from memory**.
3. If a reference is assigned to another variable, the count **increases**.
4. If a reference is removed, the count **decreases**.

---

## 📂 Project Structure
```
gc_project/
│── reference_counting/
│   │── main.c  # Entry point, tests Reference Counting GC
│   │── gc.c    # Implementation of Reference Counting GC
│   │── gc.h    # Header file

```


## 🚀 Running the Reference Counting GC
### **1️⃣ Compile the Project**
```sh
make
```
### **2️⃣ Run the Program**
```sh
./gc_program
```
### **Expected Output**
```
Freeing memory for object with data: 100
Freeing memory for object with data: 200
```

---

## 🚀 Next Steps: Implementing True Automation
The next phase is implementing **Mark-and-Sweep**, which will:
✅ Automatically scan memory and free unused objects  
✅ Handle **cyclic references** (which reference counting cannot)  
✅ Be a **real automated garbage collector**  

---

## 📝 License
This project is open-source. Contributions are welcome! 🚀