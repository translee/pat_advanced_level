#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
using namespace std;

int str_to_num(string name)
{   
    int id = (name[0] - 'A' + 1) * 100 + 
             (name[1] - 'A' + 1) * 10 +
             (name[2] - 'A' + 1);
    return id;
}

string num_to_str(int id)
{
    int id_1 = id / 100;
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("0.txt", "r", stdin);
#endif
    int n, k;
    scanf("%d %d", &n, &k);
    for (size_t i = 0; i < n; i++)
    {
        
    }
    
    return 0;
}
