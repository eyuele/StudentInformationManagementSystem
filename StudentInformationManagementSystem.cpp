#include <ios>
#include <ostream>
#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

const std::map<int, std::string> majorMap = {
    {1, "Computer Science"}, {2, "Business"}, {3, "Management"}, {4, "Art"}};
const int YEAR = 2026;

struct Student {
  int age = 0;
  int id = 0;
  int year = YEAR;
  float gpa = 0.0;
  std::string name = "";
  std::string major = "";
};
// Singly Linked List Data Structure
// Node structure for singly linked list
struct Slist_Node {
  Student data;
  Slist_Node *next;
};
// Doubly Linked List Data Structure
struct Dllist_Node {
  Student data;
  Dllist_Node *next;
  Dllist_Node *prev;
};
// Tree Data Structure
struct Tree_Node {
  Student data;
  Tree_Node *left;
  Tree_Node *right;
};
// Queue Node Structure
struct QueueNode {
  Student data;
  QueueNode *next;
  QueueNode(const Student &student) : data(student), next(nullptr) {}
};

// Global queue variables (defined once here)
static QueueNode *queueFront = nullptr;
static QueueNode *queueRear = nullptr;
static int queueCount = 0;

// Student Info Insert Function Decalaration
Student studentInfo(Student &student, std::vector<int> &ID_REGISTER);

// Doubly Linked List Funcition Declaration
Dllist_Node *createNode(const Student &student);
void Dllist_insert(Dllist_Node *&head, Dllist_Node *&tail,
                   std::vector<int> &DLLIST_ID_REGISTER);
void Dllist_delete(Dllist_Node *&head, Dllist_Node *&tail,
                   std::vector<int> &DLLIST_ID_REGISTER);
void Dllist_Search(Dllist_Node *head, Dllist_Node *tail);
void Dllist_Display(Dllist_Node *head, Dllist_Node *tail);
void Dllist_Sort(Dllist_Node *head, Dllist_Node *tail);
void BubbleSort(Dllist_Node *head, Dllist_Node *tail);
void SelectionSort(Dllist_Node *head, Dllist_Node *tail);
void InsertionSort(Dllist_Node *head, Dllist_Node *tail);
void Dllist_clear(Dllist_Node *&head, Dllist_Node *&tail,
                  std::vector<int> &ID_REGISTER);
// Single Linked List Function Declaration
Slist_Node *createSNode(const Student &s);
void displaySingly(Slist_Node *head);
void bubbleSortSingly(Slist_Node *head);
void insertIntoSingly(Slist_Node *&head, std::vector<int> &ID_REGISTER);
void deleteFromSingly(Slist_Node *&head, std::vector<int> &ID_REGISTER);
void searchSingly(Slist_Node *head);
void insertionSortSingly(Slist_Node *&head);
void freeSinglyList(Slist_Node *&head, std::vector<int> &ID_REGISTER);

// Stack Function Declaration
void pushStudent(std::vector<int> &ID_REGISTER, std::vector<Student> &stack);
void popStudent(std::vector<int> &ID_REGISTER, std::vector<Student> &stack);
void peekStack(std::vector<Student> &stack);
void displayStack(std::vector<Student> &stack);
void searchStack(std::vector<Student> &stack);
void bubbleSortStack(std::vector<Student> &stack);
void insertionSortStack(std::vector<Student> &stack);
void selectionSortStack(std::vector<Student> &stack);
void mergeSortStack(std::vector<Student> &stack);
void quickSortStack(std::vector<Student> &stack);

// Queue Function Declaration
void queueEnqueue(std::vector<int> &ID_REGISTER);
void queueDequeue(std::vector<int> &ID_REGISTER);
void queuePeek();
void queueDisplay();
void queueSort();
void queueClear(std::vector<int> &ID_REGISTER);

// Tree Function Declaration
Tree_Node *CreateTree(Student &student);
Tree_Node *deleteRec(Tree_Node *node, int id, std::vector<int> &ID_REGISTER);
void Tree_Insert(Tree_Node *&head, std::vector<int> &ID_REGISTER);
void Tree_Delete(Tree_Node *&head, std::vector<int> &ID_REGISTER);
void Tree_Search(Tree_Node *head);
void inorderRec(Tree_Node *node);
void Tree_Traverse(Tree_Node *head);
void clearRec(Tree_Node *node);
void Tree_Clear(Tree_Node *&head, std::vector<int> &ID_REGISTER);

// Menu Function Declarations
void slinkedlistMenu(Slist_Node *&Slist_head, std::vector<int> &ID_REGISTER);
void DlinkedlistMenu(Dllist_Node *&head, Dllist_Node *&tail,
                     std::vector<int> &ID_REGISTER);
void stackMenu(std::vector<int> &ID_REGISTER, std::vector<Student> &stack);
void queueMenu(std::vector<int> &ID_REGISTER);
void treeMenu(Tree_Node *&Tlist_head, std::vector<int> &ID_REGISTER);
void mainMenu(Dllist_Node *&Dllist_head, Dllist_Node *&Dllist_tail,
              Tree_Node *&Tlist_head, std::vector<Student> &stack,
              Slist_Node *&Slist_head, std::vector<int> &SLLIST_ID_REGISTER,
              std::vector<int> &DLLIST_ID_REGISTER,
              std::vector<int> &STACK_ID_REGISTER,
              std::vector<int> &QUEUE_ID_REGISTER,
              std::vector<int> &TREE_ID_REGISTER);

int main() {
  Dllist_Node *Dllist_head = nullptr;
  Dllist_Node *Dllist_tail = nullptr;
  Slist_Node *Slist_head = nullptr;
  Tree_Node *Tree_head = nullptr;
  std::vector<int> SLLIST_ID_REGISTER;
  std::vector<int> DLLIST_ID_REGISTER;
  std::vector<int> STACK_ID_REGISTER;
  std::vector<int> QUEUE_ID_REGISTER;
  std::vector<int> TREE_ID_REGISTER;
  std::vector<Student> stack;
  mainMenu(Dllist_head, Dllist_tail, Tree_head, stack, Slist_head,
           SLLIST_ID_REGISTER, DLLIST_ID_REGISTER, STACK_ID_REGISTER,
           QUEUE_ID_REGISTER, TREE_ID_REGISTER);
  return 0;
}

// Menu Function Implementations
void DlinkedlistMenu(Dllist_Node *&Dllist_head, Dllist_Node *&Dllist_tail,
                     std::vector<int> &ID_REGISTER) {
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
      std::cout << "Invalid input. Please enter a number between 1 and 6."
                << std::endl;
      std::cin.get();
      continue;
    }
    switch (choice) {
    case 1:
      Dllist_insert(Dllist_head, Dllist_tail, ID_REGISTER);
      break;
    case 2:
      Dllist_delete(Dllist_head, Dllist_tail, ID_REGISTER);
      break;
    case 3:
      Dllist_Search(Dllist_head, Dllist_tail);
      break;
    case 4:
      Dllist_Display(Dllist_head, Dllist_tail);
      break;
    case 5:
      Dllist_Sort(Dllist_head, Dllist_tail);
      break;
    case 6:
      std::cout << "Returning to Main Menu." << std::endl;
      return;
    default:
      std::cout << "Invalid choice. Please select a valid option." << std::endl;
    }
  }
}

void slinkedlistMenu(Slist_Node *&Slist_head, std::vector<int> &ID_REGISTER) {
  while (true) {
    system(CLEAR_COMMAND);
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Single Linked List Operations:" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "1. Insert Student Record at Beginning" << std::endl;
    std::cout << "2. Delete Student Record" << std::endl;
    std::cout << "3. Search Student Record" << std::endl;
    std::cout << "4. Display All Records" << std::endl;
    std::cout << "5. Bubble Sort" << std::endl;
    std::cout << "6. Insertion Sort" << std::endl;
    std::cout << "7. Return to Main Menu" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a number between 1 and 7."
                << std::endl;
      std::cin.get();
      continue;
    }
    switch (choice) {
    case 1:
      insertIntoSingly(Slist_head, ID_REGISTER);
      break;
    case 2:
      deleteFromSingly(Slist_head, ID_REGISTER);
      break;
    case 3:
      searchSingly(Slist_head);
      break;
    case 4:
      displaySingly(Slist_head);
      break;
    case 5:
      bubbleSortSingly(Slist_head);
      break;
    case 6:
      insertionSortSingly(Slist_head);
      break;
    case 7:
      std::cout << "Go Back To Main Menu" << std::endl;
      return;
    default:
      std::cout << "Invalid choice. Please select a valid option." << std::endl;
    }
    std::cin.get();
  }
}
void stackMenu(std::vector<int> &ID_REGISTER, std::vector<Student> &stack) {
  while (true) {
    system(CLEAR_COMMAND);
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Stack Operations:" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "1. Push Student Record" << std::endl;
    std::cout << "2. Pop Student Record" << std::endl;
    std::cout << "3. Peek Top Student Record" << std::endl;
    std::cout << "4. Display All Records" << std::endl;
    std::cout << "5. Search Student by ID" << std::endl;
    std::cout << "6. Sort Stack" << std::endl;
    std::cout << "7. Return to Main Menu" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Press Enter to continue...";
      std::cin.get();
      continue;
    }

    switch (choice) {
    case 1:
      pushStudent(ID_REGISTER, stack);
      break;
    case 2:
      popStudent(ID_REGISTER, stack);
      break;
    case 3:
      peekStack(stack);
      break;
    case 4:
      displayStack(stack);
      break;
    case 5:
      searchStack(stack);
      break;
    case 6: {
      system(CLEAR_COMMAND);
      std::cout << "--- Sorting Algorithms ---" << std::endl;
      std::cout << "1. Bubble sort (by name)" << std::endl;
      std::cout << "2. Insertion sort (by GPA)" << std::endl;
      std::cout << "3. Selection sort (by ID)" << std::endl;
      std::cout << "4. Merge sort (by name)" << std::endl;
      std::cout << "5. Quick sort (by GPA)" << std::endl;
      std::cout << "Enter choice: ";
      int sortChoice;
      std::cin >> sortChoice;
      std::cin.ignore();
      switch (sortChoice) {
      case 1:
        bubbleSortStack(stack);
        break;
      case 2:
        insertionSortStack(stack);
        break;
      case 3:
        selectionSortStack(stack);
        break;
      case 4:
        mergeSortStack(stack);
        break;
      case 5:
        quickSortStack(stack);
        break;
      default:
        std::cout << "Invalid choice.\n";
      }
      std::cout << "Press Enter to continue...";
      std::cin.get();
      break;
    }
    case 7:
      std::cout << "Returning to Main Menu." << std::endl;
      return;
    default:
      std::cout << "Invalid choice. Please select a valid option." << std::endl;
      std::cout << "Press Enter to continue...";
      std::cin.get();
    }
  }
}
void treeMenu(Tree_Node *&Tree_head, std::vector<int> &ID_REGISTER) {
  while (true) {
    system(CLEAR_COMMAND);
    std::cout << "----------------------------------------" << std::endl;
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
      std::cout << "Invalid input. Please enter a number between 1 and 6."
                << std::endl;
      std::cin.get();
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
    std::cin.get();
  }
}
void queueMenu(std::vector<int> &ID_REGISTER) {
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
      std::cout << "Invalid input. Please enter a number between 1 and 6."
                << std::endl;
      std::cin.get();
      continue;
    }
    switch (choice) {
    case 1:
      queueEnqueue(ID_REGISTER);
      break;
    case 2:
      queueDequeue(ID_REGISTER);
      break;
    case 3:
      queuePeek();
      break;
    case 4:
      queueDisplay();
      break;
    case 5:
      queueSort();
      break;
    case 6:
      std::cout << "Returning to Main Menu." << std::endl;
      return;
    default:
      std::cout << "Invalid choice. Please select a valid option." << std::endl;
    }
    std::cin.get();
  }
}
void mainMenu(Dllist_Node *&Dllist_head, Dllist_Node *&Dllist_tail,
              Tree_Node *&Tree_head, std::vector<Student> &stack,
              Slist_Node *&Slist_head, std::vector<int> &SLLIST_ID_REGISTER,
              std::vector<int> &DLLIST_ID_REGISTER,
              std::vector<int> &STACK_ID_REGISTER,
              std::vector<int> &QUEUE_ID_REGISTER,
              std::vector<int> &TREE_ID_REGISTER) {
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
      std::cout << "Invalid input. Please enter a number between 1 and 6."
                << std::endl;
      std::cout << "Press Enter to continue" << std::endl;
      std::cin.get();
      continue;
    }
    switch (choice) {
    case 1:
      slinkedlistMenu(Slist_head, SLLIST_ID_REGISTER);
      break;
    case 2:
      DlinkedlistMenu(Dllist_head, Dllist_tail, DLLIST_ID_REGISTER);
      break;
    case 3:
      stackMenu(STACK_ID_REGISTER, stack);
      break;
    case 4:
      queueMenu(QUEUE_ID_REGISTER);
      break;
    case 5:
      treeMenu(Tree_head, TREE_ID_REGISTER);
      break;
    case 6:
      std::cout << "Exiting program. Goodbye!" << std::endl;
      Dllist_clear(Dllist_head, Dllist_tail, DLLIST_ID_REGISTER);
      Tree_Clear(Tree_head, TREE_ID_REGISTER);
      freeSinglyList(Slist_head, SLLIST_ID_REGISTER);
      queueClear(QUEUE_ID_REGISTER);
      exit(0);
      break;
    default:
      std::cout << "Invalid choice. Please select a valid option." << std::endl;
    }
    std::cin.get();
  }
}

// Student Information Insertion Function
Student studentInfo(Student &student, std::vector<int> &ID_REGISTER) {
  while (true) {
    while (true) {
      std::cout << "Enter Student Name: ";
      std::getline(std::cin, student.name);
      if (!student.name.empty())
        break;
      std::cout << "Name cannot be empty. Please try again." << std::endl;
    }
    while (true) {
      std::cout << "Enter Student Age: ";
      std::cin >> student.age;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (std::cin.fail() || student.age <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid age. Please enter a positive integer."
                  << std::endl;
      } else if (student.age <= 5) {
        std::cout << "Student is too young (must be > 5). Please try again."
                  << std::endl;
        student.age = 0;
      } else {
        break;
      }
    }
    while (true) {
      int id, MIN = 1000;
      bool IsAvilable = true;
      std::cout << "Enter Student ID: ";
      std::cin >> id;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (!ID_REGISTER.empty()) {
        for (int i = 0; i < (int)ID_REGISTER.size(); i++) {
          if (ID_REGISTER[i] == id) {
            std::cout << "The id: " << id << " Is In Use. Please Enter New ID!"
                      << std::endl;
            IsAvilable = false;
            break;
          }
        }
        if (IsAvilable == false) {
          continue;
        }
      }
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please Enter A Valid ID!" << std::endl;
        continue;
      } else if (id <= MIN) {
        std::cout << "The ID Must Be Above 1000!" << std::endl;
      } else {
        student.id = id;
        std::cout << student.id << std::endl;
        break;
      }
    }
    while (true) {
      int choice;
      for (auto it = majorMap.begin(); it != majorMap.end(); ++it) {
        std::cout << it->first << " : " << it->second << "\n";
      }
      std::cout << "Enter Student Major (1-4): ";
      std::cin >> choice;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between 1 and 4."
                  << std::endl;
        continue;
      }

      auto it = majorMap.find(choice);
      if (it != majorMap.end()) {
        student.major = it->second;
        std::cout << "Selected Major: " << student.major << std::endl;
        break;
      } else {
        std::cout << "Invalid choice. Please select a valid major (1-4)."
                  << std::endl;
      }
    }
    while (true) {
      std::cout << "Enter Student GPA (0.0 - 4.0): ";
      std::cin >> student.gpa;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid GPA. Please enter a number between 0.0 and 4.0."
                  << std::endl;
      } else if (student.gpa < 0.0 || student.gpa > 4.0) {
        std::cout << "Invalid GPA. Please enter a number between 0.0 and 4.0."
                  << std::endl;
      } else {
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
Dllist_Node *createNode(const Student &student) {
  Dllist_Node *newNode = new Dllist_Node;
  newNode->data = student;
  newNode->next = nullptr;
  newNode->prev = nullptr;
  return newNode;
}
void Dllist_insert(Dllist_Node *&head, Dllist_Node *&tail,
                   std::vector<int> &ID_REGISTER) {
  Student student;
  student = studentInfo(student, ID_REGISTER);

  Dllist_Node *n = createNode(student);
  if (head == nullptr) {
    head = n;
    tail = n;
    ID_REGISTER.push_back(n->data.id);
  } else {
    tail->next = n;
    n->prev = tail;
    tail = n;
    ID_REGISTER.push_back(n->data.id);
  }
}
void Dllist_delete(Dllist_Node *&head, Dllist_Node *&tail,
                   std::vector<int> &ID_REGISTER) {
  int id;
  Dllist_Node *temp = head;
  if (temp == nullptr) {
    std::cout << "No student records found." << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return;
  }
  while (true) {
    std::cout << "----------------------" << std::endl;
    std::cout << "Delete Student Record" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Enter Student ID to delete: ";

    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a valid Student ID."
                << std::endl;
      continue;
    }
    else if (id <= 1000) {
        std::cout << "!!!Invalid ID number!!!" << std::endl;
        continue;
    }
    break;
  }
  while (temp != nullptr) {
    if (temp->data.id == id) {
      if (temp->prev != nullptr && temp->next != nullptr) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
      } else if (temp->prev == nullptr && temp->next != nullptr) {
        head = temp->next;
        head->prev = nullptr;
      } else if (temp->prev != nullptr && temp->next == nullptr) {
        temp->prev->next = nullptr;
        tail = temp->prev;
      } else {
        head = nullptr;
        tail = nullptr;
      }
      delete temp;
      std::cout << "Student record with ID " << id << " deleted successfully."
                << std::endl;
      for (int i = 0; i < (int)ID_REGISTER.size(); i++) {
        if (ID_REGISTER[i] == id) {
          ID_REGISTER.erase(ID_REGISTER.begin() + i);
          break;
        }
      }
      std::cout << "Press Enter to continue...";
      std::cin.get();
      return;
    } else if (temp->next == nullptr) {
      std::cout << "Student record with ID: " << id << " not found."
                << std::endl;
      std::cout << "Press Enter to continue...";
      std::cin.get();
      return;
    } else {
      temp = temp->next;
    }
  }
}
void Dllist_Search(Dllist_Node *head, Dllist_Node *tail) {
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
  if (head == nullptr) {
    std::cout << "No student records found." << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return;
  }

  // Search from both ends simultaneously using head and tail
  Dllist_Node *left = head;
  Dllist_Node *right = tail;
  while (left != nullptr && right != nullptr) {
    if (left->data.id == id || right->data.id == id) {
      Dllist_Node *found = (left->data.id == id) ? left : right;
      std::cout << "Found:" << std::endl;
      std::cout << "-----------------------------" << std::endl;
      std::cout << "Student Records" << std::endl;
      std::cout << "-----------------------------" << std::endl;
      std::cout << "Name: " << found->data.name << std::endl;
      std::cout << "Age: " << found->data.age << std::endl;
      std::cout << "Student ID: " << std::to_string(found->data.id)
                << std::endl;
      std::cout << "Major: " << found->data.major << std::endl;
      std::cout << "Registration year: " << found->data.year << std::endl;
      std::cout << "GPA: " << found->data.gpa << std::endl;
      std::cout << "-----------------------------" << std::endl;
      std::cout << "Press Enter to continue...";
      std::cin.get();
      return;
    }
    // Stop when the two pointers meet or cross
    if (left == right || left->next == right)
      break;
    left = left->next;
    right = right->prev;
  }
  std::cout << "There Is No Student Under ID: " << id << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void Dllist_Display(Dllist_Node *head, Dllist_Node *tail) {
  if (head == nullptr) {
    std::cout << "No student records found." << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return;
  }
  int choice;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Display Student Records" << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "1. Display All Records (head -> tail)" << std::endl;
  std::cout << "2. Display All Records (tail -> head)" << std::endl;
  std::cout << "3. Display Records by Major" << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Enter your choice: ";
  std::cin >> choice;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  auto printNode = [](Dllist_Node *node) {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Student Information" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Name: " << node->data.name << std::endl;
    std::cout << "Age: " << node->data.age << std::endl;
    std::cout << "Student ID: " << std::to_string(node->data.id) << std::endl;
    std::cout << "Major: " << node->data.major << std::endl;
    std::cout << "Registration year: " << node->data.year << std::endl;
    std::cout << "GPA: " << node->data.gpa << std::endl;
  };

  switch (choice) {
  case 1: {
    std::cout << "Displaying all student records (head -> tail):" << std::endl;
    Dllist_Node *temp = head;
    while (temp != nullptr) {
      printNode(temp);
      temp = temp->next;
    }
    break;
  }
  case 2: {
    std::cout << "Displaying all student records (tail -> head):" << std::endl;
    Dllist_Node *temp = tail; // <-- tail: walk backwards
    while (temp != nullptr) {
      printNode(temp);
      temp = temp->prev;
    }
    break;
  }
  case 3: {
    std::string major, temp_major = "", main_major = "";
    std::cout << "Enter Major to filter by: ";
    std::getline(std::cin, major);
    for (int i = 0; i < (int)major.length(); i++)
      temp_major += tolower(major[i]);
    major = temp_major;
    std::cout << "Displaying student records for Major: " << major << std::endl;
    Dllist_Node *temp = head;
    while (temp != nullptr) {
      temp_major = "";
      main_major = "";
      temp_major = temp->data.major;
      for (int i = 0; i < (int)temp->data.major.length(); i++)
        main_major += tolower(temp_major[i]);
      if (main_major == major) {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Name: " << temp->data.name << std::endl;
        std::cout << "Age: " << temp->data.age << std::endl;
        std::cout << "Student ID: " << std::to_string(temp->data.id)
                  << std::endl;
        std::cout << "Major: " << temp->data.major << std::endl;
        std::cout << "Registration year: " << temp->data.year << std::endl;
        std::cout << "GPA: " << temp->data.gpa << std::endl;
      }
      temp = temp->next;
    }
    break;
  }
  default:
    std::cout << "Invalid choice." << std::endl;
  }
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void Dllist_Sort(Dllist_Node *head, Dllist_Node *tail) {
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
      std::cout << "Invalid input. Please enter a number between 1 and 4."
                << std::endl;
      continue;
    }

    switch (choice) {
    case 1:
      BubbleSort(head, tail);
      break;
    case 2:
      SelectionSort(head, tail);
      break;
    case 3:
      InsertionSort(head, tail);
      break;
    case 4:
      return;
    default:
      std::cout
          << "Invalid choice. Please select a valid sorting algorithm (1-4)."
          << std::endl;
    }
  }
}
void BubbleSort(Dllist_Node *head, Dllist_Node *tail) {
  if (head == nullptr)
    return;
  bool swapped;
  do {
    swapped = false;
    Dllist_Node *temp = head;
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
void SelectionSort(Dllist_Node *head, Dllist_Node *tail) {
  if (head == nullptr)
    return;
  Dllist_Node *start = head;
  while (start != nullptr) {
    Dllist_Node *minNode = start;
    Dllist_Node *temp = start->next;
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
void InsertionSort(Dllist_Node *head, Dllist_Node *tail) {
  if (head == nullptr)
    return;
  Dllist_Node *current = head->next;
  while (current != nullptr) {
    Dllist_Node *walk = current;
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
void Dllist_clear(Dllist_Node *&head, Dllist_Node *&tail,
                  std::vector<int> &ID_REGISTER) {
  while (head != nullptr) {
    Dllist_Node *temp = head;
    head = head->next;
    delete temp;
  }
  tail = nullptr; // <-- tail: reset on clear
  ID_REGISTER.clear();
}

// Single Linked List Function Implementations
Slist_Node *createSNode(const Student &s) {
  Slist_Node *newNode = new Slist_Node;
  newNode->data = s;
  newNode->next = nullptr;
  return newNode;
}
void displaySingly(Slist_Node *head) {
  if (head == nullptr) {
    std::cout << "\n--- No student records found. ---\n";
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return;
  }
  std::cout << "\n--- Student Records (Singly Linked List) ---\n";
  Slist_Node *current = head;
  while (current != nullptr) {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Student Information" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Name: " << current->data.name << std::endl;
    std::cout << "Age: " << current->data.age << std::endl;
    std::cout << "Student ID: " << std::to_string(current->data.id)
              << std::endl;
    std::cout << "Major: " << current->data.major << std::endl;
    std::cout << "Registration year: " << current->data.year << std::endl;
    std::cout << "GPA: " << current->data.gpa << std::endl;
    current = current->next;
  }
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void insertIntoSingly(Slist_Node *&head, std::vector<int> &ID_REGISTER) {
  Student s;
  s = studentInfo(s, ID_REGISTER);
  Slist_Node *newNode = createSNode(s);
  if (head == nullptr) {
    head = newNode;
    ID_REGISTER.push_back(head->data.id);
  } else {
    Slist_Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
    ID_REGISTER.push_back(temp->next->data.id);
  }
  bubbleSortSingly(head);
  std::cout << "List automatically sorted by ID after insertion.\n";
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void deleteFromSingly(Slist_Node *&head, std::vector<int> &ID_REGISTER) {
  if (head == nullptr) {
    std::cout << "List is empty. Nothing to delete.\n";
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return;
  }
  int id;
  std::cout << "Enter Student ID to delete: ";
  std::cin >> id;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid ID.\n";
    return;
  }
  Slist_Node *current = head;
  Slist_Node *previous = nullptr;
  while (current != nullptr && current->data.id != id) {
    previous = current;
    current = current->next;
  }
  if (current == nullptr) {
    std::cout << "Student with ID " << id << " not found.\n";
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return;
  }
  if (previous == nullptr) {
    head = current->next;
  } else {
    previous->next = current->next;
  }
  delete current;
  for (int i = 0; i < (int)ID_REGISTER.size(); i++) {
    if (ID_REGISTER[i] == id) {
      ID_REGISTER.erase(ID_REGISTER.begin() + i);
      break;
    }
  }
  std::cout << "Student ID " << id << " deleted successfully.\n";
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void searchSingly(Slist_Node *head) {
  if (head == nullptr) {
    std::cout << "List is empty. No students to search.\n";
    return;
  }
  int id;
  std::cout << "Enter Student ID to search: ";
  std::cin >> id;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid ID.\n";
    return;
  }
  Slist_Node *current = head;
  while (current != nullptr && current->data.id != id) {
    current = current->next;
  }
  if (current != nullptr) {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Student Information" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Name: " << current->data.name << std::endl;
    std::cout << "Age: " << current->data.age << std::endl;
    std::cout << "Student ID: " << std::to_string(current->data.id)
              << std::endl;
    std::cout << "Major: " << current->data.major << std::endl;
    std::cout << "Registration year: " << current->data.year << std::endl;
    std::cout << "GPA: " << current->data.gpa << std::endl;
  } else {
    std::cout << "Student with ID " << id << " not found.\n";
  }
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void bubbleSortSingly(Slist_Node *head) {
  if (head == nullptr || head->next == nullptr) {
    std::cout << "List too small to sort (need at least 2 nodes).\n";
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return;
  }
  bool swapped;
  do {
    swapped = false;
    Slist_Node *current = head;
    while (current->next != nullptr) {
      if (current->data.id > current->next->data.id) {
        Student temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;
        swapped = true;
      }
      current = current->next;
    }
  } while (swapped);
  std::cout << "Bubble sort completed.\n";
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void insertionSortSingly(Slist_Node *&head) {
  if (head == nullptr || head->next == nullptr) {
    std::cout << "List too small to sort (need at least 2 nodes).\n";
    return;
  }
  Slist_Node *sorted = nullptr;
  Slist_Node *current = head;
  while (current != nullptr) {
    Slist_Node *nextNode = current->next;
    if (sorted == nullptr || sorted->data.id >= current->data.id) {
      current->next = sorted;
      sorted = current;
    } else {
      Slist_Node *temp = sorted;
      while (temp->next != nullptr && temp->next->data.id < current->data.id) {
        temp = temp->next;
      }
      current->next = temp->next;
      temp->next = current;
    }
    current = nextNode;
  }
  head = sorted;
  std::cout << "Insertion sort completed.\n";
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void freeSinglyList(Slist_Node *&head, std::vector<int> &ID_REGISTER) {
  while (head != nullptr) {
    Slist_Node *temp = head;
    head = head->next;
    delete temp;
    ID_REGISTER.clear();
  }
}

// Stack Function Implementations
void pushStudent(std::vector<int> &ID_REGISTER, std::vector<Student> &stack) {
  Student newStudent;
  newStudent = studentInfo(newStudent, ID_REGISTER);
  stack.push_back(newStudent);
  ID_REGISTER.push_back(newStudent.id);
  std::cout << "\nStudent pushed onto stack.\n";
  std::cout << "Press Enter...";
  std::cin.get();
}
void popStudent(std::vector<int> &ID_REGISTER, std::vector<Student> &stack) {
  if (stack.empty()) {
    std::cout << "Stack is empty.\n";
    std::cout << "Press Enter...";
    std::cin.get();
    return;
  }
  int id = stack.back().id;
  for (size_t i = 0; i < ID_REGISTER.size(); ++i) {
    if (ID_REGISTER[i] == id) {
      ID_REGISTER.erase(ID_REGISTER.begin() + i);
      break;
    }
  }
  std::cout << "Popped: " << stack.back().name << " (ID: " << id << ")\n";
  stack.pop_back();
  std::cout << "Press Enter...";
  std::cin.get();
}
void peekStack(std::vector<Student> &stack) {
  if (stack.empty()) {
    std::cout << "Stack is empty.\n";
  } else {
    std::cout << "Top Student:\n";
    std::cout << "ID: " << stack.back().id << " | Name: " << stack.back().name
              << " | Age: " << stack.back().age
              << " | Major: " << stack.back().major
              << " | GPA: " << stack.back().gpa << "\n";
  }
  std::cout << "Press Enter...";
  std::cin.get();
}
void displayStack(std::vector<Student> &stack) {
  if (stack.empty()) {
    std::cout << "Stack is empty.\n";
    std::cout << "Press Enter...";
    std::cin.get();
    return;
  }
  std::cout << "\n--- Stack (top to bottom) ---\n";
  for (int i = stack.size() - 1; i >= 0; --i) {
    std::cout << "ID: " << stack[i].id << " | Name: " << stack[i].name
              << " | Age: " << stack[i].age << " | Major: " << stack[i].major
              << " | GPA: " << stack[i].gpa << "\n";
  }
  std::cout << "-------------------------------\n";
  std::cout << "Press Enter...";
  std::cin.get();
}
void searchStack(std::vector<Student> &stack) {
  if (stack.empty()) {
    std::cout << "Stack is empty.\n";
    std::cout << "Press Enter...";
    std::cin.get();
    return;
  }
  int id;
  std::cout << "Enter Student ID to search: ";
  std::cin >> id;
  std::cin.ignore();
  for (int i = stack.size() - 1; i >= 0; --i) {
    if (stack[i].id == id) {
      std::cout << "Found at position " << (stack.size() - 1 - i)
                << " (top = 0)\n";
      std::cout << "Name: " << stack[i].name << ", Major: " << stack[i].major
                << "\n";
      std::cout << "Press Enter...";
      std::cin.get();
      return;
    }
  }
  std::cout << "Student ID " << id << " not found.\n";
  std::cout << "Press Enter...";
  std::cin.get();
}
void bubbleSortStack(std::vector<Student> &stack) {
  if (stack.empty())
    return;
  int n = stack.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (stack[j].name < stack[j + 1].name) {
        std::swap(stack[j], stack[j + 1]);
      }
    }
  }
  std::cout << "Stack sorted by name in descending order (Bubble sort).\n";
}
void insertionSortStack(std::vector<Student> &stack) {
  std::vector<Student> vec = stack;
  int n = vec.size();
  for (int i = 1; i < n; ++i) {
    Student key = vec[i];
    int j = i - 1;
    while (j >= 0 && vec[j].gpa > key.gpa) {
      vec[j + 1] = vec[j];
      --j;
    }
    vec[j + 1] = key;
  }
  stack = vec;
  std::cout << "Sorted by GPA (Insertion sort).\n";
}
void selectionSortStack(std::vector<Student> &stack) {
  std::vector<Student> vec = stack;
  int n = vec.size();
  for (int i = 0; i < n - 1; ++i) {
    int minIdx = i;
    for (int j = i + 1; j < n; ++j)
      if (vec[j].id < vec[minIdx].id)
        minIdx = j;
    std::swap(vec[i], vec[minIdx]);
  }
  stack = vec;
  std::cout << "Sorted by ID (Selection sort).\n";
}
void merge(std::vector<Student> &arr, int left, int mid, int right) {
  int n1 = mid - left + 1, n2 = right - mid;
  std::vector<Student> L(n1), R(n2);
  for (int i = 0; i < n1; ++i)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; ++j)
    R[j] = arr[mid + 1 + j];
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i].name <= R[j].name)
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}
void mergeSort(std::vector<Student> &arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}
void mergeSortStack(std::vector<Student> &stack) {
  std::vector<Student> vec = stack;
  mergeSort(vec, 0, vec.size() - 1);
  stack = vec;
  std::cout << "Sorted by name (Merge sort).\n";
}
int partition(std::vector<Student> &arr, int low, int high) {
  float pivot = arr[high].gpa;
  int i = low - 1;
  for (int j = low; j < high; ++j) {
    if (arr[j].gpa <= pivot) {
      ++i;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}
void quickSort(std::vector<Student> &arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
void quickSortStack(std::vector<Student> &stack) {
  std::vector<Student> vec = stack;
  quickSort(vec, 0, vec.size() - 1);
  stack = vec;
  std::cout << "Sorted by GPA (Quick sort).\n";
}

// Queue Function Implementations
bool isQueueEmpty() { return queueFront == nullptr; }
void queueEnqueue(std::vector<int> &ID_REGISTER) {
  Student student;
  student = studentInfo(student, ID_REGISTER);

  QueueNode *newNode = new QueueNode(student);

  if (isQueueEmpty()) {
    queueFront = queueRear = newNode;
  } else {
    queueRear->next = newNode;
    queueRear = newNode;
  }
  queueCount++;
  ID_REGISTER.push_back(student.id);

  std::cout << "Student enqueued successfully!" << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void queueDequeue(std::vector<int> &ID_REGISTER) {
  if (isQueueEmpty()) {
    std::cout << "Queue is empty! No records to dequeue." << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return;
  }

  for (size_t i = 0; i < ID_REGISTER.size(); i++) {
    if (ID_REGISTER[i] == queueFront->data.id) {
      ID_REGISTER.erase(ID_REGISTER.begin() + i);
      break;
    }
  }

  QueueNode *temp = queueFront;
  std::cout << "Dequeued student: " << temp->data.name
            << " (ID: " << temp->data.id << ")" << std::endl;

  queueFront = queueFront->next;
  if (queueFront == nullptr) {
    queueRear = nullptr;
  }
  delete temp;
  queueCount--;

  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void queuePeek() {
  if (isQueueEmpty()) {
    std::cout << "Queue is empty! No records to peek." << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return;
  }

  std::cout << "=============================" << std::endl;
  std::cout << "Front Student Record" << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Name: " << queueFront->data.name << std::endl;
  std::cout << "Age: " << queueFront->data.age << std::endl;
  std::cout << "Student ID: " << queueFront->data.id << std::endl;
  std::cout << "Major: " << queueFront->data.major << std::endl;
  std::cout << "Registration year: " << queueFront->data.year << std::endl;
  std::cout << "GPA: " << queueFront->data.gpa << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void queueDisplay() {
  if (isQueueEmpty()) {
    std::cout << "Queue is empty! No records to display." << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return;
  }

  std::cout << "=============================" << std::endl;
  std::cout << "Queue Records (Front to Rear)" << std::endl;
  std::cout << "=============================" << std::endl;

  QueueNode *temp = queueFront;
  int position = 1;
  while (temp != nullptr) {
    std::cout << "\n--- Record " << position++ << " ---" << std::endl;
    std::cout << "Name: " << temp->data.name << std::endl;
    std::cout << "Age: " << temp->data.age << std::endl;
    std::cout << "Student ID: " << temp->data.id << std::endl;
    std::cout << "Major: " << temp->data.major << std::endl;
    std::cout << "Registration year: " << temp->data.year << std::endl;
    std::cout << "GPA: " << temp->data.gpa << std::endl;
    temp = temp->next;
  }
  std::cout << "\n=============================" << std::endl;
  std::cout << "Total students in queue: " << queueCount << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void queueSort() {
  if (isQueueEmpty() || queueFront->next == nullptr) {
    std::cout << "Not enough elements to sort (need at least 2)." << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return;
  }

  std::vector<Student> students;
  QueueNode *temp = queueFront;
  while (temp != nullptr) {
    students.push_back(temp->data);
    temp = temp->next;
  }

  for (size_t i = 0; i < students.size() - 1; i++) {
    for (size_t j = 0; j < students.size() - i - 1; j++) {
      if (students[j].id > students[j + 1].id) {
        Student tempSwap = students[j];
        students[j] = students[j + 1];
        students[j + 1] = tempSwap;
      }
    }
  }

  while (!isQueueEmpty()) {
    QueueNode *del = queueFront;
    queueFront = queueFront->next;
    delete del;
  }
  queueFront = queueRear = nullptr;
  queueCount = 0;

  for (const auto &student : students) {
    QueueNode *newNode = new QueueNode(student);
    if (isQueueEmpty()) {
      queueFront = queueRear = newNode;
    } else {
      queueRear->next = newNode;
      queueRear = newNode;
    }
    queueCount++;
  }

  std::cout << "Queue sorted by ID successfully!" << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void queueClear(std::vector<int> &ID_REGISTER) {
  while (!isQueueEmpty()) {
    QueueNode *temp = queueFront;
    queueFront = queueFront->next;
    delete temp;
  }
  queueFront = queueRear = nullptr;
  queueCount = 0;
  ID_REGISTER.clear();
}

// Tree Function Implementations
Tree_Node *CreateTree(Student &student) {
  Tree_Node *newNode = new Tree_Node();
  newNode->data = student;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}
Tree_Node *deleteRec(Tree_Node *node, int id, std::vector<int> &ID_REGISTER) {
  if (node == nullptr)
    return nullptr;
  if (id < node->data.id)
    node->left = deleteRec(node->left, id, ID_REGISTER);
  else if (id > node->data.id)
    node->right = deleteRec(node->right, id, ID_REGISTER);
  else {
    for (int i = 0; i < (int)ID_REGISTER.size(); i++) {
      if (ID_REGISTER[i] == id) {
        ID_REGISTER.erase(ID_REGISTER.begin() + i);
        break;
      }
    }
    if (node->left == nullptr && node->right == nullptr) {
      delete node;
      return nullptr;
    } else if (node->left == nullptr) {
      Tree_Node *temp = node->right;
      delete node;
      return temp;
    } else if (node->right == nullptr) {
      Tree_Node *temp = node->left;
      delete node;
      return temp;
    } else {
      Tree_Node *successor = node->right;
      while (successor->left != nullptr)
        successor = successor->left;
      node->data = successor->data;
      node->right = deleteRec(node->right, successor->data.id, ID_REGISTER);
    }
  }
  return node;
}
void Tree_Insert(Tree_Node *&head, std::vector<int> &ID_REGISTER) {
  Student student;
  student = studentInfo(student, ID_REGISTER);
  Tree_Node *Node = CreateTree(student);
  if (head == nullptr) {
    head = Node;
    ID_REGISTER.push_back(head->data.id);
  } else {
    Tree_Node *temp = head;
    while (temp != nullptr) {
      if (Node->data.id < temp->data.id) {
        if (temp->left == nullptr) {
          temp->left = Node;
          ID_REGISTER.push_back(temp->left->data.id);
          break;
        } else {
          temp = temp->left;
        }
      } else {
        if (temp->right == nullptr) {
          temp->right = Node;
          ID_REGISTER.push_back(temp->right->data.id);
          break;
        } else {
          temp = temp->right;
        }
      }
    }
  }
}
void Tree_Delete(Tree_Node *&head, std::vector<int> &ID_REGISTER) {
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
      std::cout << "Invalid input. Please enter a valid Student ID."
                << std::endl;
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
void Tree_Search(Tree_Node *head) {
  if (head == nullptr) {
    std::cout << "Tree is empty.\n";
    std::cin.get();
    return;
  }
  int id;
  std::cout << "Enter ID to search: ";
  std::cin >> id;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  Tree_Node *temp = head;
  while (temp) {
    if (id < temp->data.id)
      temp = temp->left;
    else if (id > temp->data.id)
      temp = temp->right;
    else {
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
  std::cout << "No Student Records Under That ID Was Found." << std::endl;
  std::cout << "Press Enter to continue...";
  std::cin.get();
}
void inorderRec(Tree_Node *node) {
  if (node == nullptr)
    return;
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
void Tree_Traverse(Tree_Node *head) {
  if (head == nullptr) {
    std::cout << "Tree is empty.\n";
  } else {
    std::cout << "Students sorted by ID:\n";
    inorderRec(head);
  }
  std::cout << "Press Enter...";
  std::cin.get();
}
void Tree_Clear(Tree_Node *&head, std::vector<int> &ID_REGISTER) {
  clearRec(head);
  head = nullptr;
  ID_REGISTER.clear();
  std::cout << "Tree cleared.\n";
}
void clearRec(Tree_Node *node) {
  if (node == nullptr)
    return;
  clearRec(node->left);
  clearRec(node->right);
  delete node;
}