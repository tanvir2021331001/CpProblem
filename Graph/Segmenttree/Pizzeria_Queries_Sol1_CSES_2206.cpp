#include <bits/stdc++.h>
using namespace std;
#define int long long
const int sz = 2e5+7;
int tree1[3 * sz], tree2[3 * sz];
int arr[sz];
void merge(int tree[], int node)
{
  int left = 2 * node, right = 2 * node + 1;
  tree[node] = min(tree[left], tree[right]);
}

void build1(int node, int st, int en)
{
  if (st >= en)
  {
    tree1[node] = arr[st] + st;
    return;
  }
  int mid = (st + en) / 2, left = 2 * node, right = 2 * node + 1;
  build1(left, st, mid);
  build1(right, mid + 1, en);
  merge(tree1, node);
}

void build2(int node, int st, int en)
{
  if (st >= en)
  {
    tree2[node] = arr[st] - st;
    return;
  }
  int mid = (st + en) / 2, left = 2 * node, right = 2 * node + 1;
  build2(left, st, mid);
  build2(right, mid + 1, en);
  merge(tree2, node);
}

void update1(int node, int st, int en, int ind, int val)
{
  if (ind < st || ind > en)
    return;
  if (ind == st && ind == en)
  {
    arr[st] = val;
    tree1[node] = val + st;
    return;
  }
  int mid = (st + en) / 2, left = 2 * node, right = 2 * node + 1;
  update1(left, st, mid, ind, val);
  update1(right, mid + 1, en, ind, val);
  merge(tree1, node);
}

void update2(int node, int st, int en, int ind, int val)
{
  if (ind < st || ind > en)
    return;
  if (ind == st && ind == en)
  {
     arr[st] = val;
    tree2[node] = val - st;
    return;
  }
  int mid = (st + en) / 2, left = 2 * node, right = 2 * node + 1;
  update2(left, st, mid, ind, val);
  update2(right, mid + 1, en, ind, val);
  merge(tree2, node);
}

int query(int tree[], int node, int st, int en, int l, int r)
{
  if (r < st || l > en)
    return 1e18;
  if (st >= l && en <= r)
  {
    return tree[node];
  }
  int mid = (st + en) / 2, left = 2 * node, right = 2 * node + 1;
  return min(query(tree, left, st, mid, l, r), query(tree, right, mid + 1, en, l, r));
}

void solve()
{
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  build1(1, 1, n);
  build2(1, 1, n);
  while (q--)
  {
    int fl;
    cin >> fl;
    if (fl == 1)
    {
      int pos, val;
      cin >> pos >> val;
      update1(1, 1, n, pos, val);
      update2(1, 1, n, pos, val);
    }
    else
    {
      int ind;
      cin >> ind;
      int q1 = query(tree1, 1, 1, n, ind, n) - ind;
      int q2 = query(tree2, 1, 1, n, 1, ind) + ind;
      cout << min(q1, q2) << "\n";
    }
  }
}
int32_t main()
{

  solve();

  return 0;
}
