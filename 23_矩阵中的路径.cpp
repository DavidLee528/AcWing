#include <iostream>
#include <string>
#include <vector>

using namespace std; 

bool dfs(vector<vector<char>> &matrix, string &str, int u, int x, int y) {
    // 若矩阵中字母与字符串中字母不同，则该路径不符合要求
    if (matrix[x][y] != str[u]) return false; 
    // 若已经遍历到底，则路径符合要求
    if (u == str.size() - 1) return true; 
    // 不允许两次触及同一个矩阵位置
    char tmp = matrix[x][y]; 
    matrix[x][y] = '*'; 
    // 位移向量   上 右 下 左
    int dx[4] = {-1, 0, 1, 0};  
    int dy[4] = {0, 1, 0, -1}; 
    // 从各个起点做运动
    for (int i = 0; i < 4; ++i) {
        // 临时坐标
        int tx = x + dx[i]; 
        int ty = y + dy[i]; 
        // 判断是否超出矩阵范围
        if (tx >= 0 && tx < matrix.size() && ty >= 0 && ty < matrix[tx].size()) {
            // 递推
            if (dfs(matrix, str, u + 1, tx, ty)) return true; 
        }
    } 
    // 回溯 
    // 还原状态
    matrix[x][y] = tmp; 
    return false; 
}

bool hasPath(vector<vector<char>> &matrix, string str) {
    // 对两种不存在的情况进行判断
    if (matrix.size() == 0) return false; 
    if (matrix.size() * matrix[0].size() < str.size()) return false; 
    // 遍历矩阵中每个位置作为起点，从起点开始分析
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (dfs(matrix, str, 0, i, j)) return true; 
        }
    }
    return false; 
}

int main() {

    // 测试

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
