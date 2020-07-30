#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);指定长度n
    int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        temp = temp + v[i];//前i位和temp
        if (temp < 0) {
            temp = 0;
            tempindex = i + 1;//不使temp为负数的左下标
        } else if (temp > sum) {
            sum = temp;//sum最大子序列和
            leftindex = tempindex;
            rightindex = i;
        }
    }
    if (sum < 0) sum = 0;//最大子序列和非负数
    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}
