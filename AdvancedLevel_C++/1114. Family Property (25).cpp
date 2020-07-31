#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA {
    int id, fid, mid, num, area;
    int cid[10];//儿子
}data[1005];//输入形式
struct node {
    int id, people;
    double num, area;
    bool flag = false;//统计家庭数，检验某家庭是否存在
}ans[10000];//输出形式，一个ans[]元素是一个合并后的家
int father[10000];
bool visit[10000];//统计家庭人数
int find(int x) {
    while(x != father[x])
        x = father[x];
    return x;
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB)
        father[faA] = faB;
    else if(faA < faB)
        father[faB] = faA;//家庭用最小id来标记
}
int cmp1(node a, node b) {
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int main() {
    int n, k, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < 10000; i++)//初
        father[i] = i;
    for(int i = 0; i < n; i++) {//I
        scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
        visit[data[i].id] = true;
        if(data[i].fid != -1) {
            visit[data[i].fid] = true;
            Union(data[i].fid, data[i].id);
        }
        if(data[i].mid != -1) {
            visit[data[i].mid] = true;
            Union(data[i].mid, data[i].id);
        }
        for(int j = 0; j < k; j++) {
            scanf("%d", &data[i].cid[j]);
            visit[data[i].cid[j]] = true;
            Union(data[i].cid[j], data[i].id);
        }
        scanf("%d %d", &data[i].num, &data[i].area);
    }
    for(int i = 0; i < n; i++) {//转
        int id = find(data[i].id);
        ans[id].id = id;//输出的下标及家的根为合并后的根
        ans[id].num += data[i].num;
        ans[id].area += data[i].area;
        ans[id].flag = true;
    }
    for(int i = 0; i < 10000; i++) {//数
        if(visit[i])
            ans[find(i)].people++;
        if(ans[i].flag)
            cnt++;
    }
    for(int i = 0; i < 10000; i++) {//算
        if(ans[i].flag) {
            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }
    sort(ans, ans + 10000, cmp1);//排
    printf("%d\n", cnt);//O
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    return 0;
}
