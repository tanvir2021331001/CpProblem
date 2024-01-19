
#include <bits/stdc++.h>
using namespace std;
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define int long long

void solve()
{
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++)//input
  {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++)//prefix sum
  {
    a[i] += a[i - 1];
  }
  for (int i = 0; i < n; i++)//mod by the k(k times dristibute)
  {
    a[i] = a[i] % k;
  }
  map<int, int> mp;   
  int ans = 0;
  mp[0]++;   //counting 0 because ,every 0 should be count
  for (int i = 0; i < n; i++)
  {
    if (mp[a[i]])
    {
      ans += mp[a[i]];   // if 1 find 2 times or more there differences is 0
    }
    mp[a[i]]++;  
  }

  cout << ans << "\n";
}

int32_t main()
{
  fast
  // int t;cin>>t;while(t--)
  solve();
  return 0;
}
