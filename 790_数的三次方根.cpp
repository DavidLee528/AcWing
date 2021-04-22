/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210421
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

double cube_root(double n) {
    if (n == 0) return 0; 
    const double EPS = 1e-8; 
    double lhs = 0; 
    double rhs = n; 
    if (rhs < 0) swap(lhs, rhs); 
    if (n > -1 && n < 1) { lhs = -1; rhs = 1; }
    while (rhs - lhs > EPS) {
        double mid = (lhs + rhs) / 2; 
        if (mid * mid * mid > n) rhs = mid; 
        else lhs = mid; 
    }
    return lhs; 
}

int main() {
    double n; 
    cin >> n; 
    printf("%lf\n", cube_root(n)); 
    return 0; 
}