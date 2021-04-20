/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210420
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>
#include <cstring>

using namespace std; 

const int N = 1e5 + 10; 

int n; 
int arr[N]; 

void merge_sort(int *arr, int lhs, int rhs) {

    if (lhs >= rhs) return ; 

    int mid = (lhs + rhs) >> 1; 
    merge_sort(arr, lhs, mid); 
    merge_sort(arr, mid + 1, rhs); 

    int cnt = 0; 
    int i = lhs; 
    int j = mid + 1; 

    int res[N]; 
    memset(res, 0, sizeof(res) / sizeof(int)); 
    while (i <= mid && j <= rhs) {
        if (arr[i] < arr[j]) res[cnt++] = arr[i++]; 
        else res[cnt++] = arr[j++]; 
    }
    while (i <= mid) res[cnt++] = arr[i++]; 
    while (j <= rhs) res[cnt++] = arr[j++]; 

    for (int i = lhs, j = 0; i <= rhs; ++i, ++j) arr[i] = res[j]; 

}

int main() {

    scanf("%d", &n); 
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]); 

    merge_sort(arr, 0, n - 1); 

    for (int i = 0; i < n; ++i) printf("%d ", arr[i]); 
    printf("\n"); 

    return 0; 
}