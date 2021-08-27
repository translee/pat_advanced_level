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

vector<int> node[110];
int hashTable[110] = {0};
int n, m;

void dfs(int id, int cu_gen)
{   
    hashTable[cu_gen]++;
    for (size_t i = 0; i < node[id].size(); i++)
        dfs(node[id][i], cu_gen + 1);
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("0.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    int now, num, child;
    for (size_t i = 0; i < m; i++)
    {
        scanf("%d %d", &now, &num);
        for (size_t j = 0; j < num; j++)
        {
            scanf("%d", &child);
            node[now].push_back(child);
        }
    }

    dfs(1, 1);

    int max_gen;
    int max_num = 0;
    for (size_t i = 1; i <= n; i++)
    {
        if (hashTable[i] > max_num)
        {
            max_gen = i;
            max_num = hashTable[i];
        }
    }

    printf("%d %d", max_num, max_gen);
    
    return 0;
}
