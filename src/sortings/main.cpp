#include "sortings.h"

#include <iostream>

using namespace std;
using namespace sortings;

int main() {
    int arr[] = {10, 1, 5, 2, 6, 9, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}