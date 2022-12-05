#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <numeric>

#define fi first
#define se second
#define p_b(a) emplace_back(a)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sqr(x) (x) * (x)
#define len(b) (int)(b.size())
#define fr(i, a, b) for(int i = 0; i < (int)a; i += b)
#define en "\n"
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;
typedef long double ldd;
typedef pair <int, int> pii;
typedef vector <long long> vll;
typedef vector <long double> vldd;
typedef vector <int> vi;

const ll mod = 1e9 + 7;
const ll neutral = 0LL;
const ll INF = -2e9;

void solve()
{
    int n;
    cin >> n;
    vector <bool> a(n + 1, 0);
    int k = 0;
    fr(i, n, 1) {
        int x;
        cin >> x;
        if (!a[x]) {
            k++;
            a[x] = 1;
        }
    }

    if (k == 1) cout << 1 << en;
    else if (k == 2) cout << n / 2 + 1 << en;
    else cout << n << en;
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}