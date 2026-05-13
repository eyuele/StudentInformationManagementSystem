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



#pragma once
#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <cstdlib>




const std::unordered_map<int, std::string> majorMap = {
        {1, "Computer Science"},
        {2, "Business"},
        {3, "Management"},
        {4, "Art"}
    };
const int YEAR = 2026;

struct Student {
    int age = 0;
    int id = 0;
    int year = YEAR;
    float gpa = 0.0;
    std::string name = "";
    std::string major = "";
};
struct Dllist_Node {
    Student data;
    Dllist_Node* next;
    Dllist_Node* prev;
};


// Student Info Insert Function Decalaration 
Student studentInfo(Student& student, std::vector <int>& ID_REGISTER);

// Doubly Linked List Funcition Declaration
Dllist_Node* createNode(const Student& student);
void Dllist_insert(Dllist_Node* &head, std::vector <int>& DLLIST_ID_REGISTER);
void Dllist_delete(Dllist_Node* &head, std::vector <int>& DLLIST_ID_REGISTER); 
void Dllist_Search(Dllist_Node* head);
void Dllist_Display(Dllist_Node* head);
void Dllist_Sort(Dllist_Node* &head);
    void BubbleSort(Dllist_Node* head);
    void SelectionSort(Dllist_Node* head);
    void InsertionSort(Dllist_Node* head);
void Dllist_clear(Dllist_Node* &head);
// Single Linked List Function Declaration
// Put Your Code Here





// Stack Function Declaration 
// Put Your Code Here





// Queue Function Declaration
// Put Your Code Here   





// Tree Function Declaration
// Put Your Code Here







// Menu Function Declarations 
void slinkedlistMenu(std::vector <int>& ID_REGISTER);
void DlinkedlistMenu(Dllist_Node* &head, std::vector <int>& ID_REGISTER);
void stackMenu(std::vector <int>& ID_REGISTER);
void queueMenu(std::vector <int>& ID_REGISTER);
void treeMenu(std::vector <int>& ID_REGISTER);
void mainMenu(Dllist_Node* &Dllist_head, std::vector <int>& SLLIST_ID_REGISTER,
            std::vector <int>& DLLIST_ID_REGISTER, std::vector <int>& STACK_ID_REGISTER,
            std::vector <int>& QUEUE_ID_REGISTER, std::vector <int>& TREE_ID_REGISTER);




int main() {
    Dllist_Node* Dllist_head = nullptr;
    std::vector <int> SLLIST_ID_REGISTER;
    std::vector <int> DLLIST_ID_REGISTER;
    std::vector <int> STACK_ID_REGISTER;
    std::vector <int> QUEUE_ID_REGISTER;
    std::vector <int> TREE_ID_REGISTER;
    mainMenu(Dllist_head, SLLIST_ID_REGISTER, DLLIST_ID_REGISTER, STACK_ID_REGISTER, QUEUE_ID_REGISTER, TREE_ID_REGISTER);
    return 0;
}



// Menu Function Implementations
void DlinkedlistMenu(Dllist_Node* &Dllist_head, std::vector <int>& ID_REGISTER) {
    while (true) {
        system(CLEAR_COMMAND);
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Doubly Linked List Operations:" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "1. Insert Student Record" << std::endl;
        std::cout << "2. Delete Student Record" << std::endl;
        std::cout << "3. Search Student Record" << std::endl;
        std::cout << "4. Display All Records" << std::endl;
        std::cout << "5. Sort Records by ID" << std::endl;
        std::cout << "6. Return to Main Menu" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
            continue;
        }
        switch (choice) {
            case 1:
                Dllist_insert(Dllist_head, ID_REGISTER);
                break;
            case 2:
                Dllist_delete(Dllist_head, ID_REGISTER);
                break;
            case 3: 
                Dllist_Search(Dllist_head);
                break;
            case 4:
                Dllist_Display(Dllist_head);
                break;
            case 5:
                Dllist_Sort(Dllist_head);
                break;
            case 6:
                std::cout << "Returning to Main Menu." << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
        
    }
}
void slinkedlistMenu(std::vector <int>& ID_REGISTER) {
    while (true) {
        system(CLEAR_COMMAND);
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Single Linked List Operations:" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "1. Insert Student Record at Beginning" << std::endl;
        std::cout << "2. Delete Student Record" << std::endl;
        std::cout << "3. Search Student Record" << std::endl;
        std::cout << "4. Display All Records" << std::endl;\
        std::cout << "5. Sort Records by ID" << std::endl;
        std::cout << "6. Return to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
            continue;
        }
        switch (choice) {
            case 1:
                std::cout << "You selected Insert Student Record at Beginning." << std::endl;
                break;
            case 2:
                std::cout << "You selected Delete Student Record." << std::endl;
                break;
            case 3: 
                std::cout << "You selected Search Student Record." << std::endl;
                break;
            case 4:
                std::cout << "You selected Display All Records." << std::endl;
                break;
            case 5:
                std::cout << "You selected Sort Records by ID." << std::endl;
                break;
            case 6:
                std::cout << "Returning to Main Menu." << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
        
    }
}
void stackMenu(std::vector <int>& ID_REGISTER) {
    while (true) {
        
        system(CLEAR_COMMAND);
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Stack Operations:" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "1. Push Student Record" << std::endl;
        std::cout << "2. Pop Student Record" << std::endl;
        std::cout << "3. Peek Top Student Record" << std::endl;
        std::cout << "4. Display All Records" << std::endl;
        std::cout << "5. Sort Records by ID" << std::endl;
        std::cout << "6. Return to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
            continue;
        }
        switch (choice) {
            case 1:
                std::cout << "You selected Push Student Record." << std::endl;
                break;
            case 2:
                std::cout << "You selected Pop Student Record." << std::endl;
                break;
            case 3:
                std::cout << "You selected Peek Top Student Record." << std::endl;
                break;
            case 4:
                std::cout << "You selected Display All Records." << std::endl;
                break;
            case 5:
                std::cout << "You selected Sort Records by ID." << std::endl;
                break;
            case 6:
                std::cout << "Returning to Main Menu." << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
        
    }
}
void treeMenu(std::vector <int>& ID_REGISTER) {
    while (true){
        system(CLEAR_COMMAND);
        std::cout <<"----------------------------------------" << std::endl;
        std::cout << "Tree Operations:" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "1. Insert Student Record" << std::endl;
        std::cout << "2. Delete Student Record" << std::endl;
        std::cout << "3. Search Student Record" << std::endl;
        std::cout << "4. Traverse Tree(Inorder/Preorder/Postorder)" << std::endl;
        std::cout << "5. Sort Records by ID" << std::endl;
        std::cout << "6. Return to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
            continue;
        }
        switch (choice) {
            case 1:
                std::cout << "You selected Insert Student Record." << std::endl;
                break;
            case 2:
                std::cout << "You selected Delete Student Record." << std::endl;
                break;
            case 3:
                std::cout << "You selected Search Student Record." << std::endl;
                break;
            case 4:
                std::cout << "You selected Traverse Tree." << std::endl;
                break;
            case 5:
                std::cout << "You selected Sort Records by ID." << std::endl;
                break;
            case 6:
                std::cout << "Returning to Main Menu." << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }
}
void queueMenu(std::vector <int>& ID_REGISTER) {
    while (true) {
        system(CLEAR_COMMAND);
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Queue Operations:" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "1. Enqueue Student Record" << std::endl;
        std::cout << "2. Dequeue Student Record" << std::endl;
        std::cout << "3. Peek Front Student Record" << std::endl;
        std::cout << "4. Display All Records" << std::endl;
        std::cout << "5. Sort Records by ID" << std::endl;
        std::cout << "6. Return to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
            continue;
        }
        switch (choice) {
            case 1:
                std::cout << "You selected Enqueue Student Record." << std::endl;
                break;
            case 2:
                std::cout << "You selected Dequeue Student Record." << std::endl;
                break;
            case 3:
                std::cout << "You selected Peek Front Student Record." << std::endl;
                break;
            case 4:
                std::cout << "You selected Display All Records." << std::endl;
                break;
            case 5:
                std::cout << "You selected Sort Records by ID." << std::endl;
                break;
            case 6:
                std::cout << "Returning to Main Menu." << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
        
    }
}
void mainMenu(Dllist_Node* &Dllist_head, std::vector <int>& SLLIST_ID_REGISTER,
            std::vector <int>& DLLIST_ID_REGISTER, std::vector <int>& STACK_ID_REGISTER,
            std::vector <int>& QUEUE_ID_REGISTER, std::vector <int>& TREE_ID_REGISTER) {
    while (true) {
        system(CLEAR_COMMAND);
        std::cout << "Student Information Management System" << std::endl;
        std::cout << "Select a Data Structure:" << std::endl;
        std::cout << "1. Single Linked List" << std::endl;
        std::cout << "2. Doubly Linked List" << std::endl;
        std::cout << "3. Stack" << std::endl;
        std::cout << "4. Queue" << std::endl;
        std::cout << "5. Tree" << std::endl;
        std::cout << "6. Exit Program" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
            std::cout << "Press Enter to continue" << std::endl;
            std::cin.get();
            continue;
        }
        switch (choice) {
            case 1:
                slinkedlistMenu(SLLIST_ID_REGISTER);
                break;
            case 2:
                DlinkedlistMenu(Dllist_head, DLLIST_ID_REGISTER);
                break;
            case 3:
                stackMenu(STACK_ID_REGISTER);
                break;
            case 4:
                queueMenu(QUEUE_ID_REGISTER);
                break;
            case 5:
                treeMenu(TREE_ID_REGISTER);
                break;
            case 6:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                Dllist_clear(Dllist_head);
                exit(0);
                break;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }
}

// Student Information Insertion Function
Student studentInfo(Student& student, std::vector <int>& ID_REGISTER) {
    while (true) {
        while (true) {
            std::cout << "Enter Student Name: ";
            std::getline(std::cin, student.name);
            if (!student.name.empty()) break;
            std::cout << "Name cannot be empty. Please try again." << std::endl;
        }
        while (true) {
            std::cout << "Enter Student Age: ";
            std::cin >> student.age; 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   
            if (std::cin.fail() || student.age <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid age. Please enter a positive integer." << std::endl;
            } 
            else if (student.age <= 5) {
                std::cout << "Student is too young (must be > 5). Please try again." << std::endl;
                student.age = 0;
            }
            else {
                break; 
            }
        }
        while (true){
            int id, MIN = 1000;
            bool IsAvilable = true;
            std::cout << "Enter Student ID: ";
            std::cin >> id;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (!ID_REGISTER.empty()){
                for (int i = 0; i < ID_REGISTER.size(); i++){
                    if (ID_REGISTER[i] == id){
                        std::cout << "The id: "<< id << " Is In Use. Please Enter New ID!" << std::endl;
                        IsAvilable = false;
                        break;
                    } 
                }
                if (IsAvilable == false){
                    continue;
                }
            }
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please Enter A Valid ID!" << std::endl;
                continue;
            }
            else if (id <= MIN){
                std::cout << "The ID Must Be Above 1000!" << std::endl;
            }
            else {
                student.id = id;
                ID_REGISTER.push_back(id);
                std::cout << student.id << std::endl;
                break;
            }
        }
        while (true) {
            int choice;
            std::cout << "Enter Student Major (1-4): ";
            std::cin >> choice;  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
                continue;
            }
            
            auto it = majorMap.find(choice);
            if (it != majorMap.end()) {
                student.major = it->second;
                std::cout << "Selected Major: " << student.major << std::endl;
                break;  
            } else {
                std::cout << "Invalid choice. Please select a valid major (1-4)." << std::endl;
            }
        }
        while (true) {
            std::cout << "Enter Student GPA (0.0 - 4.0): ";
            std::cin >> student.gpa;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid GPA. Please enter a number between 0.0 and 4.0." << std::endl;
            } 
            else if (student.gpa < 0.0 || student.gpa > 4.0) {
                std::cout << "Invalid GPA. Please enter a number between 0.0 and 4.0." << std::endl;
            }else {
                break; 
            }
        }      
        break;
    }

    std::cout << "Student information recorded successfully." << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Age: " << student.age << std::endl;
    std::cout << "ID: " << student.id << std::endl;
    std::cout << "Major: " << student.major << std::endl;
    std::cout << "GPA: " << student.gpa << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    
    return student;
}

// Doubly Linked List Function Implementations
Dllist_Node* createNode(const Student& student) {
    Dllist_Node* newNode = new Dllist_Node;
    newNode->data = student;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}
void Dllist_insert(Dllist_Node* &head, std::vector <int>& ID_REGISTER) {
    Student student; 
    student = studentInfo(student, ID_REGISTER);
    
    Dllist_Node* n = createNode(student);
    if (head == nullptr) {
        head = n;
    }
    else {
        Dllist_Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
        
    }
}
void Dllist_delete(Dllist_Node* &head, std::vector <int>& ID_REGISTER) {
    int id;
    bool IsEXistes = false;
    while (true) {
        std::cout << "----------------------" << std::endl;
        std::cout << "Delete Student Record" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "Enter Student ID to delete: ";
        
        std::cin >> id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail() || id <= 1000) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid Student ID." << std::endl;
            continue;
        }
        break;
    }
    Dllist_Node* temp = head;
    if (temp == nullptr) {
        std::cout << "No student records found." << std::endl;
        std::cout << "Press Enter to continue...";
        std::cin.get(); 
        return;
    }
    for (int i = 0; i < ID_REGISTER.size(); i++){
        if (ID_REGISTER[i] == id ) {
            ID_REGISTER.erase(ID_REGISTER.begin() + i);
            IsEXistes = true;
        }
    }
    if (IsEXistes == false) {
        std::cout << "Student under this ID dosent exist" << std::endl;
        return;
    }
    while (temp != nullptr) {
        if (temp -> data.id == id) {
            if (temp -> prev != nullptr && temp -> next != nullptr) {
                temp -> prev -> next = temp -> next;
                temp -> next -> prev = temp -> prev;
                delete temp;
                std::cout << "Student record with ID " << id << " deleted successfully." << std::endl;
                std::cout << "Press Enter to continue...";
                std::cin.get(); 
                return;
            }
            else if (temp -> prev == nullptr && temp -> next != nullptr) {
                head = temp -> next;
                head -> prev = nullptr;
                delete temp;
                std::cout << "Student record with ID " << id << " deleted successfully." << std::endl;
                std::cout << "Press Enter to continue...";
                std::cin.get(); 
                return;
            }
            else if (temp -> prev != nullptr && temp -> next == nullptr) {
                temp -> prev -> next = nullptr;
                delete temp;
                std::cout << "Student record with ID " << id << " deleted successfully." << std::endl;
                std::cout << "Press Enter to continue...";
                std::cin.get(); 
                return;
            }
            else{
                head = nullptr;
                delete temp;
                std::cout << "Student record with ID " << id << " deleted successfully." << std::endl;
                std::cout << "Press Enter to continue...";
                std::cin.get(); 
                return;
            }
        }
        else if (temp -> next == nullptr) {
            std::cout << "Student record with ID: " << id << " not found." << std::endl;
            std::cout << "Press Enter to continue...";
            std::cin.get(); 
            return;
        }
        else {
            temp = temp -> next;
        }
    }
    
    
}
void Dllist_Search(Dllist_Node* head) {
    std::cout << "----------------------" << std::endl;
    std::cout << "Search Student Record" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Enter Student ID to search: ";
    int id;
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid Student ID." << std::endl;
        return;
    }
    Dllist_Node* temp = head;
    if (temp == nullptr) {
        std::cout << "No student records found." << std::endl;
        std::cout << "Press Enter to continue...";
        std::cin.get(); 
        return;
    }
    while (temp != nullptr){
        if (temp->data.id == id) {
            std::cout << "-----------------------------" << std::endl;
            std::cout << "Display Student Records" << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::cout << "Name: " << temp->data.name << std::endl;
            std::cout << "Age: " << temp->data.age << std::endl;
            std::cout << "Student ID: " << std::to_string(temp->data.id) << std::endl;
            std::cout << "Major: " << temp->data.major << std::endl;
            std::cout << "Registration year: " << temp->data.year << std::endl;
            std::cout << "GPA: " << temp->data.gpa << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::cout << "Press Enter to continue...";
            std::cin.get();
            return;
        }
        temp = temp->next;
    }
    std::cout << "Ther Is No Student Under ID: " << id << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();

}
void Dllist_Display(Dllist_Node* head) {
    
    Dllist_Node* temp = head;
    if (temp == nullptr) {
        std::cout << "No student records found." << std::endl;
        std::cout << "Press Enter to continue...";
        std::cin.get(); 
        return;
    }
    int choice;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Display Student Records" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "1. Display All Records" << std::endl;
    std::cout << "2. Display Records by Major" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (choice) {
        case 1:{
            std::cout << "Displaying all student records:" << std::endl;
            while ( temp != nullptr) {
                std::cout << "-----------------------------" << std::endl;
                std::cout << "Name: " << temp->data.name << std::endl;
                std::cout << "Age: " << temp->data.age << std::endl;
                std::cout << "Student ID: " << std::to_string(temp->data.id) << std::endl;
                std::cout << "Major: " << temp->data.major << std::endl;
                std::cout << "Registration year: " << temp->data.year << std::endl;
                std::cout << "GPA: " << temp->data.gpa << std::endl;
            
                temp = temp->next;
            }
            break;}
        case 2:{
            std::string major, temp_major = "", main_major = "";
            std::cout << "Enter Major to filter by: ";
            std::getline(std::cin, major);
            for (int i = 0; i < major.length(); i++){
                temp_major += tolower(major[i]);
            }   
            major = temp_major; 
            
            std::cout << "Displaying student records for Major: " << major << std::endl;
            while (temp != nullptr) {
                temp_major = "";
                main_major = "";
                temp_major = temp->data.major;
                for (int i = 0; i < temp->data.major.length(); i++){
                    main_major += tolower(temp_major[i]);
                }
                if (main_major == major) {
                    std::cout << "-----------------------------" << std::endl;
                    std::cout << "Name: " << temp->data.name << std::endl;
                    std::cout << "Age: " << temp->data.age << std::endl;
                    std::cout << "Student ID: " << std::to_string(temp->data.id) << std::endl;
                    std::cout << "Major: " << temp->data.major << std::endl;
                    std::cout << "Registration year: " << temp->data.year << std::endl;
                    std::cout << "GPA: " << temp->data.gpa << std::endl;
                }
                temp = temp->next;
            }
            break;
        }
        default:
            std::cout << "Invalid choice. Displaying all student records." << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
}
void Dllist_Sort(Dllist_Node* &head) {
    while (true) {
        int choice;
        std::cout << "-------------------------" << std::endl;
        std::cout << "Select Sorting Algorithm:" << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "1. Bubble Sort" << std::endl;
        std::cout << "2. Selection Sort" << std::endl;
        std::cout << "3. Insertion Sort" << std::endl;
        std::cout << "4. Return to Main Menu" << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                BubbleSort(head);
                break;
            case 2:
                SelectionSort(head);
                break;
            case 3:
                InsertionSort(head);
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid choice. Please select a valid sorting algorithm (1-4)." << std::endl;
        }
    }
}
    void BubbleSort(Dllist_Node* head) {
        if (head == nullptr) return;
        bool swapped;
        do {
            swapped = false;
            Dllist_Node* temp = head;
            while (temp->next != nullptr) {
                if (temp->data.id > temp->next->data.id) {
                    Student tempData = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = tempData;
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
        std::cout << "Bubble Sort completed!\n";
    }

    void SelectionSort(Dllist_Node* head) {
        if (head == nullptr) return;
        Dllist_Node* start = head;
        while (start != nullptr) {
            Dllist_Node* minNode = start;
            Dllist_Node* temp = start->next;
            while (temp != nullptr) {
                if (temp->data.id < minNode->data.id)
                    minNode = temp;
                temp = temp->next;
            }
            if (minNode != start) {
                Student tempData = start->data;
                start->data = minNode->data;
                minNode->data = tempData;
            }
            start = start->next;
        }
        std::cout << "Selection Sort completed!\n";
    }

    void InsertionSort(Dllist_Node* head) {
        if (head == nullptr) return;
        Dllist_Node* current = head->next;
        while (current != nullptr) {
            Dllist_Node* walk = current;
            while (walk->prev != nullptr && walk->data.id < walk->prev->data.id) {
                Student temp = walk->data;
                walk->data = walk->prev->data;
                walk->prev->data = temp;
                walk = walk->prev;
            }
            current = current->next;
        }
        std::cout << "Insertion Sort completed!\n";
    }
    
void Dllist_clear(Dllist_Node* &head) {
    while (head != nullptr) {
        Dllist_Node* temp = head;
        head = head->next;
        delete temp;
    }
}



// Single Linked List Function Implementations
// Put Your Code Here






// Stack Function Implementations 
// Put Your Code Here






// Queue Function Implementations
// Put Your Code Here   





// Tree Function Implementations
// Put Your Code Here
