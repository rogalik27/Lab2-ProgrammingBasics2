#include <cstdint>
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
    cout << "Starting sorting\n";
    for(int i = 0; i < studentAmount-1; ++i){
        cout << "i: " << i << "\n";
        int a = 0;
        for(int j = i+1; j < studentAmount; ++j){
            cout << "j: " << j << "\n";
            cout << "i element: " << students[i]->familyName[a] << "\n";
            cout << "j element: " << students[j]->familyName[a] << "\n";
            while(students[i]->familyName[a] == students[j]->familyName[a]){
                ++a;
                cout << "Same letter!\n";
            }
            if (students[i]->familyName[a] > students[j]->familyName[a]){
                Student* temp = students[i];
                students[i] = students[j];
                students[j] = temp;
                cout << "Swapped\n";
            }
            
        printStudents(students, 5);
        }
    printStudents(students, 5);
    }
    return students;
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

    cout << "Виведення сортованих елементів масиву: \n";
    printStudents(sortStudents(students, 5), 5);

    return 0;
}
