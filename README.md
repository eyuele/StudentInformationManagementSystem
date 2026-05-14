# Student Information Management System (SIMS)

A robust, console-based C++ application designed to manage student records through various fundamental data structures. This project serves as a comprehensive demonstration of memory management, pointer manipulation, and algorithmic efficiency in C++.

## 🚀 Overview

This system allows for the management of `Student` records using five distinct architectural patterns. It includes manual implementations of searching, sorting, and traversal algorithms, providing a deep dive into how data is organized and manipulated at a low level.

### Key Learning Outcomes:
* **Manual Memory Management:** Proper use of `new` and `delete` across linked structures and trees.
* **Algorithm Implementation:** Hand-written sorting algorithms including Quick Sort and Merge Sort.
* **Cross-Platform Compatibility:** Automatic console handling for both Windows and Unix-based systems.
* **Input Robustness:** Extensive validation to prevent buffer overflows and logic errors (e.g., ID collision detection).

## 🧰 Supported Data Architectures

You can interact with the system using any of the following structures, each implemented from scratch:

1.  **Singly Linked List:** Efficient forward insertion and ID-based bubble sorting.
2.  **Doubly Linked List:** Bi-directional navigation allowing for complex pointer manipulation during node deletion and sorting.
3.  **Vector-backed Stack:** LIFO (Last-In-First-Out) implementation featuring advanced sorting (Quick/Merge).
4.  **Linked Queue:** FIFO (First-In-First-Out) structure using `front` and `rear` pointers.
5.  **Binary Search Tree (BST):** Hierarchical storage optimized for $O(\log n)$ searching and in-order traversal.

## 🧬 Data Entity: The Student

Every record maintains the following attributes:
- **Name:** Full string identifiers.
- **Age:** Validated integer (Age > 5).
- **ID:** Unique identifier (must be > 1000).
- **Major:** Computer Science, Business, Management, or Art.
- **GPA:** Floating-point value (0.0 - 4.0).
- **Year:** Defaulted to 2026.

## 🛠️ Algorithmic Suite

The project implements several sorting algorithms to organize data by different criteria:

| Algorithm | Used In | Complexity (Avg) | Organized By |
| :--- | :--- | :--- | :--- |
| **Bubble Sort** | Linked Lists | $O(n^2)$ | Student ID |
| **Selection Sort** | Stack / DLL | $O(n^2)$ | ID / Name |
| **Insertion Sort** | Stack / DLL | $O(n^2)$ | GPA |
| **Merge Sort** | Stack | $O(n \log n)$ | Student Name |
| **Quick Sort** | Stack | $O(n \log n)$ | GPA |

## 💻 Compilation & Setup

### Prerequisites
* C++11 compatible compiler (`g++`, `clang++`, or MSVC).

### Instructions
1.  **Clone the repository:**
    ```bash
    git clone https://github.com/yourusername/sims-cpp.git
    cd sims-cpp
    ```
2.  **Compile:**
    ```bash
    g++ -std=c++11 -o sims StudentInformationManagementSystem.cpp
    ```
3.  **Run:**
    ```bash
    ./sims
    ```

## 🎮 Usage Guide

1.  **Choose Architecture:** Select your preferred data structure from the main menu.
2.  **Add Records:** Enter student details; the system will automatically check for ID uniqueness.
3.  **Sort/Search:** Use the structure-specific sub-menus to organize your data.
4.  **Switching:** To switch structures, return to the main menu (data is cleared upon exit to ensure memory safety).

---
*Created as part of a C++ Data Structures & Algorithms study path. Updated May 2026.*