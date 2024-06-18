//
// Created by Quan on 2024/4/15.
//
#include <iostream>
#include <vector>
using namespace std;

void merge(int* array, int left,int mid,int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int* left_array, *right_array;
    left_array = new int[n1];
    right_array = new int[n2];

    for (int i = 0; i < n1; i++) {
        left_array[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        right_array[i] = array[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 and j < n2) {
        if (left_array[i] < right_array[j]) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    if (i == n1) {
        while (j < n2) {
            array[k] = right_array[j];
            j++;
            k++;
        }
    } else if (j == n2) {
        while (i < n1) {
            array[k] = left_array[i];
            i++;
            k++;
        }
    }

    delete[] left_array;
    delete[] right_array;
}

void merge_sort(int* array, int left,int right) {
    if (right > left) {
        int mid = (left + right) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}


int main() {
    int n;
    cin >> n;

    int* array;
    array = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> array[i];
    }

    merge_sort(array, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    delete[] array;
}