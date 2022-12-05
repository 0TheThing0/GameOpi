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

char mod_sys[62] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

string  sum_longArithmetician(string a, string b, int md) {

    int n = max(len(a), len(b));
    
    vi a1(n + 1);
    for(int i = a.size() - 1; i >= 0; i--) {
        if (a[i] >= 'A' && a[i] <= char('Z')) a1[a.size() - 1 - i] = int(a[i] - 'A') + 10;
        else if (a[i] >= 'a' && a[i] <= char('z')) a1[a.size() - 1 - i] = int(a[i] - 'a') + 36;
        else a1[a.size() - 1 - i] = int(a[i] - '0');
    }

    vi b1(n + 1);
    for(int i = b.size() - 1; i >= 0; i--) {
        if (b[i] >= 'A' && b[i] <= char('Z')) b1[b.size() - 1 - i] = int(b[i] - 'A') + 10;
        else if (b[i] >= 'a' && b[i] <= char('z')) b1[b.size() - 1 - i] = int(b[i] - 'a') + 36;
        else b1[b.size() - 1 - i] = int(b[i] - '0');
    }
 
    for(int i = 0; i < n; i++) {
        int x = b1[i] + a1[i];
        b1[i] = x % md;
        b1[i + 1] += x / md;
    }
 
    while(b1[n] == 0) n--;
 
    string ans = "";
    //cout << b1.size() << en;
    for(int i = n; i >= 0; i--) ans += mod_sys[b1[i]];

    return ans;
 
}
 

int main()
{
    
    string s;
    getline(cin, s);

    for(int i = 36; i <= 61; i++) {
        mod_sys[i] = char('Z' + i - 29);
    }

    vector <string> slsum;
    vector <string> srsum;

    s += '/';
    int pos = s.find('=');

    int i = 0;
    bool f = 0;
    int mx = 0;
    string str = "";
    while(i <= pos) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))) {
            if (len(str) > 0 && f) {
                srsum.push_back(str);
                str = "";
                f = 0;
            } else if (len(str) > 0) {
                slsum.push_back(str);
                str = "";
            }
        }  
        if (s[i] == '-') f = 1;
        else if (s[i] == '+') {
        } else if (s[i] != ' ' && s[i] != '=' && s[i] != '+' && s[i] != '-') {
            str += s[i];
            mx = max(mx, int(s[i]));
        }

        i++;
    }

    i = pos + 1;
    str = "";
    f = 0;
    while(i < len(s)) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))) {
            if (len(str) > 0 && f) {
                slsum.push_back(str);
                str = "";
                f = 0;
            } else if (len(str) > 0) {
                srsum.push_back(str);
                str = "";
            }
        } 

        if (s[i] == '-') f = 1;
        else if (s[i] == '+') {
        } else if (s[i] != ' ' && s[i] != '/' && s[i] != '=' && s[i] != '+' && s[i] != '-') {
            str += s[i];
            mx = max(mx, int(s[i]));
        }

        i++;
    }

    int md = 2;
    if (mx >= 'A' && mx <= 'Z') {
        md = int(mx - 'A') + 11;
    } else {
        md = int(mx - '0') + 1;
    }
    md = max(md, 2);

    string resl, resr;
    while(md <= 62) {
        resl = ""; resr = "";
        for(auto i: slsum) {
            resl = sum_longArithmetician(resl, i, md);
        }
        for(auto i: srsum) {
            resr = sum_longArithmetician(resr, i, md);
        }

        //cout << resl << ' ' << resr << ' ' << md << en;

        if (resr == resl) {
            cout << md << en;
            return 0;
        }
        
        md++;
    }

    cout << "-2" << en;
    return 0;
}