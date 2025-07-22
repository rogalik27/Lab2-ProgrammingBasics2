#include <iostream>
#include <cstring>

using namespace std;

struct Student {
    unsigned int id;
    char* familyName;
    int grades[8];
};

struct Node {
    Student* student;
    Node* prev;
    Node* next;
};

void printStudent(Student& student) {
    cout << "Id: " << student.id << "\tName: " << student.familyName << "\tGrades: ";
    for (int i = 0; i < 8; i++) {
        cout << student.grades[i] << " ";
    }
    cout << "\n";
}

void printStudents(Node* head) {
    Node* current = head;
    while (current) {
        printStudent(*current->student);
        current = current->next;
    }
}

void appendStudent(Node*& head, Node*& tail, Student* student) {
    Node* newNode = new Node{student, tail, nullptr};
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void sortStudents(Node* head) {
    for (Node* i = head; i && i->next; i = i->next) {
        Node* min = i;
        for (Node* j = i->next; j; j = j->next) {
            if (strcmp(j->student->familyName, min->student->familyName) < 0) {
                min = j;
            }
        }
        if (min != i) {
            swap(i->student, min->student);
        }
    }
}

Node* findStudents(Node* head, int& foundCount) {
    Node* foundHead = nullptr;
    Node* foundTail = nullptr;
    foundCount = 0;

    Node* current = head;
    while (current) {
        if (current->student->id % 2 == 0) {
            Student* copiedStudent = new Student;
            copiedStudent->id = current->student->id;
            copiedStudent->familyName = new char[strlen(current->student->familyName) + 1];
            strcpy(copiedStudent->familyName, current->student->familyName);
            for (int i = 0; i < 8; ++i)
                copiedStudent->grades[i] = current->student->grades[i];
            appendStudent(foundHead, foundTail, copiedStudent);
            foundCount++;
        }
        current = current->next;
    }

    return foundHead;
}

void deleteStudents(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete[] temp->student->familyName;
        delete temp->student;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    Student* student1 = new Student{24, strdup("Mischa"), {40, 50, 60, 70, 0, 0, 0, 0}};
    Student* student2 = new Student{3, strdup("Alex"), {40, 50, 60, 70, 0, 0, 0, 0}};
    Student* student3 = new Student{36, strdup("Dohn"), {40, 50, 60, 70, 0, 0, 0, 0}};
    Student* student4 = new Student{28, strdup("Doe"), {40, 50, 60, 70, 0, 0, 0, 0}};
    Student* student5 = new Student{11, strdup("Dane"), {40, 50, 60, 70, 0, 0, 0, 0}};

    appendStudent(head, tail, student1);
    appendStudent(head, tail, student2);
    appendStudent(head, tail, student3);
    appendStudent(head, tail, student4);
    appendStudent(head, tail, student5);

    cout << "Виведення всіх елементів:\n";
    printStudents(head);

    cout << "\nВиведення сортованих елементів у алфавітному порядку:\n";
    sortStudents(head);
    printStudents(head);

    int foundCount = 0;
    Node* foundStudents = findStudents(head, foundCount);
    cout << "\nЗнайдено студентів з парним ID: " << foundCount << "\n";
    printStudents(foundStudents);

    deleteStudents(head);
    deleteStudents(foundStudents);

    return 0;
}

