/*
 * @ Author: 李天昊
 * @ Description: 生成数字的全排列
 * @ Date: 20210429
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

const int N = 10; 

int n; 
int path[N]; 
bool st[N]; 

void dfs(int u) {

    // 判断递推停止条件
    // 输出排列
    if (u == n) {
        for (int i = 0; i < n; ++i) printf("%d ", path[i]); 
        cout << endl; 
        return ; 
    }

    // 遍历每一个数字
    for (int i = 1; i <= n; ++i) {
        // 检查当前遍历数字是否被使用
        if (!st[i]) {
            // 在当前路径保存当前遍历数字
            path[u] = i; 
            // 标记当前数字使用状态
            st[i] = true; 
            // 递归
            dfs(u + 1); 
            // 恢复当前数字使用状态
            st[i] = false; 
        }
    }
    return ;
}

int main() {
    cin >> n; 
    dfs(0); 
    return 0; 
}
