#include <iostream>

using namespace std; 

typedef long long LL; 

int main() {

    LL t; 
    cin >> t; 

    // 不需要毫秒
    // 不需要日期
    t /= 1000; 
    t %= 86400; 

    int h = t / 3600; 
    t %= 3600; 
    int m = t / 60; 
    int s = t % 60; 

    printf("%02d:%02d:%02d", h, m, s); 

    return 0; 
}