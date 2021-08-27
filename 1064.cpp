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

const int maxn = 1010;
int node[maxn] = {0};
int n;
int res[maxn] = {0};
int cnt = 0;

void inorder(int index)
{
    if (index > n) return;
    inorder(index * 2);
    res[index] = node[cnt++];
    inorder(index * 2 + 1);
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("0.txt", "r", stdin);
#endif

    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
        scanf("%d", &node[i]);
    
    sort(node, node + n);

    inorder(1);
    
    for (size_t i = 1; i <= n; i++)
        printf(" %d" + !(i - 1), res[i]);

    return 0;
}
