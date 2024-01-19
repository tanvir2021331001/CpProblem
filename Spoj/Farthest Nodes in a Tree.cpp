#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define mk make_pair
#define inf 2e18
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
int vis[30007];
void dfs(vector<pair<int, int> > v[], int node, int wt, int dis[])
{
  vis[node] = 1;
  dis[node] = wt;
  for (int i = 0; i < v[node].size(); i++)
  {
    int chn = v[node][i].first;
    int chw = v[node][i].second;
    if (vis[chn] != 1)
    {
      dfs(v, chn, wt + chw, dis);
    }
  }
}

void solve()
{
  int n;
  scanf("%d", &n);
  memset(vis, 0, sizeof(vis));
  vector<pair<int, int> > v[n + 1];
  for (int i = 1; i < n; i++)
  {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    v[x].push_back(mk(y, w));
    v[y].push_back(mk(x, w));
  }
  int dis1[n + 1], dis2[n + 1];
  dfs(v, 0, 0, dis1);
  int mx = -1e9, ind = 0;
  for (int i = 0; i < n; i++)
  {
    if (dis1[i] > mx)
    {
      mx = dis1[i];
      ind = i;
    }
  }
  memset(vis, 0, sizeof(vis));
  dfs(v, ind, 0, dis2);
  mx = -1e9;
  for (int i = 0; i < n; i++)
  {
    if (dis2[i] > mx)
    {
      mx = dis2[i];
    }
  }
  printf("%d\n", mx);
}

int32_t main()
{
   fast
  int t = 1;
  scanf("%d", &t);
  int h = t;
  while (t--)
  {
    printf("Case %d: ", h - t);
    solve();
  }
}
