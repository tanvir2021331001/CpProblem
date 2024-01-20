#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mk make_pair
#define inf 2e18
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int pre[n + 1], suf[n + 1];
  pre[0] = 1;
  for (int i = 1; i < n; i++)
  {
    pre[i] = min(pre[i - 1] + 1, a[i]);//previous posible distance
  }
  suf[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--)
  {
    suf[i] = min(suf[i + 1] + 1, a[i]);//next posible distance
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, min(pre[i], suf[i]));
  }
  cout << ans << "\n";
}

int32_t main()
{
  fast
  // int t = 1;cin >> t;	while(t--)
  solve();
}
