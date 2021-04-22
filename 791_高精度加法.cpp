/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210422
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

vector<int> add(const vector<int> &lhs, const vector<int> &rhs) {

    if (lhs.size() < rhs.size()) return add(rhs, lhs); 

    vector<int> ans; 
    int tmp = 0; 
    for (int i = 0; i < lhs.size(); ++i) {
        tmp += lhs[i]; 
        if (i < rhs.size()) tmp += rhs[i]; 
        ans.push_back(tmp % 10); 
        tmp /= 10; 
    }

    if (tmp) ans.push_back(tmp); 
    reverse(ans.begin(), ans.end()); 
    
    return ans; 
}

int main() {

    string a, b; 
    cin >> a >> b; 
    
    vector<int> A; 
    vector<int> B; 
    for (int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0'); 
    for (int i = b.size() - 1; i >= 0; --i) B.push_back(b[i] - '0'); 

    vector<int> C = add(A, B); 

    for (int i = 0; i < C.size(); ++i) printf("%d", C[i]); 
    cout << endl; 

    return 0; 
}