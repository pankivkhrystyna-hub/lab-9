#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <string>
#include <ctime>

bool isOdd(int n) {
    return n % 2 != 0;
}

void list_remove_if() {
    std::cout << "Task 1: std::list remove_if (Function Pointer)\n";
    std::list<int> l(20);
    // Заповнення рандомними числами 0-99
    for (int& x : l) x = rand() % 100;

    std::cout << "Before: ";
    for (int n : l) std::cout << n << " ";

    // Використання вказівника на функцію isOdd
    l.erase(std::remove_if(l.begin(), l.end(), isOdd), l.end());

    std::cout << "\nAfter (even only): ";
    for (int n : l) std::cout << n << " ";
    std::cout << "\n\n";
}

bool compareLength(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

void array_sort() {
    std::cout << "Task 2: std::array sort by length (Function Pointer)\n";
    std::array<std::string, 5> names = {"Oleksandr", "Anna", "Dmitro", "Ian", "Max"};

    std::sort(names.begin(), names.end(), compareLength);

    for (const auto& name : names) {
        std::cout << name << " (" << name.length() << ") ";
    }
    std::cout << "\n\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    list_remove_if();
    array_sort();

    return 0;
}
