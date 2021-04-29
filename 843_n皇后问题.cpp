/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210429
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

const int N = 10; 
int n; 
char g[N][N]; 
bool col[N], dg[N], bdg[N]; 

void dfs(int u) {

    if (u == n) {
        for (int i = 0; i < n; ++i) puts(g[i]); 
        cout << endl; 
        return ; 
    }

    for (int i = 0; i < n; ++i) {
        if (!col[i] && !dg[i + u] && !bdg[n + i - u]) {
            g[u][i] = 'Q'; 
            col[i] = dg[i + u] = bdg[n + i - u] = true; 
            dfs(u + 1); 
            col[i] = dg[i + u] = bdg[n + i - u] = false; 
            g[u][i] = '.'; 
        }
    }
}


int main() {

    cin >> n; 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i][j] = '.'; 
        }
    }

    dfs(0); 

    return 0; 
}