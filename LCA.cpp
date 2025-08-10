#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define all(x) (x).begin(), (x).end()
const int N = 2e5 + 1 ,LOG = 31;
 
vector<vector<int>>anc(N ,vector<int>(LOG));
vector<int> lvl(N , 0);
 
int k_th(int a, int b)
{
    for(int i = 0 ; i < LOG ;i++)
    {
        if((b >> i) & 1)
        {
            a = anc[a][i];
        }
    }
    return a;
 
}
 
int LCA(int a, int b)
{
    if(lvl[a] > lvl[b])
    {
        swap(a,b);
    }
    b = k_th(b , lvl[b] - lvl[a]);
    
    if(a == b)
    {
        return a;
    }
    else
    {
        for(int i = LOG-1 ; i >= 0 ;--i)
        {
            if (anc[a][i] != anc[b][i])
            {
                a = anc[a][i];
                b = anc[b][i];   
            }   
        }
        return anc[a][0];
 
    }
 
    
}
int main()
{
    int n , q;
    cin >> n >> q;
    for(int i = 2 ; i <= n ;i++)
    {
      int a;
      cin >> a;
      anc[i][0] = a;
      lvl[i] = lvl [a] + 1;
    }
 
    for (int i  = 1 ; i < LOG ;i++)
    {
        for(int j = 1 ; j <= n ;j++ )
        {
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
    for(int i = 0 ; i< q ;i++)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a,b)<<'\n';
    }
 
 
}
