#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int COLUMNS = 4; 

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
    }
}

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int countElements(Node* head) {
    int count = 0;
    while (head) {
        ++count;
        head = head->next;
    }
    return count;
}

int main() {
    Node* head = nullptr;
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile.is_open()) {
        cerr << "Помилка відкриття файлу input.txt" << endl;
        return 1;
    }

    int number;
    while (inFile >> number) {
        append(head, number);
    }
    inFile.close();

    int total = countElements(head);
    int rows = (total + COLUMNS - 1) / COLUMNS;

    
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int[COLUMNS];

    
    Node* current = head;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (current) {
                matrix[i][j] = current->data;
                current = current->next;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    
    deleteList(head);

    
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < COLUMNS; ++j)
            if (matrix[i][j] < 0)
                matrix[i][j] = matrix[i][j] * matrix[i][j];

    int minDim = min(rows, COLUMNS);
    double* diagonals = new double[minDim];

    for (int i = 0; i < minDim; ++i) {
        if (matrix[i][i] < 0) {
            cerr << "Помилка: не можна обчислити корінь з від’ємного елементу на діагоналі." << endl;
            diagonals[i] = NAN;
        } else {
            diagonals[i] = sqrt(matrix[i][i]);
        }
    }

    cout << "Перетворений 2D масив:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < COLUMNS; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    cout << "\nМасив квадратних коренів з діагональних елементів:\n";
    for (int i = 0; i < minDim; ++i)
        cout << diagonals[i] << " ";
    cout << endl;

    outFile << "Перетворений 2D масив:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < COLUMNS; ++j)
            outFile << matrix[i][j] << "\t";
        outFile << endl;
    }

    outFile << "\nМасив квадратних коренів з діагональних елементів:\n";
    for (int i = 0; i < minDim; ++i)
        outFile << diagonals[i] << " ";
    outFile << endl;

    outFile.close();

    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
    delete[] diagonals;

    return 0;
}

