/*
 * @ Author: 李天昊
 * @ Description: n皇后问题
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

    // 判断递归停止条件
    // 输出棋盘图
    if (u == n) {
        for (int i = 0; i < n; ++i) puts(g[i]); 
        cout << endl; 
        return ; 
    }

    // 遍历第u行的各个列
    for (int i = 0; i < n; ++i) {
        // 检查是否符合放置皇后条件
        // 即列、对角、斜对角均无皇后
        if (!col[i] && !dg[i + u] && !bdg[n + i - u]) {
            // 在当前位置放置皇后
            g[u][i] = 'Q'; 
            // 标记当前位置状态
            col[i] = dg[i + u] = bdg[n + i - u] = true; 
            // 递归
            dfs(u + 1); 
            // 恢复当前位置状态
            col[i] = dg[i + u] = bdg[n + i - u] = false; 
            // 还原棋盘当前位置
            g[u][i] = '.'; 
        }
    }
    return ; 
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
