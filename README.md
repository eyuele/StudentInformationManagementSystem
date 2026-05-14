Below is a **`README.md`** that combines project overview, compilation instructions, and detailed team member instructions. You can paste this directly into your repository.


# Student Information Management System (SIMS)

A C++ console application that manages student records using multiple data structures.  
Developed as a group project for a Data Structures and Algorithms course.

---

## ✅ Completed Features (by the author)

| Data Structure      | Operations                                                                 |
|---------------------|----------------------------------------------------------------------------|
| **Doubly Linked List** | Insert, delete, search, display (with case‑insensitive major filter), sort (Bubble/Selection/Insertion), clear |
| **Binary Search Tree** | Insert, delete (leaf/one child/two children), search, inorder traversal (sorted output), clear |

Both structures maintain separate `ID_REGISTER` vectors to prevent duplicate student IDs.

---

## 🧩 Team Member Tasks (to be implemented)

- **Singly Linked List** – all operations (insert, delete, search, display, sort, clear)
- **Stack** – push, pop, peek, display, sort (via temporary vector), clear
- **Queue** – enqueue, dequeue, peek, display, sort (via temporary vector), clear

Each must use the existing `studentInfo()` function and the `ID_REGISTER` vector for duplicate prevention.

---

## 🚀 Compilation & Running

### Requirements
- C++11 or later compiler (g++, clang++, MSVC)

### Compile
```bash
g++ -std=c++11 main.cpp -o sims
```

### Run
- Linux / macOS: `./sims`
- Windows: `sims.exe`

---

## 📝 Important Code Updates & Patterns

### 1. Student Input Function – `studentInfo(Student& student, std::vector<int>& ID_REGISTER)`
- **Parameters:**  
  - `student` – reference to a `Student` object (filled with user input)  
  - `ID_REGISTER` – reference to your data structure’s ID vector  
- **Behavior:**  
  - Prompts for name, age, ID, major, GPA.  
  - Validates all fields (name non‑empty, age >5, ID >1000, major 1‑4, GPA 0‑4).  
  - **Checks duplicate IDs** against the passed vector.  
  - **Does NOT add the ID to the register** – that is your responsibility after successful insertion.  
- **Returns:** the filled `Student` object.

### 2. ID_REGISTER Vectors (defined in `main()`)
```cpp
std::vector<int> SLLIST_ID_REGISTER;   // for Singly Linked List
std::vector<int> DLLIST_ID_REGISTER;   // already used
std::vector<int> STACK_ID_REGISTER;    // for Stack
std::vector<int> QUEUE_ID_REGISTER;    // for Queue
std::vector<int> TREE_ID_REGISTER;     // already used
```
These vectors are **passed by reference** to every menu and every insert/delete function.  
- **Insert:** after adding a node, call `ID_REGISTER.push_back(student.id);`  
- **Delete:** after removing the node, erase the ID:  
  ```cpp
  for (int i = 0; i < ID_REGISTER.size(); i++) {
      if (ID_REGISTER[i] == id) {
          ID_REGISTER.erase(ID_REGISTER.begin() + i);
          break;
      }
  }
  ```

### 3. I/O Handling Pattern – Follow Exactly
After every `std::cin >> variable;`, immediately clear the input buffer:
```cpp
std::cin >> choice;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // show error message and continue/return
}
```

### 4. Sorting Requirements
- **Linked Lists (Singly & Doubly):** swap the `Student` data inside nodes (not the pointers).  
- **Stack / Queue:** pop/dequeue all elements into a temporary vector, sort the vector, then push/enqueue back.

### 5. Memory Cleanup
Implement a `clear()` function that deletes all nodes and clears the ID register. The `mainMenu` already calls `Dllist_clear` and `Tree_Clear` on exit – add similar calls for your DS.

---

## 📁 Menu System – What You Fill

Each data structure already has a menu function that is called from `mainMenu`. You must **replace the placeholder `cout` statements** with calls to your own functions.

| Menu Function               | What to implement                                   |
|-----------------------------|------------------------------------------------------|
| `slinkedlistMenu(...)`      | Singly Linked List operations (insert, delete, etc.)|
| `stackMenu(...)`            | Stack operations (push, pop, peek, display, sort)   |
| `queueMenu(...)`            | Queue operations (enqueue, dequeue, display, sort)  |

> **Note:** `DlinkedlistMenu` and `treeMenu` are already fully implemented – do not modify them.

---

## 🔧 Required Functions for Each Data Structure

| Operation | Function Signature (example) | Notes |
|-----------|-----------------------------|-------|
| Insert    | `void insert(Student s, std::vector<int>& reg)` | Call `studentInfo` to get data; add ID to register after node creation |
| Delete    | `void delete(int id, std::vector<int>& reg)` | Remove node; erase ID from register |
| Search    | `void search(int id)` | Display student details if found |
| Display   | `void display()` | Show all students (optionally filter by major) |
| Sort      | `void sortMenu()` | Provide at least three sorting algorithms |
| Clear     | `void clear(std::vector<int>& reg)` | Delete all nodes; clear the register |

---

## 🧪 Example: Insert Pattern (from DLL)
```cpp
void Dllist_insert(Dllist_Node* &head, std::vector<int>& ID_REGISTER) {
    Student student;
    student = studentInfo(student, ID_REGISTER);
    Dllist_Node* n = createNode(student);
    if (head == nullptr) {
        head = n;
        ID_REGISTER.push_back(head->data.id);
    } else {
        // insert at end (or appropriate position)
        ID_REGISTER.push_back(n->data.id);
    }
}
```

---

## ❌ Common Pitfalls to Avoid

- Adding ID to register **before** node creation – if insertion fails later, the ID is wrongly marked as used.
- Forgetting to remove ID from register on deletion – causes false duplicate errors later.
- Using `std::cin.ignore()` without checking `cin.fail()` first.
- Sorting a stack/queue by manipulating internal pointers – always use a temporary vector.

---

## 🤝 Team Members & Contributions

| Team Member | Data Structure | Status      |
|-------------|----------------|-------------|
| You (author) | Doubly Linked List, BST | ✅ Complete |
| Teammate 1  | Singly Linked List      | 🟡 To do    |
| Teammate 2  | Stack                   | 🟡 To do    |
| Teammate 3  | Queue                   | 🟡 To do    |

---

## 📄 License
```Text
This project was created for educational purposes. Use at your own discretion.
```