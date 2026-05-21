#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void zeigeVector()
{
    vector<int> zahlen = {3, 1, 5};

    cout << "vector: ";
    for (int zahl : zahlen) {
        cout << zahl << " ";
    }
    cout << "\n";
    cout << "Erklaerung: vector behaelt die Einfuegereihenfolge.\n\n";
}

void zeigeSet()
{
    set<int> zahlen = {3, 1, 5, 3};

    cout << "set: ";
    for (int zahl : zahlen) {
        cout << zahl << " ";
    }
    cout << "\n";
    cout << "Erklaerung: set sortiert automatisch und speichert keine doppelten Werte.\n\n";
}

void zeigeQueue()
{
    queue<int> warteschlange;

    warteschlange.push(3);
    warteschlange.push(1);
    warteschlange.push(5);

    cout << "queue: ";
    while (!warteschlange.empty()) {
        cout << warteschlange.front() << " ";
        warteschlange.pop();
    }
    cout << "\n";
    cout << "Erklaerung: queue arbeitet nach FIFO: First In, First Out.\n\n";
}

void zeigePriorityQueue()
{
    priority_queue<int> prioritaetsWarteschlange;

    prioritaetsWarteschlange.push(3);
    prioritaetsWarteschlange.push(1);
    prioritaetsWarteschlange.push(5);

    cout << "priority_queue: ";
    while (!prioritaetsWarteschlange.empty()) {
        cout << prioritaetsWarteschlange.top() << " ";
        prioritaetsWarteschlange.pop();
    }
    cout << "\n";
    cout << "Erklaerung: priority_queue gibt standardmaessig den groessten Wert zuerst aus.\n\n";
}

void zeigeMinHeap()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(5);

    cout << "priority_queue als Min-Heap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << "\n";
    cout << "Erklaerung: mit greater<int> kommt der kleinste Wert zuerst.\n\n";
}

int main()
{
    cout << "C++ Container Demo\n";
    cout << "==================\n\n";

    zeigeVector();
    zeigeSet();
    zeigeQueue();
    zeigePriorityQueue();
    zeigeMinHeap();

    return 0;
}