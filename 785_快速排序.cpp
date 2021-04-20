/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210418
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

const int N = 1e6 + 10; 

int n; 
int arr[N]; 

void quick_sort(int *arr, int lhs, int rhs) {

    if (lhs >= rhs) return ; 

    int x = arr[ (lhs + rhs) >> 1 ]; 
    int i = lhs - 1; 
    int j = rhs + 1; 

    while (i < j) {
        do i++; while (arr[i] < x); 
        do j--; while (arr[j] > x); 
        if (i < j) swap(arr[i], arr[j]); 
    }

    quick_sort(arr, lhs, j); 
    quick_sort(arr, j + 1, rhs); 
}

int main() {

    scanf("%d", &n); 
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]); 

    quick_sort(arr, 0, n - 1); 

    for (int i = 0; i < n; ++i) printf("%d ", arr[i]); 
    printf("\n"); 

    return 0; 
}