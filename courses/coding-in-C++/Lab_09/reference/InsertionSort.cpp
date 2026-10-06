#include <iostream>
using namespace std;

int main() {

    int arr[] = {7, 4, 5, 2};
    int n = 4;

    // Ausgabe des unsortierten Arrays
    cout << "Unsortiertes Array: ";
    for (int k = 0; k < n; k++)
        cout << arr[k] << " ";
    cout << endl;

    // Insertion Sort Algorithmus
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        cout << "\nLauf " << i << ": " << key << " einsortieren" << endl;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;

            cout << "  verschieben -> ";
            for (int k = 0; k < n; k++)
                cout << arr[k] << " ";
            cout << endl;
        }

        arr[j + 1] = key;

        cout << "  einsetzen   -> ";
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }

    // Ausgabe des sortierten Arrays
    cout << "\nFertig: ";
    for (int k = 0; k < n; k++)
        cout << arr[k] << " ";
    cout << endl;

    return 0;
}
