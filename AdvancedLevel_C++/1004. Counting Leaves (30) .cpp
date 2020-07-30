#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100];
int book[100], maxdepth = -1;//book：每层叶子数
void dfs(int index, int depth) {
    if(v[index].size() == 0) {//如果找到一个叶子，该层叶子数加一
        book[depth]++;
        maxdepth = max(maxdepth, depth);//maxdepth：树的深度，比较每个叶子的深度得出树的深度
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)//深度递归遍历儿子
        dfs(v[index][i], depth + 1);
}
int main() {
    int n, m, k, node, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&node, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    dfs(1, 0);
    printf("%d", book[0]);
    for(int i = 1; i <= maxdepth; i++)
        printf(" %d", book[i]);
    return 0;
}
