# StudentInformationManagementSystem

/* 
 * Student Information Management System
 * =====================================
 * 
 * IMPORTANT UPDATES FOR TEAM MEMBERS (READ THIS FIRST)
 * ----------------------------------------------------
 * 
 * 1. Student Input Function - studentInfo() has been CHANGED:
 *    - Signature: Student studentInfo(Student& student, std::vector<int>& ID_REGISTER)
 *    - It now receives a vector reference to store used IDs (no global ID counter).
 *    - IDs are entered MANUALLY by the user, not auto-generated.
 *    - Each data structure must maintain its own ID_REGISTER vector (see main()).
 * 
 * 2. ID_REGISTER Vectors:
 *    - In main(), separate vectors are created for each data structure:
 *        SLLIST_ID_REGISTER, DLLIST_ID_REGISTER, STACK_ID_REGISTER, QUEUE_ID_REGISTER, TREE_ID_REGISTER.
 *    - These vectors are passed by reference to every menu function and every insert/delete function.
 *    - Use them to prevent duplicate IDs within your data structure.
 * 
 * 3. Sorting Requirement:
 *    - All data structures must implement sorting by ID.
 *    - For linked lists, simply swap the Student data inside nodes (not the pointers).
 *    - For stack/queue, pop/dequeue all elements into a vector, sort, then push/enqueue back.
 *    - For tree, inorder traversal already gives sorted order if inserted by ID.
 * 
 * 4. I/O Handling Pattern:
 *    - After every `std::cin >> variable;`, use:
 *        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 *    - This clears the newline and prevents getline/cin.get() issues.
 *    - Always check for `std::cin.fail()` after input and clear the stream.
 * 
 * 5. Major Filter (in Dllist_Display) is case‑insensitive:
 *    - It converts both user input and stored major to lowercase using tolower().
 *    - Include <cctype> and use tolower() if you implement similar filters.
 * 
 * 6. Doubly Linked List (already implemented):
 *    - Full insert, delete, search, display, and sort menu (sorting algorithms are empty stubs).
 *    - Review Dllist_insert, Dllist_delete, etc. to see the required pattern.
 * 
 * 7. Your Tasks (implement the following with the same interface style):
 *    - Singly Linked List:   functions in slinkedlistMenu() (currently placeholders)
 *    - Stack:                functions in stackMenu()
 *    - Queue:                functions in queueMenu()
 *    - Tree:                 functions in treeMenu()
 * 
 *    Each must accept the ID_REGISTER vector by reference and use it.
 * 
 * 8. Compilation:
 *    - Use C++11 or later.
 *    - All required headers are already included.
 * 
 * ------------------------------------------------------------
 * Original Project Requirements (from instructor)
 * ------------------------------------------------------------
 * - After completing your part, add brief documentation of function variables.
 * - Implement sorting.
 * - Student info insertion function implementation is on line 463-573 (may have moved, search for studentInfo).
 */


