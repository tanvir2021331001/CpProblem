#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define F first
#define int long long
#define S second
#define test \
  int t;     \
  cin >> t;  \
  while (t--)
#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
int trie[25000 * 26][27];
int words[500007];
int node;
vector<string> str;
vector<string> ans;
void dfs(int cur, int fl)
{ // for possible string from cur node
  if (words[cur] != -1 && fl)
  {
    ans.push_back(str[words[cur]]);
  }
  for (int i = 0; i < 26; i++)
  {
    if (trie[cur][i] != -1)
    {
      dfs(trie[cur][i], 1);
    }
  }
}
void Insert(string s, int indx)
{
  int cur = 0;
  for (int i = 0; i < s.size(); i++)
  {
    int ch = s[i] - 'a';
    if (trie[cur][ch] == -1)
    {
      trie[cur][ch] = ++node;
    }
    cur = trie[cur][ch];
  }
  str.push_back(s);
  words[cur] = indx;
}
bool Search(string s, int &cur)
{ // also update cur(node:- common prefix initial node)
  for (int i = 0; i < s.size(); i++)
  {
    int ch = s[i] - 'a';
    if (trie[cur][ch] == -1)
    {
      return false;
    }
    cur = trie[cur][ch];
  }
  return true;
}
void solve()
{
  memset(trie, -1, sizeof(trie));
  memset(words, -1, sizeof(words));

  node = 0;
  int n;
  cin >> n;
  for (int j = 0; j < n; j++)
  {
    string s;
    cin >> s;
    int cur = 0;

    Insert(s, j);
  }
  int query;
  cin >> query;
  int h = 1;
  while (query--)
  {
    cout << "Case #" << h++ << ":\n";
    string s;
    cin >> s;
    int fl = true;
    int cur = 0;
    if (!Search(s, cur))
    {
      cout << "No match.\n";
      continue;
    }

    ans.clear();
    dfs(cur, 0);
    if (ans.size() == 0)
    {
      cout << "No match\n";
    }
    else
    {
      for (int i = 0; i < ans.size(); i++)
      {
        cout << ans[i] << "\n";
      }
    }
  }
}
int32_t main()
{
  solve();
  return 0;
}
