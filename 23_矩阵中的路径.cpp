#include <iostream>
#include <string>
#include <vector>

using namespace std; 

bool dfs(vector<vector<char>> &matrix, string &str, int u, int x, int y) {
    if (matrix[x][y] != str[u]) return false; 
    if (u == str.size() - 1) return true; 
    int dx[4] = {-1, 0, 1, 0};  
    int dy[4] = {0, 1, 0, -1}; 
    char tmp = matrix[x][y]; 
    matrix[x][y] = '*'; 
    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i]; 
        int b = y + dy[i]; 
        if (a >= 0 && a < matrix.size() && b >= 0 && b < matrix[a].size()) {
            if (dfs(matrix, str, u + 1, a, b)) return true; 
        }
    } 
    matrix[x][y] = tmp; 
    return false; 
}

bool hasPath(vector<vector<char>> &matrix, string str) {
    if (matrix.size() == 0) return false; 
    if (matrix.size() * matrix[0].size() < str.size()) return false; 
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (dfs(matrix, str, 0, i, j)) return true; 
        }
    }
    return false; 
}

int main() {

    vector<vector<char>> mat = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    }; 

    string s1 = "BCCE"; 
    string s2 = "ASAE"; 

    cout << hasPath(mat, s1) << endl; 
    cout << hasPath(mat, s2) << endl; 

    return 0; 
}