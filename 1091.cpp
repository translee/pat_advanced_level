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
    int x, y, z;
};

int m, n, l, t;
// 记录每个点的状态
int pixel[1290][130][61];
// 记录是否已经访问
bool visit[1290][130][61] = {false};

// 增量矩阵
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

// 判断是否需要访问
bool judge(int x, int y, int z)
{
    if (x >= m || x < 0 || y >= n || y < 0 || z >= l || z < 0)
        return false;
    if (visit[x][y][z] == true || pixel[x][y][z] == 0)
        return false;
    return true;
}   

// 对一个节点进行广度搜索
int bfs(int x, int y, int z)
{   
    int res = 0;
    queue<node> q;
    q.push(node{x, y, z});
    visit[x][y][z] = true;
    while (!q.empty())
    {
        node ft = q.front();
        q.pop();
        res++;
        for (size_t i = 0; i < 6; i++)
        {   
            int new_x = ft.x + X[i];
            int new_y = ft.y + Y[i];
            int new_z = ft.z + Z[i];
            if (judge(new_x, new_y, new_z))
            {
                q.push(node{new_x, new_y, new_z});
                visit[new_x][new_y][new_z] = true;
            }
        }
    }
    if (res >= t) 
        return res;
    else
        return 0;
}


int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("0.txt", "r", stdin);
#endif

    scanf("%d%d%d%d", &m, &n, &l, &t);

    // 接受输入
    for (size_t z = 0; z < l; z++)
    {
        for (size_t x = 0; x < m; x++)
        {
            for (size_t y = 0; y < n; y++)
            {
                scanf("%d", &pixel[x][y][z]);
            }
        }
    }

    int ans = 0;
    // 遍历所有节点，如果值为1，进行广度搜索，找到附近所有的1
    for (size_t z = 0; z < l; z++)
    {
        for (size_t x = 0; x < m; x++)
        {
            for (size_t y = 0; y < n; y++)
            {
                if (pixel[x][y][z] == 1 && visit[x][y][z] == false)
                    ans += bfs(x, y, z);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
