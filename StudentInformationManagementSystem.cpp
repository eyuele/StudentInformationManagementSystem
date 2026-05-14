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
// Doubly Linked List Data Structure
struct Dllist_Node {
    Student data;
    Dllist_Node* next;
    Dllist_Node* prev;
};
// Tree Data Structure
struct Tree_Node {
    Student data;
    Tree_Node* left;
    Tree_Node* right;
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
void Dllist_clear(Dllist_Node* &head, std::vector <int>& ID_REGISTER);
// Single Linked List Function Declaration
// Put Your Code Here





// Stack Function Declaration 
// Put Your Code Here





// Queue Function Declaration
// Put Your Code Here   





// Tree Function Declaration
// Put Your Code Here
Tree_Node* CreateTree(Student &student);
Tree_Node* deleteRec(Tree_Node* node, int id, std::vector<int>& ID_REGISTER);
void Tree_Insert(Tree_Node* &head, std::vector <int>& ID_REGISTER);
void Tree_Delete(Tree_Node* &head, std::vector <int>& ID_REGISTER);
void Tree_Search(Tree_Node* head);
void inorderRec(Tree_Node* node);
void Tree_Traverse(Tree_Node* head);
void clearRec(Tree_Node* node);
void Tree_Clear(Tree_Node* &head, std::vector <int>& ID_REGISTER);




// Menu Function Declarations 
void slinkedlistMenu(std::vector <int>& ID_REGISTER);
void DlinkedlistMenu(Dllist_Node* &head, std::vector <int>& ID_REGISTER);
void stackMenu(std::vector <int>& ID_REGISTER);
void queueMenu(std::vector <int>& ID_REGISTER);
void treeMenu(Tree_Node* &Tlist_head, std::vector <int>& ID_REGISTER);
void mainMenu(Dllist_Node* &Dllist_head, Tree_Node* &Tlist_head, std::vector <int>& SLLIST_ID_REGISTER,
            std::vector <int>& DLLIST_ID_REGISTER, std::vector <int>& STACK_ID_REGISTER,
            std::vector <int>& QUEUE_ID_REGISTER, std::vector <int>& TREE_ID_REGISTER);




int main() {
    Dllist_Node* Dllist_head = nullptr;
    Tree_Node* Tree_head = nullptr;
    std::vector <int> SLLIST_ID_REGISTER;
    std::vector <int> DLLIST_ID_REGISTER;
    std::vector <int> STACK_ID_REGISTER;
    std::vector <int> QUEUE_ID_REGISTER;
    std::vector <int> TREE_ID_REGISTER;
    
    mainMenu(Dllist_head, Tree_head, SLLIST_ID_REGISTER, DLLIST_ID_REGISTER, STACK_ID_REGISTER, QUEUE_ID_REGISTER, TREE_ID_REGISTER);
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
void treeMenu(Tree_Node* &Tree_head, std::vector <int>& ID_REGISTER) {
    while (true){
        system(CLEAR_COMMAND);
        std::cout <<"----------------------------------------" << std::endl;
        std::cout << "Tree Operations:" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "1. Insert Student Record" << std::endl;
        std::cout << "2. Delete Student Record" << std::endl;
        std::cout << "3. Search Student Record" << std::endl;
        std::cout << "4. Traverse Tree(Inorder)" << std::endl;
        std::cout << "5. Return to Main Menu" << std::endl;
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
                Tree_Insert(Tree_head, ID_REGISTER);
                break;
            case 2:
                Tree_Delete(Tree_head, ID_REGISTER);
                break;
            case 3:
                Tree_Search(Tree_head); 
                break;
            case 4:
                Tree_Traverse(Tree_head);
                break;
            case 5:
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
void mainMenu(Dllist_Node* &Dllist_head, Tree_Node* &Tree_head, std::vector <int>& SLLIST_ID_REGISTER,
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
        std::cout << "---------------------------------------" << std::endl;
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
                treeMenu(Tree_head, TREE_ID_REGISTER);
                break;
            case 6:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                Dllist_clear(Dllist_head, DLLIST_ID_REGISTER);
                Tree_Clear(Tree_head, TREE_ID_REGISTER);
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
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please Enter A Valid ID!" << std::endl;
                continue;
            }
            else if (id <= MIN){
                std::cout << "The ID Must Be Above 1000!" << std::endl;
            }
            else {
                student.id = id;
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
        ID_REGISTER.push_back(head->data.id);
    }
    else {
        Dllist_Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
            
        }
        temp->next = n;
        n->prev = temp;
        ID_REGISTER.push_back(temp->next->data.id);
        
    }
}
void Dllist_delete(Dllist_Node* &head, std::vector <int>& ID_REGISTER) {
    int id;
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
    while (temp != nullptr) {
        if (temp -> data.id == id) {
            if (temp -> prev != nullptr && temp -> next != nullptr) {
                temp -> prev -> next = temp -> next;
                temp -> next -> prev = temp -> prev;
                delete temp;
                std::cout << "Student record with ID " << id << " deleted successfully." << std::endl;
                for (int i = 0; i < ID_REGISTER.size(); i++){
                    if (ID_REGISTER[i] == id ) {
                        ID_REGISTER.erase(ID_REGISTER.begin() + i);
                    }
                }
                std::cout << "Press Enter to continue...";
                std::cin.get(); 
                return;
            }
            else if (temp -> prev == nullptr && temp -> next != nullptr) {
                head = temp -> next;
                head -> prev = nullptr;
                delete temp;
                std::cout << "Student record with ID " << id << " deleted successfully." << std::endl;
                for (int i = 0; i < ID_REGISTER.size(); i++){
                    if (ID_REGISTER[i] == id ) {
                        ID_REGISTER.erase(ID_REGISTER.begin() + i);
                    }
                }
                std::cout << "Press Enter to continue...";
                std::cin.get(); 
                return;
            }
            else if (temp -> prev != nullptr && temp -> next == nullptr) {
                temp -> prev -> next = nullptr;
                delete temp;
                std::cout << "Student record with ID " << id << " deleted successfully." << std::endl;
                for (int i = 0; i < ID_REGISTER.size(); i++){
                    if (ID_REGISTER[i] == id ) {
                        ID_REGISTER.erase(ID_REGISTER.begin() + i);
                    }
                }
                std::cout << "Press Enter to continue...";
                std::cin.get(); 
                return;
            }
            else{
                head = nullptr;
                delete temp;
                std::cout << "Student record with ID " << id << " deleted successfully." << std::endl;
                for (int i = 0; i < ID_REGISTER.size(); i++){
                    if (ID_REGISTER[i] == id ) {
                        ID_REGISTER.erase(ID_REGISTER.begin() + i);
                    }
                }
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
            std::cout << "Found:" << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::cout << "Student Records" << std::endl;
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
                std::cout << "Student Information" << std::endl;
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
    
void Dllist_clear(Dllist_Node* &head, std::vector <int>& ID_REGISTER) {
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
Tree_Node* CreateTree(Student &student){
    Tree_Node* newNode = new Tree_Node();
    newNode -> data = student;
    newNode -> left = nullptr;
    newNode -> right = nullptr;
    return newNode;
}
Tree_Node* deleteRec(Tree_Node* node, int id, std::vector<int>& ID_REGISTER) {
    if (node == nullptr) return nullptr;
    if (id < node->data.id)
        node->left = deleteRec(node->left, id, ID_REGISTER);
    else if (id > node->data.id)
        node->right = deleteRec(node->right, id, ID_REGISTER);
    else {
        // Found the node to delete
        // Remove ID from register
        for (int i = 0; i < ID_REGISTER.size(); i++) {
            if (ID_REGISTER[i] == id) {
                ID_REGISTER.erase(ID_REGISTER.begin() + i);
                break;
            }
        }  
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            Tree_Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Tree_Node* temp = node->left;
            delete node;
            return temp;
        }
        else {
            Tree_Node* successor = node->right;
            while (successor->left != nullptr)
                successor = successor->left;
            node->data = successor->data;
            node->right = deleteRec(node->right, successor->data.id, ID_REGISTER);
        }
    }
    return node;
}
void Tree_Insert(Tree_Node* &head, std::vector <int>& ID_REGISTER){
    Student student;
    student = studentInfo(student, ID_REGISTER);
    Tree_Node* Node = CreateTree(student);
    if (head == nullptr){
        head = Node;
        ID_REGISTER.push_back(head->data.id);
    }
    else{
        Tree_Node* temp = head;
        while (temp != nullptr){
            if (Node->data.id < temp->data.id){
                if(temp->left == nullptr){
                    temp->left = Node;
                    ID_REGISTER.push_back(temp->left->data.id);
                    break;
                }
                else {
                    temp = temp->left;
                }
            }
            else {
                if(temp->right == nullptr){
                    temp->right = Node;
                    ID_REGISTER.push_back(temp->right->data.id);
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }
}
void Tree_Delete(Tree_Node* &head, std::vector <int>& ID_REGISTER){
    int id;
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
    if (head == nullptr) {
        std::cout << "No student records found." << std::endl;
        std::cout << "Press Enter to continue...";
        std::cin.get(); 
        return;
    }   
    head = deleteRec(head, id, ID_REGISTER);
}
void Tree_Search(Tree_Node* head) {
    if (head == nullptr) {
        std::cout << "Tree is empty.\n";
        std::cin.get(); return;
    }
    int id;
    std::cout << "Enter ID to search: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    Tree_Node* temp = head;
    while (temp) {
        if (id < temp->data.id)
            temp = temp->left;
        else if (id > temp->data.id)
            temp = temp->right;
        else {
            // Found
            std::cout << "Found:\n";
            std::cout << "-----------------------------" << std::endl;
            std::cout << "Student Information" << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::cout << "Name: " << temp->data.name << std::endl;
            std::cout << "Age: " << temp->data.age << std::endl;
            std::cout << "Student ID: " << std::to_string(temp->data.id) << std::endl;
            std::cout << "Major: " << temp->data.major << std::endl;
            std::cout << "Registration year: " << temp->data.year << std::endl;
            std::cout << "GPA: " << temp->data.gpa << std::endl;

            std::cout << "Press Enter to continue...";
            std::cin.get(); 
            return;
        }
    }
    std::cout << "No Student Records Under That Is Was found." << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
}
void inorderRec(Tree_Node* node) {
    if (node == nullptr) return;
    inorderRec(node->left);
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Student Information" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Name: " << node->data.name << std::endl;
    std::cout << "Age: " << node->data.age << std::endl;
    std::cout << "Student ID: " << node->data.id << std::endl;
    std::cout << "Major: " << node->data.major << std::endl;
    std::cout << "Registration year: " << node->data.year << std::endl;
    std::cout << "GPA: " << node->data.gpa << std::endl;

    inorderRec(node->right);
}
void Tree_Traverse(Tree_Node* head) {
    if (head == nullptr) {
        std::cout << "Tree is empty.\n";
    } else {
        std::cout << "Students sorted by ID:\n";
        inorderRec(head);
    }
    std::cout << "Press Enter...";
    std::cin.get();
}
void Tree_Clear(Tree_Node* &head, std::vector<int>& ID_REGISTER) {
    clearRec(head);
    head = nullptr;
    ID_REGISTER.clear();
    std::cout << "Tree cleared.\n";
}
void clearRec(Tree_Node* node) {
    if (node == nullptr) return;
    clearRec(node->left);
    clearRec(node->right);
    delete node;
}