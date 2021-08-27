#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
using namespace std;

// 存放输入的三个值
int n, k, p;
// 分别存放指数列表，当前最优解，正在搜索的数据
vector<int> fac, ans, temp;
// 存放当前最大底数和
int maxFacSum = -1;

// 整数版本的指数函数，避免pow产生的误差
int my_pow(int a, int p)
{   
    int ans = 1;
    for (size_t i = 0; i < p; i++)
        ans *= a;
    return ans;
}

// 深度优先搜索
void dfs(int index, int nowK, int sum, int facSum)
{
    if (sum == n && nowK == k)
    {
        if (facSum > maxFacSum)
        {
            ans = temp;
            maxFacSum = facSum;
        }
        return;
    }
    else if (sum > n || nowK > k)
        return;
    else if (index > 0)
    {   
        temp.push_back(index);
        // “选”的分支
        dfs(index, nowK + 1, sum + fac[index], facSum + index);
        temp.pop_back();
        // “不选”的分支
        dfs(index-1, nowK, sum, facSum);
    }
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("0.txt", "r", stdin);
#endif
    
    scanf("%d%d%d", &n, &k, &p);
    
    for (size_t i = 0; i <= n; i++)
    {
        int now = my_pow(i, p);
        if (now <= n)
            fac.push_back(now);
        else 
            break;
    }

    dfs(fac.size() - 1, 0, 0, 0);

    if (maxFacSum == -1)
        printf("Impossible\n");
    else 
    {
        printf("%d = %d^%d", n, ans[0], p);
        for (size_t i = 1; i < ans.size(); i++)
            printf(" + %d^%d", ans[i], p);
    }

    return 0;
}
