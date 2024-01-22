#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define int long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
vector<int> number;
int keepdata[15][2][140][140];    //dp[15][2][140][140]
int calculation(int pos, bool f, int sum, int mod, int rem)
{

    if (pos == number.size())
    {
        if (sum == 0 && rem == 0)
        {
            return 1;
        }
        return 0;
    }
    if (keepdata[pos][f][sum][rem] != -1)
    {
        return keepdata[pos][f][sum][rem];
    }
    int maxdigit = number[pos];
    if (f)
        maxdigit = 9;
    int ans = 0;
    int currdis = number[pos];
    for (int i = 0; i <= maxdigit; i++)
    {
        bool nf = f;
        if (i < currdis)
            nf = true;
        if (rem - i >= 0)
            ans += calculation(pos + 1, nf, (sum * 10 + i) % mod, mod, rem - i);
    }
    return keepdata[pos][f][sum][rem] = ans;
}


void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        number.push_back((s[i] - '0'));
    }
    int ans = 0;
    for (int i = 1; i <= 9 * 14; i++)
    {
        memset(keepdata, -1, sizeof(keepdata));
        ans += max(calculation(0, false, 0, i, i), 0LL);
    }
    cout << ans << "\n";
}

int32_t main()
{
    fast

    solve();
    return 0;
}
