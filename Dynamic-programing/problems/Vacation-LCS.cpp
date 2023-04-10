/***  بسم الله الرحمن ا لرحيم   ***/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define endl                         '\n'
#define Ceil(x,y)             ((x+y-1)/y)
#define sz(s)               (int)s.size()
#define RT(x)           return cout<<x,0;
#define mem(x,y)    memset(x,y,sizeof(x))
#define all(v) ((v).begin()), ((v).end())
#define watch(x) cout<<#x<<" = { "<<x<<" }\n"
#define test int t;cin>>t;while(t--)
const int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
const double PI = acos(-1), EPS = 1e-7;
const int OO = 0x3f3f3f3f, N = 2e5 + 5, mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll x, ll y) { return (!y) ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return ((x / gcd(x, y)) * y); }


void file() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int memo[105][105];
string s, d;
int tt = 1;


int dp(int i, int j) {
	if (i == sz(s) || j== sz(d))return 0;
	int& ret = memo[i][j];
	if (~ret)return ret;

	if (s[i] == d[j])ret = max(ret, dp(i + 1, j + 1) + 1);
	ret = max(ret, dp(i , j+1));
	ret = max(ret, dp(i + 1, j));
	return ret;
}



void solve() {
    
	while (getline(cin,s)) {
	mem(memo, -1);
		if (s == "#")break;
		getline(cin, d);
		printf("Case #%d: you can visit at most %d cities.\n", tt++, dp(0, 0));
	}
}



int main() {
	file();
   // int t;cin>>t;while(t--){
	    solve();
   // }

	return 0;
}