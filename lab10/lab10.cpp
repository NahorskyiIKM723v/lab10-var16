#include <iostream>
#include <string>
#include <algorithm>
#include "windows.h";
using namespace std;

const int NUM_USERS = 5;

struct LibraryUser {
    string surname;
    int yearOfBirth;
    int numOfBooks;
};

bool compareByNumOfBooks(const LibraryUser& a, const LibraryUser& b) {
    return a.numOfBooks > b.numOfBooks;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    LibraryUser users[NUM_USERS];

    cout << "Введіть інформацію про " << NUM_USERS << " у форматі 'призвище рік.народження кіл.книг':\n";
    for (int i = 0; i < NUM_USERS; ++i) {
        cin >> users[i].surname >> users[i].yearOfBirth >> users[i].numOfBooks;
    }

    sort(users, users + NUM_USERS, compareByNumOfBooks);

    cout << "\nПовна інформація про користувачів:\n";
    for (int i = 0; i < NUM_USERS; ++i) {
        cout << "Призвище: " << users[i].surname << ", Рік нарождення: " << users[i].yearOfBirth << ", Кількість книг: " << users[i].numOfBooks << endl;
    }

    cout << "\nТоп 5 людей з найбільшою кількістю книг:\n";
    for (int i = 0; i < min(5, NUM_USERS); ++i) {
        cout << "Призвище: " << users[i].surname << ", Кількість книг: " << users[i].numOfBooks << endl;
    }

    return 0;
}
