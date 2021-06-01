#include <iostream>

using namespace std; 

const int N = 50; 
int n; 
int m;
int path[N]; 
bool st[N]; 

void dfs(int u) {

    if (u == m) {
        for (int i = 0; i < m; ++i) printf("%d ", path[i]); 
        cout << endl; 
        return ; 
    }

    for (int i = 1; i <= n; ++i) {
        if (!st[i] && (path[u - 1] < i || u == 0)) {
            path[u] = i; 
            st[i] = true; 
            dfs(u + 1); 
            st[i] = false; 
        }
    }
    return ; 
}

int main() {

    cin >> n >> m; 
    
    dfs(0); 

    return 0; 
}