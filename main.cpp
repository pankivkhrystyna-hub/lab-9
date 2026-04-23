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

//5
void show_large_stock() {
    cout << "Task 5: map filter > 100 (Lambda)\n";
    map<string, int> stock = {{"Apples", 150}, {"Bananas", 50}, {"Oranges", 200}, {"Milk", 90}};

    for_each(stock.begin(), stock.end(), [](const pair<string, int>& item) {
        if (item.second > 100) {
            cout << item.first << ": " << item.second << " | ";
        }
    });
    cout << "\n\n";
}


//6
void replace_negatives() {
    cout << "Task 6: vector replace negatives with 0 (Lambda)\n";
    vector<int> vec = {15, -3, 0, -10, 7, -1};

    // Алгоритм замінює елемент, якщо лямбда повертає true
    replace_if(vec.begin(), vec.end(), [](int n) {
        return n < 0;
    }, 0);

    for (int n : vec) cout << n << " ";
    cout << "\n\n";
}


//7
void calculate_stats() {
    cout << "Task 7: vector Sum and Average (Capturing Lambda)\n";
    vector<int> vals = {10, 20, 30, 40, 50};
    double sum = 0;

    for_each(vals.begin(), vals.end(), [&](int n) {
        sum += n;
    });

    double avg = vals.empty() ? 0 : sum / vals.size();
    cout << "Sum: " << sum << ", Average: " << avg << "\n\n";
}

//8
void count_vowels() {
    cout << "Task 8: count vowels in string (Lambda)\n";
    string text = "STL Algorithms are powerful";
    string vowels = "aeiouAEIOU";

    int count = count_if(text.begin(), text.end(), [&](char c) {
        return vowels.find(c) != string::npos;
    });

    cout << "Text: \"" << text << "\"\n";
    cout << "Vowels count: " << count << "\n";
}
int main() {
    srand(static_cast<unsigned>(time(0)));

    list_remove_if();
    array_sort();
    processing();
    how_much_elements();
    show_large_stock();
    replace_negatives();
    calculate_stats();
    count_vowels();

    return 0;
}
