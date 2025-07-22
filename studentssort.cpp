#include <cstring>
#include <iostream>

using namespace std;

struct Student{
    unsigned int id;
    char* familyName;
    int grades[8];
};

void printStudent(Student &student){
    cout << "Id: " << student.id << "\tName: " << student.familyName << "\tGrades: ";
    for(int i = 0; i < 8; i++){
        cout << student.grades[i] << " ";
    }
    cout << "\n";
}

void printStudents(Student* students[], int studentAmount){
    for(int i = 0; i < studentAmount; ++i){
        printStudent(*students[i]);
    }
}

Student** sortStudents(Student* students[], int studentAmount){
    for(int i = 0; i < studentAmount-1; ++i){
        for(int j = i+1; j < studentAmount; ++j){
            if (strcmp(students[i]->familyName, students[j]->familyName) > 0) {
                Student* buffer = students[i];
                students[i] = students[j];
                students[j] = buffer;
            }
        }
    }
    return students;
}

Student** findStudents(Student* students[], int studentAmount, int& foundCount){
    Student** foundStudents = new Student*[studentAmount];
    foundCount = 0;

    for (int i = 0; i < studentAmount; ++i) {
        if (students[i]->id % 2 == 0) {
            foundStudents[foundCount++] = students[i];
        }
    }
    cout << foundCount;
    return foundStudents;
}

int main() {
    Student student1 = {24, "Mischa",  40, 50, 60, 70, 0, 0, 0, 0};
    Student student2 = {3, "Alex",  40, 50, 60, 70, 0, 0, 0, 0};
    Student student3 = {36, "Dohn",  40, 50, 60, 70, 0, 0, 0, 0};
    Student student4 = {28, "Doe",  40, 50, 60, 70, 0, 0, 0, 0};
    Student student5 = {11, "Dane",  40, 50, 60, 70, 0, 0, 0, 0};
    
    Student* students[5] = {&student1, &student2, &student3, &student4, &student5};

    cout << "Виведення всіх елементів масиву: \n";
    printStudents(students, 5);

    cout << "Виведення сортованих елементів масиву в алфавітному порядку: \n";
    printStudents(sortStudents(students, 5), 5);

    cout << "Виведення сортованих елементів масиву в алфавітному порядку: \n";
    int foundCount = 0;
    Student** foundStudents = findStudents(students, 5, foundCount);
    printStudents(foundStudents, foundCount);

    return 0;
}
