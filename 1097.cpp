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

struct node
{
    int id, value, next;
    int order;
};

bool isExist[100005] = {false};

bool cmp(node a, node b)
{
    return a.order < b.order;
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("0.txt", "r", stdin);
#endif
    node nodes[100005];
    int head, n;
    scanf("%d %d\n", &head, &n);
    
    // 初始化所有order为2 * n
    for (size_t i = 0; i < 100005; i++)
        nodes[i].order = 2 * n;
    
    // 读取输入
    int address;
    for (size_t i = 0; i < n; i++)
    {
        cin >> address;
        cin >> nodes[address].value >> nodes[address].next;
        nodes[address].id = address;
    }

    // 遍历与判断,确定order
    int valid_cnt = 0, abandon_cnt = n, invalid_cnt = 2 * n;
    int p = head;
    while (p != -1)
    {
        if (isExist[abs(nodes[p].value)] == false)
        {
            nodes[p].order = valid_cnt++;
            isExist[abs(nodes[p].value)] = true;
        }
        else 
            nodes[p].order = abandon_cnt++;
        p = nodes[p].next;
    }

    // 按order排序
    sort(nodes, nodes + 100005, cmp);

    // 输出
    // 1.输出首次出现节点
    printf("%05d %d ", nodes[0].id, nodes[0].value);
    for (size_t i = 1; i < valid_cnt; i++)
        printf("%05d\n%05d %d ", nodes[i].id, nodes[i].id, nodes[i].value);
    printf("-1\n");
    // 2.输出被删除节点
    if (abandon_cnt != n)
    {
        printf("%05d %d ", nodes[valid_cnt].id, nodes[valid_cnt].value);
        for (size_t i = valid_cnt + 1; i < valid_cnt + abandon_cnt - n; i++)
            printf("%05d\n%05d %d ", nodes[i].id, nodes[i].id, nodes[i].value);
        printf("-1\n");
    }
    // 3.无效节点无需输出

    return 0;
}
