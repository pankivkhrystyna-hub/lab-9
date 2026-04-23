#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

//1
bool isOdd(int n) {
    return n % 2 != 0;
}

void list_remove_if() {
    cout << "Task 1: list remove_if (Function Pointer)\n";
    list<int> l(20);
    for (int& x : l) x = rand() % 100;

    cout << "Before: ";
    for (int n : l) cout << n << " ";

    l.erase(remove_if(l.begin(), l.end(), isOdd), l.end());

    cout << "\nAfter (even only): ";
    for (int n : l) cout << n << " ";
   cout << "\n\n";
}


//2
bool compareLength(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

void array_sort() {
    cout << "Task 2: array sort by length (Function Pointer)\n";
    array<string, 5> names = {"Oleksandr", "Anna", "Dmitro", "Ian", "Max"};

    sort(names.begin(), names.end(), compareLength);

    for (const auto& name : names) {
        cout << name << " (" << name.length() << ") ";
    }
   cout << "\n\n";
}


//3
struct TaxApply {
    double rate;
    TaxApply(double r) : rate(r) {}
    void operator()(double& p) const { p *= (1.0 + rate); }
};

struct WithinRange {
    int min, max;
    WithinRange(int mi, int ma) : min(mi), max(ma) {}
    bool operator()(int n) const { return n >= min && n <= max; }
};

void processing() {
    cout << "Task 3: deque for_each "<<endl;
    deque<double> pr = {10.0, 20.0, 30.0};
    for_each(pr.begin(), pr.end(), TaxApply(0.1));
    for (double d : pr) cout << d << " ";
    cout << "\n\n";
}

//4
void how_much_elements() {
    cout << "Task 4: set count_if (Functor)\n";
    set<int> s = {10, 20, 30, 40, 50};
    cout << "In range 15-45: " <<count_if(s.begin(), s.end(), WithinRange(15, 45)) << "\n\n";
}



int main() {
    srand(static_cast<unsigned>(time(0)));

    list_remove_if();
    array_sort();
    processing();
    how_much_elements();
    return 0;
}
