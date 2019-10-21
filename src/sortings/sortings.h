#ifndef __SORTINGS_H
#define __SORTINGS_H

#include <memory>
#include <cstring>
#include <utility>
#include <cstdlib>

using std::swap;
using std::unique_ptr;

namespace sortings {
    void merge(int * arr, int l, int mid, int r) {
        unique_ptr<int[]> l_arr(new int[mid - l + 1]);
        unique_ptr<int[]> r_arr(new int[r - mid]);

        memcpy(l_arr.get(), arr + l, sizeof(int) * (mid - l + 1));
        memcpy(r_arr.get(), arr + mid + 1, sizeof(int) * (r - mid));

        int l_ind = 0;
        int r_ind = 0;

        for (int i = l; i <= r; i++) {
            if (r_ind == r - mid || (l_ind != mid - l + 1 && l_arr[l_ind] < r_arr[r_ind])) {
                arr[i] = l_arr[l_ind++];
            } else {
                arr[i] = r_arr[r_ind++];
            }
        }
    }

    void mergesort(int * arr, int l, int r) {
        if (l == r) {
            return;
        }

        int mid = (l + r) / 2;

        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r); 
    }

    void quicksort(int * arr, int l, int r) {
        if (l >= r) {
            return;
        }

        swap(arr[l + (rand() % (r - l + 1))], arr[r]);

        int ind = l;

        for (int i = l; i <= r; i++) {
            if (arr[i] <= arr[r]) {
                swap(arr[ind], arr[i]);
                ind++;
            }
        }

        quicksort(arr, l, ind - 2);
        quicksort(arr, ind, r);
    }

    void insertion_sort(int * arr, int n) {
        for (int i = 1; i < n; i++) {
            int j = i;

            while (j > 0 && arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                j--;
            }
        }
    }

    void selection_sort(int * arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            int m_ind = i;

            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[m_ind]) {
                    m_ind = j;
                }
            }

            swap(arr[i], arr[m_ind]);
        }
    }

    void bubble_sort(int * arr, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}

#endif