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

const int maxn = 100010;
vector<int> node[maxn];
int hashTable[maxn] = {0};
bool leaves[maxn] = {false};
int minLevel = maxn;
int cnt = 1;

void dfs(int index, int level)
{
    hashTable[level]++;
    if (leaves[index])
    {
        if (level < minLevel)
        {
            minLevel = level;
            cnt = 1;
        }
        else if (level == minLevel)
            cnt++;
    }
    for (size_t i = 0; i < node[index].size(); i++)
        dfs(node[index][i], level + 1);
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("0.txt", "r", stdin);
#endif
    int num;
    double price, r;
    scanf("%d%lf%lf", &num, &price, &r);

    int k, child;
    for (size_t i = 0; i < num; i++)
    {   
        scanf("%d", &k);
        if (k == 0)
            leaves[i] = true;
        else
        {
            for (size_t j = 0; j < k; j++)
            {
                scanf("%d", &child);
                node[i].push_back(child);
            }
        }
    }
    
    dfs(0, 0);

    printf("%.4f %d", price * pow(1 + r / 100, minLevel), cnt);
    return 0;
}
